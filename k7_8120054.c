#include <stdio.h>
#include <stdlib.h>
#define MAXT 100
#define ROW 40
#define COLUMN 40
int cell[ROW+2][COLUMN+2] = {0};
//set initial setting which is center part is filled with 1 instead of 0;
void init() {
    for(int col=15; col<25; col++) {
        cell[ROW/2][col] = 1;
    }
}
// show with . and @ in terminal screen 
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
    //initiate the new {}
    int next_cell[ROW+2][COLUMN+2] = {0};
    for(int col=1; col<=COLUMN; col++) {
        for (int row=1; row<=ROW; row++){
            int alive_cell = 0;
            //if the own cell is dead already
            if(cell[row][col] == 0) {
                //周りのセルを見て、生きているセルを数える。
                for(int around_cell_col=-1; around_cell_col<=1; around_cell_col++){
                    for(int around_cell_row=-1; around_cell_row<=1; around_cell_row++){
                        if(cell[row+around_cell_row][col+around_cell_col]==1) {
                            alive_cell++;
                        }
                    }
                }
                // revive
                if(alive_cell == 3) {
                    next_cell[row][col] = 1;
                }
                //keep being dead
                else {
                    next_cell[row][col] = 0;
                }
            }
            //if the own cell is alive
            else if(cell[row][col] == 1) {
                for(int around_cell_col=-1; around_cell_col<=1; around_cell_col++){
                    for(int around_cell_row=-1; around_cell_row<=1; around_cell_row++){
                        if(cell[row+around_cell_row][col+around_cell_col]==1) {
                            alive_cell++;
                        }
                    }
                }
                alive_cell--; //this includes the number i specify as aswll so I have to remove it
                //keep aliving
                if(2<=alive_cell && alive_cell<=3) {
                    next_cell[row][col] = 1;
                }
                //be killed
                else {
                    next_cell[row][col] = 0;
                }
            }  
        }
    }
    //duplicate to cell from next_cell
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
        //次に遷移
        update();
        //画面を次に移行
        system("clear");
        //出力
        dump();
        system("sleep 0.1s"); 
    }
}