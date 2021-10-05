#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<stdint.h>
//BCM2835 on Raspberry pi
#define GPIO_REGS 0x20200000 

static volatile uint32_t * gpio_regs;

int gpio_open() {
    int fd; void * map;
    if((fd=open("/dev/mem", O_RDWR 
    | O_SYNC))< 0) {
        printf("can't open. %s \n", strerror(errno));
        return -1;
    }
    map = mmap(0, getpagesize(), PROT_READ
        |PROT_WRITE,MAP_SHARED, fd, GPIO_REGS);
    if (map == MAP_FAILED) {
        printf("can't mapping.%s\n", strerror(errno));
        return -1;
    }
    close(fd);
    gpio_regs = (volatile uint32_t *)map;
    return 0;
}

int main(int argc, char**argv) {
    int i; int portnum = 7;
    if( gpio_open() != 0 ){
        printf("error:stopped\n");
        return -1;
    }
    i = portnum/10;
        *(gpio_regs + i)=(*(gpio_regs + i) & ~(0x7 << ((portnum%10)*3))) | (0x1 << ((portnum%10)*3));
    while(1){
        *(gpio_regs + 0x7) = (0x1 << portnum);
        sleep(1);
        *(gpio_regs + 0x0A) = (0x1 << portnum);
        sleep(1);
    }
}