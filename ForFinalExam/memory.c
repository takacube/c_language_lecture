#include <stdio.h>

int main(){
    char name[3][3] = {"+++", "+++", "+++"};
    int seiseki[][3] = {{72, 67, 84}, {67, 92, 71}};
    printf("%c\n", name[0][1]);
    int size = sizeof(name[3][0]);
    for(int row=0; row<3; row++){
        for(int column=0; column<3; column++){
            printf("%c", name[row][column]);
        }
        printf("\n");
    }
    printf("size iof character: %d", size);
}