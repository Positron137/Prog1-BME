#include <stdio.h>
#include <math.h>

double max(double a, double b){
    return a > b ? a : b;
}
int length(int n){
    n = (int) floor(log10(n))+1;
    return n;
}
int szjmi(int n, int i){
    if (i != 1) {
        int t = n % (int) (pow(10,i));
        n = n % (int) (pow(10,i-1));
    } else
    {
        n = n % (int) (pow(10,i));
    }
    
    return n;
}

int main(){
    int a,b,ah,bh,vsz,i,t;
    a = 123;
    b = 999;
    //scanf("%d %d",&a,&b);
    ah = length(a);
    bh = length(b);
    vsz = 0;
    i = 1;
    t = 0;
    while (i <= (int) max(ah,bh)){
        bh = length(b);
        int szj = szjmi(a,i) + szjmi(b,i);
        if (szj > 9){
            t = szj - szj % 10;
            szj -= t;
            b += t;
        }
        vsz += szj*pow(10,i-1);
        i++;
    }
    printf("%d",vsz);
    return 0;
}