
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double spread_num(times) {
    int count;
    int count_in = 0;
    srand((unsigned int)time(NULL));
    for(count=1;count<=times;count++) {
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        if ((x*x + y*y)<1)
            count_in++;
    }
    return (double)count_in/times*4;
}

int main(void) {
    double v_10 = spread_num(10);
    printf("%f\n", v_10);
    double v_100 = spread_num(100);
    printf("%f\n", v_100);
    double v_1000 = spread_num(1000);
    printf("%f\n", v_1000);
    double v_10000 = spread_num(10000);
    printf("%f\n", v_10000);
    double v_100000 = spread_num(100000);
    printf("%f\n", v_100000);
    double v_1000000 = spread_num(1000000);
    printf("%f\n", v_1000000);
    double v_10000000 = spread_num(10000000);
    printf("%f\n", v_10000000);
}
