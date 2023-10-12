#include <stdio.h>
#include <math.h>
 
int main(void) {
    printf("1. %f\n", 1.23456789123456789123456789e40); // 1. 12345678912345680000000000000000000000000.000000
    printf("2. %g\n", 1e40); // 1e+040
    printf("3. %s\n", 1e3+1 == 1e3 ? "igaz" : "hamis"); // hamis
    printf("4. %s\n", 1e30+1 == 1e30 ? "igaz" : "hamis"); // igaz
    printf("5. %g\n", pow(10, 40) / pow(10, -40)); // 1e+080
    printf("6. %g\n", powf(10, 40) / powf(10, -40)); // #INF
 
    return 0;
}