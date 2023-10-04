#include <stdio.h>
int main(void)
{
    int n;
    char roman[5] = "IVXLC";
    printf("adj egy szamot: ");
    scanf("%d", &n);
    if (n >99)
    {
        printf("csak 99ig megyunk!");
        return 0;
    }
    switch (n-(n%10))
    {
    case 10:
        printf("X");
        break;
    case 20:
        printf("XX");
        break;
    case 30:
        printf("XXX");
        break;
    case 40:
        printf("XL");
        break;
    case 50:
        printf("L");
        break;
    case 60:
        printf("LX");
        break;
    case 70:
        printf("LXX");
        break;
    case 80:
        printf("LXXX");
        break;
    case 90:
        printf("XC");
        break;
    default:
        break;
    }
    switch (n%10)
    {
    case 1:
        printf("I");
        break;
    case 2:
        printf("II");
        break;
    case 3:
        printf("III");
        break;
    case 4:
        printf("IV");
        break;
    case 5:
        printf("V");
        break;
    case 6:
        printf("VI");
        break;
    case 7:
        printf("VII");
        break;
    case 8:
        printf("VIII");
        break;
    case 9:
        printf("IX");
    default:
        break;
    }
    printf("\n");
    return 0;
}