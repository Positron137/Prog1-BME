#include <stdio.h>

int main(void)
{
    printf("%f\n", (double)(
        4+2-
        (3-(6+
        (double)(4/5)
        )))/(double)(
            3*(2-7)
            ));
}