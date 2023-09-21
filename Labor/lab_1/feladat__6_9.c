#include <stdio.h>
#include <math.h>

int main(void)
{
    double a,b,c,d;
    double x1,x2;
    printf("Mi a 3 polinom erteke? ");
    scanf("%lf %lf %lf", &a, &b, &c);
    d = b*b-4*a*c;
    if (a == 0)
    {
        printf("1 db megoldas van:\n");
        printf("x= %lf\n", -c/b);
        return 0;
    }
    if (d > 0)
    {
        x1 = (-b+sqrt(d))/(2*a);
        x2 = (-b-sqrt(d))/(2*a);
        printf("2 db megoldas van:\n");
        printf("x1 = %.3lf\nx2 = %.3lf\n", x1, x2);
    }
    else if (d == 0)
    {
        x1 = -b/(2*a);
        printf("1 db megoldas van:\n");
        printf("x1 = %.3lf\n", x1);
    }
    else
    {
        printf("Nincs valós megoldasa\n");
    }
    return 0;
}