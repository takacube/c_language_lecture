#include <stdio.h>
#define MAX 46
int ex_sequence(int);
int main() {
    int answer;
    for(int order=1; order < MAX+1; order++){
        answer = ex_sequence(order);
        printf("%d %d\n", order, answer);
    }
}

int ex_sequence(num){
    int sub_answer;
    if(num == 0 || num == 1) return num;
    sub_answer = ex_sequence(num-1)+ex_sequence(num-2);
    return sub_answer;
}