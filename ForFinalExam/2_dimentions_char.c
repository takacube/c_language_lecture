#include <stdio.h>
#include <stdlib.h>

void num_arr2(int **num, int numline, int numlen) {
    for (int i = 0; i < numline; i++) {
        for (int j = 0; j < numlen; j ++) {
        printf("%d ", num[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int input_num[][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };
    // ポインタを使用して２次元の構造にする
    int numlen = 5; //  the number of rows
    int numline = sizeof(input_num) / sizeof(int) / numlen; //the number of coliumns
    int **num = malloc(numline * sizeof(int *));
    for (int i = 0; i < numline; i++) {
        num[i] = malloc(numlen * sizeof(int));
        for (int j = 0; j < numlen; j++) {
            num[i][j] = input_num[i][j];
        }
    }
    // num_arr2関数の実行
    num_arr2(num, numline, numlen);
    // メモリの解放
    for (int i = 0; i < numline; i++) {
        free(num[i]); //各行のメモリを解放
    }
    free(num);
    return 0;
}
