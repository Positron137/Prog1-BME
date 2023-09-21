#include <stdio.h>

int main(void) {
    int list[10] = {123,346,124,7513,34,23,243,543,28,93};
    printf("A tomb: ");
    for (int i = 0; i < 10; i++)
    {
        printf("[%d]=%d ", i, list[i]);
    }
    int min = list[0];
    int mini = 0;
    for (int i = 0; i < 10; i++)
    {
        if (list[i] < min){
            min = list[i];
            mini = i;
        }
    }
    printf("\nA legkisebb szam: %d\n", min);
    printf("A legkisebb szam indexe: %d\n", mini);
    printf("Jelolve: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d%s ", list[i], i==mini ? "[MIN]" : "");
    }
    
    return 0;
}