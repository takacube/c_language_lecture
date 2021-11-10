#include <stdio.h>
#include <stdlib.h>
#define MAXT 100
#define ROW 40
#define COLUMN 40
int cell[ROW+2][COLUMN+2] = {0};
void init() {
    for(int col=15; col<25; col++) {
        cell[ROW/2][col] = 1;
    }
}
void dump() {
    for(int col=1; col<=COLUMN; col++) {
        for (int row=1; row<=ROW; row++){
            if(cell[row][col] == 0) {
                printf(".");
            }
            else if(cell[row][col] == 1) {
                printf("@");
            }  
        }
        printf("\n");
    }
}
void update() {
    int next_cell[ROW+2][COLUMN+2] = {0};
    for(int col=1; col<=COLUMN; col++) {
        for (int row=1; row<=ROW; row++){
            int cell_num = 0;

            if(cell[row][col] == 0) {
                for(int around_cell_col=-1; around_cell_col<=1; around_cell_col++){
                    for(int around_cell_row=-1; around_cell_row<=1; around_cell_row++){
                        if(cell[row+around_cell_row][col+around_cell_col]==1) {
                            cell_num++;
                        }
                    }
                }
                if(cell_num == 3) {
                    next_cell[row][col] = 1;
                }
                else {
                    next_cell[row][col] = 0;
                }
            }

            else if(cell[row][col] == 1) {
                for(int around_cell_col=-1; around_cell_col<=1; around_cell_col++){
                    for(int around_cell_row=-1; around_cell_row<=1; around_cell_row++){
                        if(cell[row+around_cell_row][col+around_cell_col]==1) {
                            cell_num++;
                        }
                    }
                }
                cell_num--; //this includes the number i specify as aswll
                if(2<=cell_num && cell_num<=3) {
                    next_cell[row][col] = 1;
                }
                else {
                    next_cell[row][col] = 0;
                }
            }  
        }
    }
    for(int col=1; col<=COLUMN; col++) {
        for (int row=1; row<=ROW; row++){
            cell[row][col] = next_cell[row][col];
        }
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
        system("clear");
        dump();
        system("sleep 0.1s"); 
    }
}