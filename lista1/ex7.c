#include <iostream>

int main() {

    float real, dolar, calculo;

    printf("Digite um valor: ");
    scanf("%f", &real);

    printf("Digite a cotacao do dolar: ");
    scanf("%f", &dolar);

    calculo = real * dolar;
    printf("Valor em Dolar: $%.2f", calculo);

    return 0;
}