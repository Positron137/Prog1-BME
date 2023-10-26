#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * return a strign without the given substirng indices
 * @param str input
 * @param start start index (exlcusive)
 * @param end end index (inclusive)
 * @return a string in dynamic memory
*/
char* nsubstr(char* str, int start, int end)
{
    if (start < 0) start = 0;
    if (end > strlen(str)) end = strlen(str);
    char*ret = malloc(end-start+strlen(str)+1);
    strncpy(ret, str, start);
    strcpy(ret+start, str + end);
    return ret;
}

int main(void){
    char* str = "hello, vilag";
    char* ret = nsubstr(str, 4, 8);
    printf("%s\n", ret);
    free(ret);
    return 0;
}