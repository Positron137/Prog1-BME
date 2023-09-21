#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int tomb[10];
 
    for (int i = 0; i < 10; i += 1){
        tomb[i] = i * 10;
    }
    int i = 0;
    while (true) { // örökké fut, emiatt a memória egészét kiírja
        printf("%d. elem: %d\n", i, tomb[i]);
        i += 1;
    }
 
    return 0;
}
// túlindexelésnek köszönhetően a memória nem definiált/ mással definiálkt byte-jait írja ki a program.