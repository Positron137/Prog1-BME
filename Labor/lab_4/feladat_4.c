#include <stdio.h>

int main(void)
{
    char name[64]; //longest name in the world: Hubert Blaine Wolfe­schlegel­stein­hausen­berger­dorff Sr.
    printf("Adj egy nevet: ");
    scanf("%[^\n]s", name);
    for (char *s = name; *s != '\0'; s++)
    {
        printf("%c\n", *s);
    }
    
}