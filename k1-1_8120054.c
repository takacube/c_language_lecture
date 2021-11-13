
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double spread_num(times) {
    int count;
    int count_in = 0;
    for(count=1;count<=times;count++) {
        double x = (double)rand()/RAND_MAX; //RAND_MAX is automatucally defined by stdlib.h library as maximum number which rand() make.
        double y = (double)rand()/RAND_MAX;
        if ((x*x + y*y)<1)
            count_in++;
    }
    return ((double)count_in/times)*4; // π/4 = Nin/Nin
}

int main(void) {
    int i;
    for(i=10; i < 100000000; i = i * 10) {
        double num = spread_num(i);
        printf("%f : %f\n", num, fabs(num-M_PI));
    }
}
