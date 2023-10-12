#include <stdio.h>
 
int main(void) {
    signed char i = 1;
    while (i > 0) {
        ++i;
    }
    printf("%d\n", i);
 
    return 0;
}
/*
int: -2137383648 integer overflow (32 bit, 2's complement)
short int: -32768 -||- (16 bit, 2's complement)
singed char: -128 (8 bit, 2's complement)
*/