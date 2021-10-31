#include <stdio.h>

int main() {
    int n, char_num;
    for (n=1; n< 25; n++) {
        char text[] = "MCI AWGG 100% CT HVS GVCHG MCI RCB'H HOYS."; //42文字 (0~41までを数える)
        char extra = '['; //Zの次の文字(91)に対応する.
        for (char_num=0; char_num<42; char_num++) {
            if(65 <= text[char_num] && text[char_num] <= 90){
                text[char_num] -= n;
                if(text[char_num] < 65) {
                    text[char_num] = extra - (65 - text[char_num]); //(65 - text[char_num]は、はみ出た数の個数)
                }
            };
            
        }
        printf("%s", text);
        printf("\n");
    }
}