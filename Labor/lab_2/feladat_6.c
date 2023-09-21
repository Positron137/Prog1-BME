#include <stdio.h>

int main(void)
{
    char pit[10] = "Pitagorasz";
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++)
        {
            printf("%c", pit[j]);
        }
        printf("\n");
        char temp = pit[0];
        for (int j = 0; j < 9; j++)
        {
            pit[j] = pit[j+1];
        }
        pit[9] = temp;
        temp = pit[0];
    }
    return 0;
}