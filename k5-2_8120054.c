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
    static int memo[MAX+1] = {0, 1};
    //initial number that you don't have to calcurate
    if(num == 0 || num == 1) return num;
    //If you already calcurate before
    if(memo[num] != 0){
        return memo[num];
    } else {
        memo[num] = ex_sequence(num-1)+ex_sequence(num-2);
        return memo[num];
    }
    
}