#include <stdio.h>
int main(){
    int size = sizeof(int *);
    printf("seize of int %d\n", size);

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

    int numlen = 5;
    int numline = sizeof(input_num) / sizeof(int) / numlen;
    printf("input_num: %lu\n", sizeof(input_num));
    printf("numline: %d\n", numline); 
}