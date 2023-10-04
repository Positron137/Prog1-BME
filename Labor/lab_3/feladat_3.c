#include <stdio.h>
#include <math.h>

double kob (double n);
double abszolut (double n);

int main(void)
{
    printf("a     a^3 |a|  sin(a)\n");
    for (double i = -1; i <= 1; i += 0.1)
    {
        printf("%.1f %.1f %.1f %.1f\n", i, kob(i), abszolut(i), sin(i));
    }
    
    return 0;
}

double kob (double n)
{
    return n * n * n;
}

double abszolut (double n)
{
    return n >= 0 ? n : -n;
}