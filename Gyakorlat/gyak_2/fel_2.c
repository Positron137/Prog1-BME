#include <stdio.h>
#include <math.h>
int main(void)
{
    int n = 3;
    for (int i = 0; i < n; i++)
    {
        int o_num = 1+i*2;
        for (int j = n-i-1; j > 0; j--)
        {
            printf(" ");
        }
        for (int j = 0; j < o_num; j++)
        {
            printf("o");
        }
        printf("\n");
    }
}
/*
  o
 ooo
ooooo
*/