#include <stdio.h>
#define MAX 15

int main() {
    FILE *file;
    int array[MAX];
    file = fopen("test.txt", "r");
    if(file == NULL) {
        printf("The file cannot be opened! \n");
        return -1;
    } else {
        for(int i=0; i<MAX; i++){
            fscanf(file, "%d", &array[i]);
        }
    }
    fclose(file);
    int Flag=0;
    int Count=0;
    int head=15;
    do {
        Count++;
        Flag=0;
        for(int point=1; point<head; point++){
            if(array[MAX-point-1] < array[MAX-point] ){
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