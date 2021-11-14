#include <stdio.h>
#define MAX 46
int main() {
    int answer;
    int acum[MAX +1] = {0, 1};
    for(int order=1; order < MAX+1; order++){
        if (order == 1) {
            printf("%d %d\n", order, acum[order]);
        }
        else {
            acum[order] = acum[order-1] + acum[order-2];
            printf("%d %d\n", order, acum[order]);
        }
    }
}