#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * insterts the second string int ot foirst at the given index
 * @param str1 first string
 * @param index index
 * @param str2 second string
 * @return a string in dynamic memory
*/
char* beszur(char* str1, int index, char* str2)
{
    if (index < 0) index = 0;
    if (index > strlen(str1)) index = strlen(str1);
    char* ret = malloc(strlen(str1) +strlen(str2) + 1);
    strncpy(ret, str1,index);
    strcat(ret, str2);
    strcat(ret, str1+index);
    return ret;
}

int main(void){
    char* str = beszur("hello!", 5, " world");
    printf("%s\n", str);
    free(str);
    return 0;
}