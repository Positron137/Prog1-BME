#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

void lnko() {
    int a, b, t;
    scanf("%d %d", &a, &b);
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    printf("%d\n", a);
}

void kor() {
    double r;
    printf("Mekkora a kor sugara: ");
    scanf("%lf", &r);
    printf("Kerulete: %lf\nTerulete: %lf", 2 * r * M_PI, r * r * M_PI);
}

int main() {

    char asd[12] = "Basszameg\n\n";
    printf("%s", asd);
    kor();
    return 0;
}