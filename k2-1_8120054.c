#include <stdio.h>
#define N 100000
//0~10000の中の素数を見つける
int show_num(subject_num) {
    printf("%d\n", subject_num);
    return 0;
}
int judge_if_prime(subject_num, count){
    if (count == 2){
        show_num(subject_num);
    }
    return 0;
}
int main(){
    int subject_num, num_to_div;
    int count=0;
    int prime_is;
    //in main function filter prime and just prime sumber whould make count 2 and make others more than 2;
    for (subject_num=2; subject_num<=N; subject_num++) {
        for (num_to_div=1; num_to_div<=subject_num; num_to_div++) {
            if (subject_num%num_to_div == 0) {
                count++;
            }
        }
        judge_if_prime(subject_num, count);
        count = 0;
    }
    return 0;
}

//0~10000の中の素数を見つける.
//まず0, 1は素数出ない。
//素数であるかどうかを2から順番に10000まで一つ一つ試していく。
//試し方としてはその対象の数を 1からその数まで順番に割っていく。
//like this. 3/1 3/2 3/3 この場合3は素数である(1とその数(3)でしか割り切れない
//よってif (subject_num%num_to_div == 0) {
//                count++;
//            }
//このcount は2回だけ＋されるからcount は2を返す。　
//２を返したということは1とその数でしか割れなかったということを示しているから 素数であると判断できる。
