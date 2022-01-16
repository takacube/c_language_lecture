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
    //Input file
    printf("Input file name: ");
    fgets(filename,MAXCHAR_F,stdin);
    printf("%s", filename);
    filename[strlen(filename)-1]='\0'; //string's length //strlenは()の中身の長さ。
    printf("\n");
    if((fp=fopen(filename, "r")) == NULL) {
        printf("The input file cannot be opened!\n");
        return -1;
    } else {
        for(i=0;i<=MAXLINE;i++){
            fgets(wrd[i],MAXLINE,fp); //fpは読み込む時には、
            char *check = strchr(wrd[i], '\n'); //1個目の引数の中に2個目の引数があるかどうかをチェック。
            if(check) {
                *check = '\0';
            } else {
                continue;
            }
        }
    }
    fclose(fp);
    printf("Strings before sort: \n");
    for(i=0;i<=MAXLINE;i++){
        printf("%s\n", wrd[i]);
    }
    printf("\n");
    // Output file
    printf("Output file name: ");
    fgets(output_filename,MAXCHAR_F,stdin);
    if((outputfile=fopen(output_filename, "w")) == NULL) {
        printf("The input file cannot be opened!\n");
        return -1;
    } else {
        for(i=0;i<=MAXLINE;i++){
            fprintf(outputfile, "%s\n", wrd[i]);
        }
    }
    fclose(outputfile);
    printf("\n");
    printf("Finish!\n");
    return 0;
}