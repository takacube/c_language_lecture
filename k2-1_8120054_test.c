#include <stdio.h>
#define N 100000

int main() {
    for (int start_from=2; start_from < N; start_from++) {
        int count = 0;
        for(int divide_number = 1; divide_number <= start_from; divide_number++) {
            if(start_from % divide_number == 0) {
                count++;    
            }   
        }
        if(count == 2) {
                    printf("%d\n", start_from);
        } 
    }
}