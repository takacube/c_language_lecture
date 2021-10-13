#include <stdio.h>
int main() {
    
    int n, char_num;
    for (n=1; n< 25; n++) {
        char text[] = "MCI AWGG 100% CT HVS GVCHG MCI RCB'H HOYS.";
        char extra = '@';
        for (char_num=0; char_num<42; char_num++) {
            if(65 <= text[char_num] && text[char_num] <= 90){
                text[char_num] += n;
                if(text[char_num] > 90) {
                    text[char_num] = extra + (text[char_num]-90);
                }
            };
            
        }
        printf("%s", text);
        printf("\n\n");
    }
}