#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double count_in(spreaded_num) {
    int counted_num;
    int in_circle = 0;
    for(counted_num=1; counted_num<=spreaded_num; counted_num++) {
        double x = (double)rand()/RAND_MAX; //rand()は乱数生成(double)でfloat型に
        double y = (double)rand()/RAND_MAX; //RAND_MAX=2147483647 rand()で生成される最大値
        if ((x*x+y*y)<1) {
            in_circle++;
        } else {
        }
    }
    return ((double)in_circle/spreaded_num)*4;
}

int main() {
    int num;
    for(num=10; num<100000000; num *= 10) {
        double in_circle = count_in(num);
        printf("%f : %f\n", in_circle, fabs(in_circle-M_PI)); //fabsf関数でfloat型の絶対値を計算する
    }
    printf("%f", (double)rand());
}