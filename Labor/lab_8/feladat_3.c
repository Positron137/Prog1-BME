#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * return a substirng of the input
 * @param str input
 * @param start start index (inclusive)
 * @param end end index (exclusive)
 * @return a substring in dynamic memory
*/
char* substr(char* str, int start, int end)
{
    if (start < 0) start = 0;
    if (end > strlen(str)) end = strlen(str);
    char* ret = malloc(end-start + 1);
    strncpy(ret, str + start, end-start);
    ret[end-start] = '\0';
    return ret;
}

int main(void){
    char* str = "hello, vilag";
    char* ret = substr(str, 3, 9);
    printf("%s\n", ret);
    free(ret);
    return 0;
}