#include <stdio.h>

int main() {
    int from;
    int char_num;
    for(from=1; from<25; from++) {
        char text[] = "MCI AWGG 100% CT HVS GVCHG MCI RCB'H HOYS.";
        char extra_char = '[';
        for(char_num=0; char_num<42;char_num++) {
            if(65<=text[char_num] && text[char_num]<=90){
                text[char_num] -=from;
                if(text[char_num] < 65) {
                    text[char_num] = extra_char - (65 - text[char_num]);
                }
            }
        }
        printf("%s\n", text);
    }
}