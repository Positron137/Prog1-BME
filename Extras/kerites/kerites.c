#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct pont
{
    double x,y;
};
typedef struct pont pont;

double tav(pont a ,pont b);
bool egyenlo(pont a, pont b);
pont beolvas(void);

int main(void)
{
    printf("Kerites szamito program\n");
    pont p0 = {-1,-1};
    pont p1 = p0;
    pont p2 = {0,0};
    double running_sum = 0;
    int num = 0;
    while (!egyenlo(p0,p2))
    {
        num++;
        printf("Add meg az %d. keritesoszlop x es y koordinatait: ", num);
        if (num == 1)
        {
            p0 = beolvas();
            p1 = p0;
            continue;
        }
        p2 = beolvas();
        running_sum += tav(p1,p2);
        p1 = p2;
    }
    printf("Kerites hossza: %lf\n", running_sum);

    return 0;
}

double tav(pont a ,pont b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool egyenlo(pont a, pont b)
{
    return (tav(a,b) < 0.01);
}

pont beolvas(void)
{
    pont p;
    scanf("%lf %lf", &p.x, &p.y);
    return p;
}