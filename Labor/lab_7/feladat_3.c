#include <stdio.h>
#include <stdlib.h>
#include "../../debugmalloc.h"


int main(void)
{
    int *list = malloc(sizeof(int));
    int *list2 = malloc(sizeof(int));
    int i = 0;
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == -1) break;
        list[i] = n;
        for (int j = 0; j < i; j++)
        {
            list[j] = list2[j];
        }
        i++;
        free(list2);
        list2 = malloc(sizeof(int) * (i+1)); //tudom lehetne realloc al is
        for (int j = 0; j < i; j++)
        {
            list2[j] = list[j];
        }
        free(list);
        list = malloc(sizeof(int) * (i+1));
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", list2[i-j-1]);
    }
    free(list2);
    free(list);
    return 0;
}