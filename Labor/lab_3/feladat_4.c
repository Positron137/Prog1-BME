#include <stdio.h>
#include <stdbool.h>

bool maganhangzo(char c) {
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main(void) {
    char c;
    char c2;
    while (scanf("%c", &c) != EOF) {
        c2 = c;
        if ('A' <= c && c <= 'Z')
        {
            c2 += 32;
        }
        if (maganhangzo(c2))
            printf("%cv%c", c, c2);
        else
            printf("%c", c);
    }
 
    return 0;
}