#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * returns a perfect copy of the input
 * @param str input
 * @return a copy in dynamic memory
*/
char* masolat(char* str){
    char* ret = malloc(strlen(str) + 1);
    strcpy(ret, str);
    return ret;
}

char* hozzfuz(char* str1, char* str2)
{
    char* ret = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(ret, str1);
    strcat(ret, str2);
    return ret;
}

int main(void){
    char* str = masolat("hello");
    printf("%s\n", str);
    str = hozzfuz(str, " world");
    printf("%s\n", str);
    free(str);
    return 0;
}
