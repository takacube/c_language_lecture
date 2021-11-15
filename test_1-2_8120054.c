#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double count_in(all_num) {
    int count;
    int in_diagram = 0;
    for(count=0; count<=all_num; count++) {
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        if (y<=sqrt(x)) {
            in_diagram++;
        }
        else {}
    }
    return (double)in_diagram/all_num; //図形の中に入ってる点の数/全部の粒の数
}

int main() {
    double answer = count_in(10000000);
    printf("%f\n", answer);
}