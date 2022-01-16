#include <stdio.h>
#include <stdlib.h>
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

int input_stone(int Turn, int *pRow, int *pColumn) {
    char input[4];
    if ( Turn == 0 ) printf("sente(@)>"); // Turn が０ => 先手
    if ( Turn == 1 ) printf("gote(O)>"); // Turn が 1 => 後手
    fgets(input,4,stdin);
    if(input[0]>='A' && input[0]<='O'){
        int tmp = input[0] - 65;
        *pRow = tmp;
    } else {
        return 1;
    }
    if (input[1]>='a' && input[1]<='o'){
        int tmp = input[1] - 97;
        *pColumn = tmp;
        return 0;
    } else {
        printf("error has occured");
        return 1;
    }
}

int place_stone(int turn, int row, int column, char *board) {
    if (*(board+15*row+column) == '+') {
        if(turn == 1){
            *(board+15*row+column) = 'O';
            //printf("%s", board[row][column]);
            return 0;
        } else if(turn == 0) {
            *(board+15*row+column) = '@';
            //printf("%s", board[row][column]);
            return 0;
        }
    } else {
        return 1;
    }
    return 0;
}

int judge(int row, int column, char *board) {
    char c = *(board+15*row+column);
    int LineLen = 0;
    int i;
    i = 1;
    while(row-i >= 0){
        if(c == *(board+15*(row-i)+column)){
            LineLen++;
            i++;
        } else {
            break;
        }
    }
    if(LineLen >= 4) {
        return 1;
    }
    LineLen = 0;
    i = 1;
    while(row+i <= 15){
        if(c == *(board+15*(row+i)+column)){
            LineLen++;
            i++;
        } else {
            break;
        }
    }
    if(LineLen >= 4) {
        return 1;
    }
    LineLen = 0;
    i = 1;
    while(column+i <= 15){
        if(c == *(board+15*row+column+i)){
            LineLen++;
            i++;
        } else {
            break;
        }
    }
    if(LineLen >= 4) {
        return 1;
    }
    LineLen = 0;
    i = 1;
    while(row+i <= 15){
        if(c == *(board+15*row+column-i)){
            LineLen++;
            i++;
        } else {
            break;
        }
    }
    if(LineLen >= 4) {
        return 1;
    }
    LineLen = 0;
    i = 1;
    while(row+i <= 15 && column+i <= 15 ){
        if(c == *(board+15*(row+i)+column+i)){
            LineLen++;
            i++;
        } else {
            break;
        }
    }
    if(LineLen >= 4) {
        return 1;
    }
    LineLen = 0;
    i = 1;
    while(row+i <= 15 && column-i <= 15 ){
        if(c == *(board+15*(row+i)+column-i)){
            LineLen++;
            i++;
        } else {
            break;
        }
    }
    if(LineLen >= 4) {
        return 1;
    }

    LineLen = 0;
    i = 1;
    while(row-i <= 15 && column-i <= 15 ){
        if(c == *(board+15*(row-i)+column-i)){
            LineLen++;
            i++;
        } else {
            break;
        }
    }
    if(LineLen >= 4) {
        return 1;
    }

    LineLen = 0;
    i = 1;
    while(row-i <= 15 && column+i <= 15 ){
        if(c == *(board+15*(row-i)+column+i)){
            LineLen++;
            i++;
        } else {
            break;
        }
    }
    if(LineLen >= 4) {
        return 1;
    }
    return 0;
}

int main() {
    int Input, Place, Turn = 0, Row, Column;
    char Board[15][15];
    init(&Board[0][0]);
    dump(Board);
    while(1) { 
        int Input = input_stone(Turn, &Row, &Column);
        if ( Input == 0 ) {
            int Place = place_stone(Turn, Row, Column, &Board[0][0]);
            if (Place == 0) {
                dump(Board);
                int judgement = judge(Row, Column, &Board[0][0]);
                if(judgement == 1 && Turn == 0){
                    printf(">Winner: sente(@)");
                    return 0;
                } else if (judgement == 1 && Turn == 1) {
                    printf("Winner: gote(O)");
                    return 0;
                } else {}

                if(Turn == 0){
                    Turn = 1;
                } else {
                    Turn = 0;
                }
            } else {
                printf("you can't put on the stone\n");
            }
        } else {
            printf("You have to put on the table\n");
        }
    }
}
