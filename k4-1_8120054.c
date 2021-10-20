#include <stdio.h>
int is_fizz(int);
int is_buzz(int);
int main() {
    int num;
    printf("Input number: ");
    scanf("%d", &num);
    for(int point=1; point<=num; point++){
        int res_fizz = is_fizz(point);
        int res_buzz = is_buzz(point);
        if (res_fizz == 0 && res_buzz==0){
            printf("Fizz Buzz\n");
        } else if (res_buzz == 0){
            printf("Buzz\n");
        } else if (res_fizz == 0){
            printf("Fizz\n");
        } else {
            printf("%d\n", point);
        }
    }
}

int is_fizz(point){
    if(point%3==0){
        return 0;
    } else {
        return 1;
    }
}
int is_buzz(point){
    if(point%5==0){
        return 0;
    } else {
        return 1;
    }
}