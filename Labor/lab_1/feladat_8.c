#include <stdio.h>

int main(void)
{
    int l;
    printf("Mekkor legyen a vonal? ");
    scanf("%d", &l);
    printf("+");
    for (int i = 0; i < l; i++)
    {
        printf("-");
    }
    printf("+");
    return 0;
}