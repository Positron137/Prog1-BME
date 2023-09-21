#include <math.h>
#include <stdio.h>

int main(void)
{
    int n;
    printf("adj egy szamot: ");
    scanf("%d", &n);
    int or_len = (int) log10(n) + 1;
    prints:
    if ((int) log10(n) + 1 != or_len){
        for (int i = 0; i < or_len-((int) log10(n) + 1); i++)
        {
            printf(" ");
        }
    }
    printf("%d|", n);
    for (int i = 2; i <= n; i++)
    {
        if (n%i == 0)
        {
            printf("%d\n",i);
            n /= i;
            goto prints;
        }
        
    }
    return 0;
}