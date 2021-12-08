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
    filename[strlen(filename)-1]='\0';
    printf("\n");

    if((fp=fopen(filename, "r")) == NULL) {
        printf("The input file cannot be opened!\n");
        return -1;
    } else {
        for(i=0;i<=MAXLINE;i++){
            fgets(wrd[i],MAXLINE,fp);
            //printf("this is test\n");
            //printf("%s\n", wrd[i]);
        }
    }
    fclose(fp);

    printf("Strings before sort: \n");
    for(i=0;i<=MAXLINE;i++){
        printf("%s", wrd[i]);
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
            fprintf(outputfile, "%s", wrd[i]);
        }
    }
    fclose(outputfile);



    return 0;
}