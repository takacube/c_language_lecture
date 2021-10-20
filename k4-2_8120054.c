#include <stdio.h>
int is_fizz(int);
int is_buzz(int);
int include_3(int);
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
    if(point%3==0 || include_3(point) == 0){
        return 0;
    } else {
        return 1;
    }
}

int include_3(point){
    int does_include = 1;
    int devide_by = 10;
    while(point>0){
        if(point%devide_by == 3){
            does_include = 0;
        }
        else {
        }
        point /= 10;
    }
    if(does_include == 0){
        return 0;
    }
    else {
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