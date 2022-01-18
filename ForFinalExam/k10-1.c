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
    char RoxIndex[15] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
    printf("  a b c d e f g h i j k l m n o\n");
    for(int row=0; row<15; row++){
        printf("%c", RoxIndex[row]);
        for(int column=0; column<15;column++){
            printf(" %c", board[row][column]);
        }
        printf("\n");
    }
    return;
}

int free_memory(char **board, int height){
    for (int i=0; i<height; i++) {
        free(board[i]); //各行のメモリを解放
    }
    free(board);
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
    // メモリの解放
    free_memory(board, height);
    return 0;
}