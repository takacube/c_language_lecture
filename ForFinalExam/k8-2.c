#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHAR_F 22
#define MAXCHAR_W 23
#define MAXLINE 16
int main(void){
    char filename[MAXCHAR_F];
    char output_filename[MAXCHAR_F];
    char wrd[MAXLINE][MAXCHAR_W];
    FILE *fp;
    FILE *outputfile; 
    int line=0;
    int i;
    int n;
    //Input file
    printf("Input file name: ");
    fgets(filename,MAXCHAR_F,stdin);
    filename[strlen(filename)-1]='\0';
    printf("\n");
    if((fp=fopen(filename, "r")) == NULL) {
        printf("The input file cannot be opened!\n");
        return -1;
    } else {
        for(i=0;i<=MAXLINE;i++){
            fgets(wrd[i],MAXLINE,fp);
            char *check = strchr(wrd[i], '\n');
            if(check) {
                *check = '\0';
            } else {
                continue;
            }
            //wrd[i][strlen(wrd[i])]='\0';
        }
    }
    fclose(fp);

    // Display strings before sort
    printf("Strings before sort: \n");
    for(i=0;i<=MAXLINE;i++){
        printf("%s\n", wrd[i]);
    }
    //Sort order

    do {
    printf("1(ascending order) or 2(descending order): ");
    scanf("%d", &n);
    scanf("%*c"); /* 残った改行を読み飛ばす処理。*/
    } while (n != 1 && n != 2);
    printf("%d\n", n); /*nを画面表示 */
    printf("\n");

    //Sort
    int Flag = 1;
    if(n==1){
        do {
            Flag = 0;
            for(int start=0; start<MAXLINE; start++){
                if(strcmp(wrd[start],wrd[start+1]) > 0){
                    for(int k=0; k<MAXCHAR_W; k++){
                        char *tmp;
                        char *tmp2;
                        char instant;
                        tmp = &wrd[start][k];
                        tmp2 = &wrd[start+1][k];
                        instant = wrd[start+1][k];
                        *tmp2 = wrd[start][k];
                        *tmp = instant;
                    }
                    Flag++;
                } else {
                    continue;
                }
            }
        } while (Flag != 0);
    } else if (n==2){
        do {
            Flag = 0;
            for(int start=0; start<MAXLINE; start++){
                if(strcmp(wrd[start],wrd[start+1]) < 0){
                    for(int k=0; k<MAXCHAR_W; k++){
                        char *tmp;
                        char *tmp2;
                        char instant;
                        tmp = &wrd[start][k];
                        tmp2 = &wrd[start+1][k];
                        instant = *&wrd[start+1][k];
                        *tmp2 = *&wrd[start][k];
                        *tmp = instant;
                    }
                    Flag++;
                } else {
                    continue;
                }
            }
        } while (Flag != 0);
    } else {
        return -1;
    }
    //Display strings after sort
    printf("String after sort: \n");
    for(i=0;i<=MAXLINE;i++){
        printf("%s\n", wrd[i]);
    }
    //Output file
    printf("Output file name: ");
    fgets(filename,MAXCHAR_F,stdin);
    fp = fopen(filename, "w");
    for(i=0;i<=MAXLINE;i++){
        fprintf(fp, "%s\n", wrd[i]);
    }
    fclose(fp);
    printf("\n");
    printf("Finish!\n");
    return 0;
}