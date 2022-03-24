#include <stdio.h>

main() {
    float metro;

    printf("entre com um valor em METRO.\n");
    scanf("%f ",&metro);

    printf("%.2f metros é equivalente a %.2f centimetro.\n",metro,metro*100);

    printf("%.2f metros é equivalente a %.2f milimetro.\n",metro,metro*1000);

    return(0);
}