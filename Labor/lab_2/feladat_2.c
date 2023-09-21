#include <stdio.h>

int main(void)
{
    int n = 1;
    int prod = 1;
    while (n <= 8){
        prod *= n;
        n++; // a végén 9 mert 9 <= 8
    }
    printf("%d", prod);

    int szorzat = 1;
    n = 8;
    while (n > 1) {
        szorzat *= n; // 20160 mikor épp 3ra váltott
        n -= 1;
    }
    printf("%d\n", szorzat);

    int a = 11220;
    int b = 2002;
    while (b > 0) {
        int temp = b;
        b = a % b; //44 mikor a 374-re váltott
        a = temp;
    }
 
    printf("lnko = %d\n", a);
    return 0;
}