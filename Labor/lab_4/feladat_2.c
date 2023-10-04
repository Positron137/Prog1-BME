# include <stdio.h>

void kocka(double size, double *vol, double *area);

int main(void)
{
    double size = 2.7;
    double vol;
    double area;
    kocka(size, &vol, &area);
    printf("terület: %f\nfelület: %f\n", vol, area);
    return 0;
}

void kocka(double size, double *vol, double *area)
{
    *vol = size * size * size;
    *area = 6 * size * size;
}