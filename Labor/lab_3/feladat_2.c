#include <stdio.h>
 
int main(void) {
    double szamok[10] = { 2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8 };
 
    /* Az eredeti tömb kiírása */
    printf("Összesen %d szám van.\n", 10);
    for (int i = 0; i < 10; ++i)
        printf("[%d]=%g ", i, szamok[i]);
    printf("\n\n");
 
    /* Negatívak indexeinek kigyűjtése */
    int neg_i[10];
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (szamok[i] < 0)
        {
            neg_i[count] = i;
            count++;
        }
    }
    /* Negatívak kiírása */
    printf("Ebbol %d szam negativ.\n", count);
    for (int i = 0; i < count; ++i)
        printf("[%d]=%g ", neg_i[i], szamok[neg_i[i]]);
    printf("\n");
    return 0;
}