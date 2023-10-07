#include <stdio.h>
#include <math.h>

void angles(double *H, double *M, double *S, int h, int m, int s)
{
    double PI = 3.14159;
    *H = (360/12*h%12+360/12/60*m+360/12/60/60*s)*PI/180;
    *M = (360/60*m+360/60/60*s)*PI/180;
    *S = (360/60*s)*PI/180;
}

int main(void)
{
    int h,m,s;
    scanf("%d %d %d", &h, &m, &s);
    double angleH, angleM, angleS;
    angles(&angleH, &angleM, &angleS, h, m, s);

    FILE *fp;
    fp = fopen("ora.svg", "w");
    fprintf(fp, "<svg width=\"200\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n");
    fprintf(fp, "<circle cx=\"100\" cy=\"100\" r=\"98\" stroke=\"black\" stroke-width=\"4\" fill=\"red\" />\n");
    fprintf(fp, "<path d=\"M %lf %lf L 95 15 A 5 5 0 0 1 105 15 L 105 100 A 5 5 0 0 1 95 100 Z\"stroke-width=\"1\" fill=\"white\" stroke=\"black\"/>\n",100-cos(angleH)*5, 100-sin(angleH)*5);
    fprintf(fp, "</svg>\n");
    return 0;
}