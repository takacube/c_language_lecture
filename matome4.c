#include <stdio.h>

int main(){
    int i, j, plus, each_sum, determinant[4][4], square[4][4], cube[4][4], forth_power[4][4];
    for(i=0; i<4; ++i){
        for(j=0; j<4; ++j){
            if(i == 0 && j == 1) determinant[i][j] = 1;
            else if(i == 1 && j == 2) determinant[i][j] = 1;
            else if(i == 2 && j == 3) determinant[i][j] = 1;
            else determinant[i][j] = 0;
        }
    }

    for(i=0;i<4;++i){
        for(j=0;j<4;++j){
            square[i][j] = determinant[i][j] * determinant[i][j];
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                each_sum = 0;
                for(plus=0;plus<4;plus++)
                    each_sum = each_sum + determinant[i][plus]*determinant[plus][j];
                square[i][j] = each_sum;
                }
            }
        }
    }

    for(i=0;i<4;++i){
        for(j=0;j<4;++j){
            cube[i][j] = square[i][j] * determinant[i][j];
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                each_sum = 0;
                for(plus=0;plus<4;plus++)
                    each_sum = each_sum + square[i][plus]*determinant[plus][j];
                cube[i][j] = each_sum;
                }
            }
        }
    }

    for(i=0;i<4;++i){
        for(j=0;j<4;++j){
            forth_power[i][j] = cube[i][j] * determinant[i][j];
            for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                each_sum = 0;
                for(plus=0;plus<4;plus++)
                    each_sum = each_sum + cube[i][plus]*determinant[plus][j];
                forth_power[i][j] = each_sum;
                }
            }
        }
    }

    for(i=0; i < 4; ++i){
        for(j=0; j<4; ++j){
            printf("square[%d][%d]=%d\n", i+1, j+1, square[i][j]);
        }
    }

    for(i=0; i < 4; ++i){
        for(j=0; j<4; ++j){
            printf("cube[%d][%d]=%d\n", i+1, j+1, cube[i][j]);
        }
    }

    for(i=0; i < 4; ++i){
        for(j=0; j<4; ++j){
            printf("forth_power[%d][%d]=%d\n", i+1, j+1, forth_power[i][j]);
        }
    }
}