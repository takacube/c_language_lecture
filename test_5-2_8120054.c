#include <stdio.h>
#define MAX 46
int sequence(int);

int main() {
    int answer;
    for(int start_from=1; start_from < MAX+1; start_from++){
        answer = sequence(start_from);
        printf("%d %d\n", start_from, answer);
    }
}

int sequence(num){
    static int memo[MAX+1] = {0,1};
    if(num == 0 || num == 1) return memo[num];
    if(memo[num] != 0) {
        return memo[num];
    } else {
        memo[num] = sequence(num-1) + sequence(num-2);
        return memo[num];
    }
}