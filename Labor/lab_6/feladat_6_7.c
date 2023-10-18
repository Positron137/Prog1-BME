#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned long szamok[9] = { 0U, 1931988508U, 581177634U, 581374240U,
                            581177632U, 581177634U, 1919159836U, 0U,  65535U|~65535U};
    /*szamok[0] = szamok[0] & 65535;
    szamok[1] = szamok[1] & ~65535;
    szamok[2] = szamok[2] | 65535;
    szamok[3] = szamok[3] | ~65535;
    szamok[4] = szamok[4] ^ 65535;
    szamok[5] = szamok[5] ^ ~65535;*/
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 32; j++){
            printf("%c", (szamok[i] & (unsigned long int) 1) ? '#':' '); // prints LSB (least significant bit first)
            szamok[i] >>= 1;
        }
        printf("\n");
    }
}