#include <stdio.h>
int is_fizz(int);
int is_buzz(int);

int main() {
    int subject;
    printf("Input the numebr: ");
    scanf("%d", &subject);
    for(int from = 1; from <= subject; from++){
        int is_fizz_ = is_fizz(from);
        int is_buzz_ = is_buzz(from);
        if( is_fizz_ == 0 && is_buzz_ == 0) {
            printf("Fizz Buzz\n");
        } else if (is_fizz_ == 0) {
            printf("Fizz\n");
        } else if (is_buzz_ == 0) {
            printf("Buzz\n");
        }
        else {
            printf("%d\n", from);
        }
    }
}

int is_fizz(num) {
    int is_fizz_ = 1;
    while(num > 1){
        if(num % 10 == 3 || num % 3 == 0){
            is_fizz_ = 0;
        } else {
        }
        num /= 10;
    }
    return is_fizz_;
}

int is_buzz(num) {
    if(num%5==0){
        return 0;
    } else {
        return 1;
    }
}