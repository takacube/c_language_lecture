#include <stdio.h>
#define MAX 15

int main() {
    FILE *file;
    int i_1, i_2, i_3, i_4, i_5, i_6, i_7, i_8, i_9, i_10, i_11, i_12, i_13, i_14, i_15;
    file = fopen("test.txt", "r");
    if(file == NULL) {
        printf("The file cannot be opened! \n");
        return -1;
    } else {
        fscanf(file, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &i_1, &i_2, &i_3, &i_4, &i_5, &i_6, &i_7, &i_8, &i_9, &i_10, &i_11, &i_12, &i_13, &i_14, &i_15);
    }
    fclose(file);
    int Flag=0;
    int array[MAX] = {i_1, i_2, i_3, i_4, i_5, i_6, i_7, i_8, i_9, i_10, i_11, i_12, i_13, i_14, i_15};
    int Count=0;
    int head = 15;
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