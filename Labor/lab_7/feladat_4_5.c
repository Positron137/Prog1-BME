#include <stdio.h>
#include <stdlib.h>
#include "../../debugmalloc.h"

char* hosszu_sort_olvas();

int main(void)
{
    char *hosszu_sor = hosszu_sort_olvas();
    printf("%s\n", hosszu_sor);
    free(hosszu_sor);
    return 0;
}

char* hosszu_sort_olvas()
{
    char* sor = malloc(sizeof(char)*2);
    char* str2;
    char c;
    int i = 0;
    while (1)
    {
        c = getc(stdin);
        if (c == '\n') break;
        sor[i] = c;
        sor[i+1] = '\0';
        i++;
        str2 = malloc(sizeof(char)*(i+1));
        strcpy(str2, sor);
        free(sor);
        sor = malloc(sizeof(char)*(i+2));
        strcpy(sor, str2);
        free(str2);
    }
    return sor;
}