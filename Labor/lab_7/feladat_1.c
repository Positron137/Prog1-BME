#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("hany szamot adsz?\n");
    int n;
    scanf("%d", &n);
    int *list = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("adj egy szamot: ");
        scanf("%d", &list[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", list[n-i-1]);
    }
    
    return 0;
}