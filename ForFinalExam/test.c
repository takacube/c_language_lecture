#include <stdio.h>
#include <stdlib.h>

void num_arr2(char **num, int width, int height) {
    printf("%c\n", *num[0]);
    num[0][0] = 'a';
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j ++) {
        printf("%c ", num[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    char input_num[][5] = {"+++++", "+++++", "+++++", "+++++", "+++++"};
    char name[] = "AA";
    int size = sizeof(name);
    printf("name:::%c", name[2]);
    // ポインタを使用して２次元の構造にする
    int height = 5; //  the number of rows
    int width = sizeof(input_num) / sizeof(char) / height; //the number of coliumns
    char **num = malloc(width * sizeof(char *)); //全列のメモリを確保
    for (int row = 0; row < height; row++) {
        num[row] = malloc(5 * sizeof(char));
        //↑ここまででメモリ確保完了
        for (int column = 0; column < width; column++) {
            num[row][column] = input_num[row][column];
        }
    }
    // num_arr2関数の実行
    num_arr2(num, width, height);
    // メモリの解放
    for (int i = 0; i < height; i++) {
        free(num[i]); //各行のメモリを解放
    }
    free(num);
    return 0;
}