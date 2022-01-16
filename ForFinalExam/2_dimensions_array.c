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
        { 32, 4, 78, 34, 64 }, 
        { 74, 5, 66, 36, 42 }, 
        { 56, 13, 55, 3, 81 }, 
        { 7, 56, 33, 83, 4 }, 
        { 32, 85, 50, 24, 39 }, 
        { 16, 24, 56, 43, 6 }, 
        { 75, 35, 27, 34, 83 }, 
        { 69, 41, 62, 2, 88 }
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
  printf("num: %d\n", num[1][1]);
  num_arr2(num, numline, numlen);

  // メモリの解放
    for (int i = 0; i < numline; i++) {
        free(num[i]); //各行のメモリを解放
    }
    free(num);

  return 0;
}
