#include <stdio.h>

int reset() {return 1;}
int add(int a) {return a+1;}
int negate(int a) {return -a;}
int mul2(int a) {return a*2;}

int main(void)
{
    int a = 1;
    int choice;
    do
    {
        printf("a = %d\n\n",a);
        printf("0. Alapertek visszaallitasa (a = 1)\n"
        "1. Hozzaad 1-et\n"
        "2. Megforditja az elojelet\n"
        "3. Szorozza 2-vel\n"
        "9. Kilepes\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 0:
                a = reset();
                break;
            case 1:
                a = add(a);
                break;
            case 2:
                a = negate(a);
                break;
            case 3:
                a = mul2(a);
                break;
            default:
                break;
        }
    } while (choice != 9);
}