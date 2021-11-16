#include <stdio.h>
#define MAXT 46
int sequence(int);

int main() {
    int answer;
    for(int start_from = 1; start_from <= MAXT; start_from++){
        answer = sequence(start_from);
        printf("%d %d\n", start_from, answer);
    }
}

int sequence(num) {
    if(num == 0 || num == 1) return num;
    int answer = sequence(num-1)+sequence(num-2);
    return answer;
}