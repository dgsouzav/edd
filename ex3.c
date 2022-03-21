#include <stdio.h>
#include <stdlib.h>

int main() {
    float massa, altura, _IMC;

    printf("Digite sua Massa (Kg): ");
    scanf("%f",&massa);
    printf("Digite sua Altura (Metros): ");
    scanf("%f",&altura);

    _IMC = massa/(pow(altura,2));

    printf("-----------------------------------\n");
    printf("Seu IMC e: %0.2f\n",_IMC);

    return 0;
}