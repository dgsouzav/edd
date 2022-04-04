#include <stdio.h>
#include <math.h>

float distancia(float x1, float y1, float x2, float y2);

int main() {
    float x1, y1, x2, y2;
    printf("digite as coordenadas do ponto 1: ");
    scanf("%f %f", &x1, &y1);
    printf("digite as coordenadas do ponto 2: ");
    scanf("%f %f", &x2, &y2);
    printf("a distância é: %.2f\n", distancia(x1, y1, x2, y2));
    return 0;
}

float distancia(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}