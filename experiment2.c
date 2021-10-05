#include "rpi_lib/rpi.h"
#define GPFSELO 0x20200000
#define GPFSEL1 0x20200004
#define GPFSEL2 0x20200008
#define GPSETO 0x2020001C
#define GPCLRO 0x202000028
#define SYST_CLO 0x20003004
#define SYST_CHI 0x20003008

volatile unsigned long long get_systime(void){
    unsigned long long t; unsigned int chi; unsigned int clo;
    chi = *(volatile unsigned int *)SYST_CHI;
    clo = *(volatile unsigned int *)SYST_CLO;

    if(chi != *(volatile unsigned int *)SYST_CHI) {
        chi = *(volatile unsigned int *)SYST_CHI;
        clo = *(volatile unsigned int *)SYST_CLO;
    }
        t = chi;
        t = t << 32;
        t += clo;
        return t;
}

void_delay_ms(unsigned int delay) {
    unsigned long long alermTime;
    alermTime = get_systime() + delay * 1000;
    while(get_systime() < alermTime);
    return;
}

int main(void) {
    rpi_init();

    *(volatile unsigned int *)SYST_CHI = 0;
    *(volatile unsigned int *)SYST_CLO = 0;

    *(volatile unsigned int *)GPFSELO |= 0x01 << (3*7);
    *(volatile unsigned int *)GPFSELO |= 0x01 << (3*8);

    while(1) {
        *(volatile unsigned int *)GPCLRO |= 0x01 << 7;
        *(volatile unsigned int *)GPSETO |= 0x01 << 8;

        delay_ms(500);

        *(volatile unsigned int *)GPSETO |= 0x01 << 7;
        *(volatile unsigned int *)GPCLRO |= 0x01 << 8;

        delay_ms(500); 
    }
    return 0;
}