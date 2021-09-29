#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
double spread_num(times) {
    int count;
    int count_in = 0;
    srand((unsigned int)time(NULL));
    for(count=1;count<=times;count++) {
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        if (y<=sqrt(x))
            count_in++;
    }
    return (double)count_in/times;
}

int main(void) {
    double v_10000000 = spread_num(10000000);
    printf("%f\n", v_10000000);
}
