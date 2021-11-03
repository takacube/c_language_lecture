#include <stdio.h>
#include <stdlib.h>
#define MAXT 7
#define N 31

int cell[N] = {0};

void init() {
    cell[N/2] = 1;
}

void dump() {
    for(int order=0; order<=N-1; order++){
        if (cell[order] == 0) {
            printf(".");
        }
        else {
            printf("@");
        }
    }
    printf("\n");
}

void update() {
    int next_array[N] = {0};
    for(int order=1; order<=N-2; order++){
        if (cell[order-1] == 0 && cell[order] ==0 && cell[order+1] ==0) {
            next_array[order] = 0;
        }
        else if (cell[order-1] == 0 && cell[order] ==0 && cell[order+1] ==1) {
            next_array[order] = 1; 
        }
        else if (cell[order-1] == 0 && cell[order] == 1 && cell[order+1] == 0) {
            next_array[order] = 0;
        }
        else if(cell[order-1] == 0 && cell[order] == 1 && cell[order+1] == 1) {
            next_array[order] = 1;
        }
        else if(cell[order-1] == 1 && cell[order] == 0 && cell[order+1] == 0) {
            next_array[order] = 1;
        }
        else if(cell[order-1] == 1 && cell[order] == 0 && cell[order+1] == 1) {
            next_array[order] = 0;
        }
        else if(cell[order-1] == 1 && cell[order] == 1 && cell[order+1] == 0) {
            next_array[order] = 1;
        }
        else if(cell[order-1] == 1 && cell[order] == 1 && cell[order+1] == 1) {
            next_array[order] = 0;
        }
    }
    for(int order=0; order<=N-1; order++) {
        cell[order] = next_array[order];
    }
}

int main() {
    int t;
    system("clear");
    init();
    dump();
    system("sleep 0.1s");
    for(t=1; t<=MAXT; t++) {
        update();
        dump();
        system("sleep 0.1s");
    }
}