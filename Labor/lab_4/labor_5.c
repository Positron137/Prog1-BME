#include <stdio.h>
#include <string.h>

/* from https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(*str == ' ') str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && *end == ' ') end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}
*/


char *trim(char *s)
{
    while (*s == ' ')
    {
        s++;
    }
    int len = strlen(s)-1;
    for (int i = len; i > 0; i--)
    {
        if (s[i] != ' ')
        {
            s[i+1] = '\0';
            break;
        }
        
    }
    return s;
}

int main()
{
    char a[] = "  hello, mizu?   ";
    printf("%s", trim(a));
    return 0;
}