#include <stdio.h>
#include <stdlib.h>

main() {
    float massa, altura, _IMC;

    printf("digite seu peso(kg): ");
    scanf("%f",&massa);
    printf("digite sua altura(metros): ");
    scanf("%f",&altura);

    _IMC = massa/(pow(altura,2));

    printf("-----------------------------------\n");
    printf("seu IMC é: %0.2f\n",_IMC);

    return 0;
}