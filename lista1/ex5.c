#include <stdio.h>
#include <math.h>

int main() {

    double a, b , c, x1, x2, delta;

    printf("digite os valores para a, b e c: ");
    scanf("%lf %lf %lf", &a, %b, &c);

    delta = b*b - 4*a*c;

    if(delta < 0){
        printf("não há raízes reais");
    }else{
        if(delta == 0){
            x1 = (-b + sqrt(delta))/(2*a);
            printf("a única raiz é %lf \n ", x1);
        }else{
            x1 = (-b + sqrt(delta))/(2*a);
            x2 = (-b + sqrt(delta))/(2*a);
            printf("a única raiz é %lf e %lf \n ", x1, x2);
        }
    }

    return 0;
}