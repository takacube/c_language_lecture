#include <stdio.h>
#define MAX 46
int fact(int);
int main() {
    int answer;
    int acum[MAX +1] = {0, 1};
    for(int order=1; order < MAX+1; order++){
        if (order >= 2) {
            acum[order] = acum[order-1] + acum[order-2];
            printf("%d %d\n", order, acum[order]);
        }
        else {
            printf("%d %d\n", order, acum[order]);
        }
        
    }
}