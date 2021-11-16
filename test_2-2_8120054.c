#include <stdio.h>
#define N 100000

int main() {
    int subject;
    int flag[N+1] = {0};
    int subject_times;

    for(subject=2; subject<=100000; subject++) {
        if(flag[subject] == 0) {
            for(subject_times = subject*2; subject_times <= N; subject_times+=subject){
                if(subject_times % subject == 0) {
                    flag[subject_times] = 1;
                }
            }
        }
    }
    for(subject_times=2; subject_times<=N; subject_times++){
        if(flag[subject_times] == 0 ){
            printf("%d\n", subject_times);
        }
    }
}