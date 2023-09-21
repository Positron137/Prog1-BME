#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <math.h>

int main(void)
{
    double h,d;
    printf("Tartaly festese\n\n");
    printf("Milyen magas? ");
    scanf("%lf", &h);
    printf("Mennyi az atmeroje? ");
    scanf("%lf", &d);
    printf("\n%lf doboz festek kell",(d*h+2*pow(d/2,2))*M_PI/2);
    return 0;
}