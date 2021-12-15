#include <stdio.h>
void init(char *array){
    //insert '+' to each adress;
    for(int row=0; row<15; row++){
        for(int column=0; column<15; column++){
            *(array+15*row+column) = '+';
        }
    }
    return;
};
void dump(char array[15][15]){
    char RoxIndex[15] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
    printf("  a b c d e f g h i j k l m n o\n");
    for(int row=0; row<15; row++){
        printf("%c", RoxIndex[row]);
        for(int column=0; column<15;column++){
            printf(" %c", array[row][column]);
        }
        printf("\n");
    }
    return;
}

int main() {
    char Board[15][15];
    init(&Board[0][0]);
    dump(Board);
    return 0;
}