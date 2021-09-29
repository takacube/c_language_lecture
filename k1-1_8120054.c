
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double spread_num(times) {
    int count;
    int count_in = 0;
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
    printf("%f : %f\n", v_10, fabs(v_10-M_PI));
    double v_100 = spread_num(100);
    printf("%f : %f\n", v_100, fabs(v_100-M_PI));
    double v_1000 = spread_num(1000);
    printf("%f : %f\n", v_1000, fabs(v_1000-M_PI));
    double v_10000 = spread_num(10000);
    printf("%f : %f\n", v_10000, fabs(v_10000-M_PI));
    double v_100000 = spread_num(100000);
    printf("%f : %f\n", v_100000, fabs(v_100000-M_PI));
    double v_1000000 = spread_num(1000000);
    printf("%f : %f\n", v_1000000, fabs(v_1000000-M_PI));
    double v_10000000 = spread_num(10000000);
    printf("%f : %f\n", v_10000000, fabs(v_10000000-M_PI));
}
