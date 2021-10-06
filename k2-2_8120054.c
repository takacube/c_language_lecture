#include <stdio.h>
#define N 100000

int main() {
    int subject_num;
    int flag[N+1] = {0};
    int comper_num;
    for (subject_num=2; subject_num<=N; subject_num++){
        if (flag[subject_num] == 0) {
            for(comper_num = subject_num+subject_num; comper_num<=N; comper_num+=subject_num){
                if(comper_num % subject_num == 0){
                    flag[comper_num] = 1;
                }
            }
        }  
    }
    for (subject_num=2; subject_num<=N; subject_num++){
        if (flag[subject_num] == 0) {
            printf("%d\n", subject_num);
        }
    }
    return 0;
}