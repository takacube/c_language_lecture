#include <stdio.h>
#define N 100000
int show(subject){
    printf("%d\n", subject);
    return 0;
}


int main() {
    int subject, to_divide;
    int count=0;
    for (subject=2; subject<=N; subject++) {
        for (to_divide=1; to_divide<=subject; to_divide++) {
            if(subject%to_divide == 0){
                count++;
            }
        }
        if (count==2) {
            show(subject);
        }
        count = 0;
    }
    
}