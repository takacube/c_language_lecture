#include <stdio.h>
#define N 100000

int main() {
    int subject_num;
    int flag[N+1] = {0}; //N+1分だけ0を入れる。
    int comper_num;
    //start from 2 coz if you include 1 all number would be changed
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

//2~Nの整数の小さい方から順番にその数の倍数を取り除いていく
//2から始めたら、2の倍数でN以下の整数は全部消える。(0を１に入れ替え)
//次に3の倍数でN以下の整数は全部消える。
//次は4だが2の倍数でもうすでに消されているから次に飛んで５の倍数を消す。
