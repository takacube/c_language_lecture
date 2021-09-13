#include <stdio.h>
int main()
{
    char name[] = "Tokyo University of Science", *po;
    po = name;
    int num_large = 0;
    int num_small = 0;
    while(*po != '\0')
        {
            if (*po <= 'z' && *po >= 'a')
                num_small += 1;
            else
                num_large += 1;
            po++;
        }
    printf("small_character: %d, large_character: %d\n", num_small, num_large);
}

