#include <stdio.h>
#define MAX 10

int main() {
    int Flag=0;
    int array[MAX] = {17, 95, 59, 72, 6, 38, 11, 45, 68, 29};
    int Count=0;
    int head = 10;
    do {
        Count++;
        Flag=0;
        for(int point=1; point<head; point++){
            if(array[MAX-point-1] > array[MAX-point] ){
                int change = array[MAX-point];
                array[MAX-point] = array[MAX-point-1];
                array[MAX-point-1] = change;
                Flag=1;
            } else {
            }
        }
        head--;
        printf("%d,   ", Count);
        for(int point=0; point < MAX; point++){
            printf("%d ", array[point]);
        }
        printf("\n");
    } while(Flag);
    return 0;
}