#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHAR_F 22
#define MAXCHAR_W 23
#define MAXLINE 16
int main(){
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
        }
    }
    fclose(fp);

    // Display strings before sort
    printf("Strings before sort: \n");
    for(i=0;i<=MAXLINE;i++){
        printf("%s", wrd[i]);
    }
    printf("\n");
    //Sort order

    do {
    printf("1(ascending order) or 2(descending order): ");
    scanf("%d", &n);
    scanf("%*c"); /* 残った改行を読み飛ばす処理。*/

    } while (n != 1 && n != 2);
    printf("%d\n", n); /*nを画面表示 */
    printf("\n");

    //Sort 
    int Count;
    int Flag = 1;
    do {
        Count++;
        Flag=0;
        for(int start=0; start<MAXLINE; start++){
            for(int point=start; point<MAXLINE; point++){
                if(strcmp(wrd[MAXLINE-point-1], wrd[MAXLINE-point]) < 0) {
                    char change[MAXLINE];
                    for(int i=0; i<MAXCHAR_W; i++){
                        change[i] = wrd[MAXLINE-point][i];
                        if(wrd[MAXLINE-point-1][i] == '\0'){
                            continue;
                        } else {
                            wrd[MAXLINE-point][i]=wrd[MAXLINE-point-1][i];
                            printf("tttt: %c\n", wrd[MAXLINE-point][i]);
                        }
                    }
                    for(int i=0; i<MAXCHAR_W; i++){
                        wrd[MAXLINE-point-1][i]=change[i];
                    }
                    Flag++;
                } else {
                }
            }
        }
    } while(Flag);
    // Output file
    printf("Output file name: ");
    fgets(filename,MAXCHAR_F,stdin);
    fp = fopen(filename, "w");
    for(i=0;i<=MAXLINE;i++){
        fprintf(fp, "%s", wrd[i]);
    }
    fclose(fp);
    printf("\n");
    printf("Finish!\n");
    return 0;
    //fgets(output_filename,MAXCHAR_F,stdin);
    //if((outputfile=fopen(output_filename, "w")) == NULL) {
    //    printf("The input file cannot be opened!\n");
    //    return -1;
    //} else {
    //    for(i=0;i<=MAXLINE;i++){
    //        fprintf(outputfile, "%s", wrd[i]);
    //    }
    //}
    //fclose(outputfile);
}