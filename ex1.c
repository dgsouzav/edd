#include <stdio.h>

int main() {
    float metro;

    printf("Entre com um valor em METRO.\n");
    scanf("%f ",&metro);

    printf("%.2f metro(s) eh equivalente a %.2f centimetro.\n",metro,metro*100);

    printf("%.2f metro(s) eh equivalente a %.2f milimetro.\n",metro,metro*1000);

    return(0);
}