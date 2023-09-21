#include <stdio.h>
 
int main(void) {
    char betu;
    while (scanf("%c", &betu) == 1){ // futtatásban tartja a proramot és figyeli az EOF jel megjelenését
        printf("betu='%c', betu=%d\n", betu, betu);
    }
    return 0;
}
/*
kiírja minden betűnek a hozzárendelt asciikódot
betűnkét beolvassa a standard-inputot majd kiírja magát a karaktert, és az ascii számát is
csak ctrl+c-vel lehet kilépni, az EOF vagy end of file az adsott file/bemenet végét jelöli
*/