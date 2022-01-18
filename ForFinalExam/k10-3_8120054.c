#include <stdio.h>
#include <stdlib.h>
void init(char **board){
    //insert '+' to each adress;
    for(int row=0; row<15; row++){
        for(int column=0; column<15; column++){
            board[row][column] = '+';
        }
    }
    return;
};
void dump(char **board){
    char RowIndex[15] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
    printf("  a b c d e f g h i j k l m n o\n");
    for(int row=0; row<15; row++){
        printf("%c", RowIndex[row]);
        for(int column=0; column<15;column++){
            printf(" %c", board[row][column]);
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

int place_stone(int turn, int row, int column, char **board) {
    if (board[row][column] == '+') {
        if(turn == 1){
            board[row][column] = 'O';
            return 0;
        } else if(turn == 0) {
            board[row][column] = '@';
            return 0;
        }
    } else {
        return 1;
    }
    return 0;
}

int free_memory(char **board, int height){
    for (int i=0; i<height; i++) {
        free(board[i]); //各行のメモリを解放
    }
    free(board);
    return 0;
}
void reset(int *length, int *distance){
    *length = 0;
    *distance = 1;
}

int judge(int row, int column, char **board) {
    char stone_type = board[row][column];
    int length = 0;
    int distance = 1;
    //下に
    while(row-distance >= 0){
        if(stone_type == board[row-distance][column]){
            length++;
            distance++;
        } else {
            break;
        }
    }
    if(length >= 4) {
        return 1;
    }
    reset(&length, &distance);
    while(row+distance < 15){
        if(stone_type == board[row+distance][column]){
            length++;
            distance++;
        } else {
            break;
        }
    }
    if(length >= 4) {
        return 1;
    }
    reset(&length, &distance);
    while(column+distance < 15){
        if(stone_type == board[row][column+distance]){
            length++;
            distance++;
        } else {
            break;
        }
    }
    if(length >= 4) {
        return 1;
    }
    reset(&length, &distance);
    while(row+distance < 15){
        if(stone_type == board[row][column-distance]){
            length++;
            distance++;
        } else {
            break;
        }
    }
    if(length >= 4) {
        return 1;
    }
    reset(&length, &distance);
    while(row+distance < 15 && column+distance < 15 ){
        if(stone_type == board[row+distance][column+distance]){
            length++;
            distance++;
        } else {
            break;
        }
    }
    if(length >= 4) {
        return 1;
    }
    reset(&length, &distance);
    while(row+distance < 15 && column-distance  >= 0 ){
        if(stone_type == board[row+distance][column-distance]){
            length++;
            distance++;
        } else {
            break;
        }
    }
    if(length >= 4) {
        return 1;
    }

    reset(&length, &distance);
    while(row-distance >= 0 && column-distance >= 0 ){
        if(stone_type == board[row-distance][column-distance]){
            length++;
            distance++;
        } else {
            break;
        }
    }
    if(length >= 4) {
        return 1;
    }

    reset(&length, &distance);
    while(row-distance >= 0 && column+distance < 15 ){
        if(stone_type == board[row-distance][column+distance]){
            length++;
            distance++;
        } else {
            break;
        }
    }
    if(length >= 4) {
        return 1;
    }
    return 0;
}
int main() {
    char Board[15][15];
    // ポインタを使用して２次元の構造にする
    int height = 15; //  the number of rows
    int width = sizeof(Board) / sizeof(char) / height; //the number of columns
    char **board = malloc(width * sizeof(char *)); //全列のメモリを確保
    for (int row = 0; row < height; row++) {
        board[row] = malloc(15 * sizeof(char));
        //↑ここまででメモリ確保完了
        for (int column = 0; column < width; column++) {
            board[row][column] = Board[row][column];
        }
    }
    init(board);
    dump(board);
    int Input, Place, Turn = 0, Row, Column;
    while(1) { 
        int is_on_the_table = input_stone(Turn, &Row, &Column);
        if ( is_on_the_table == 0 ) {
            int is_empty = place_stone(Turn, Row, Column, board); //input_stoneでRowとColumnの値は変更されている。
            if (is_empty == 0) {
                dump(board);
                int judgement = judge(Row, Column, board);
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
    free_memory(board, height);
}