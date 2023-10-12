#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ketto_hatvany(void) {
    for (int i = 0; i < 32; i++)
    {
        printf("%d\n", (int) pow(2, i));
    }
}

void unsigned_int(void) {
    unsigned int i = 1;
    while (i > 0)
    {
        i <<= 1;
        printf("%u\n", i);
    }
}

void word_len(void) {
    unsigned int i = 1;
    while ((i << 1) > 0)
    {
        i <<= 1;
    }
    printf("uint: %u\n", i);
    unsigned char i2 = 1;
    while ((i2 << 1) > 0)
    {
        i2 <<= 1;
    }
    printf("uchar: %u\n", (unsigned int)i2);
    unsigned short int i3 = 1;
    while ((i3 << 1) > 0)
    {
        i3 <<= 1;
    }
    printf("usint: %u\n", (unsigned int)i3);
    unsigned long int i4 = 1;
    while ((i4 << 1) > 0)
    {
        i4 <<= 1;
    }
    printf("ulint: %lu\n", i4);
    unsigned long long int i5 = 1;
    while ((i5 << 1) > 0)
    {
        i5 <<= 1;
    }
    printf("ullint: %I64u\n", i5);
}

int main(void)
{
    //ketto_hatvany();
    //unsigned_int();
    word_len();
    return 0;
}