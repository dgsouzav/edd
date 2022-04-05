#include <stdio.h>

int soma_algarismos(int numero) {
    int soma = 0;
    while (numero > 0) {
        soma += numero % 10;
        numero /= 10;
    }
    return soma;
}

int main() {
    int numero;
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);
    printf("A soma dos algarismos é %d\n", soma_algarismos(numero));
    return 0;
}