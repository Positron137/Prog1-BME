#include <stdio.h>
#include <math.h>

struct pont
{
    double x;
    double y;
}; typedef struct pont pont;

int main(void)
{
    pont p1;
    p1.x = 2.2;
    p1.y = 1.6;
    pont p2;
    printf("Adj meg egy x és y koordinátát: ");
    scanf("%lf %lf", &p2.x, &p2.y);
    pont p3 = {(p1.x+p2.x)/2,(p1.y+p2.y)/2};
    printf("3. pont kooridnatai: (%lf; %lf)\n", p3.x,p3.y);
    return 0;
}
