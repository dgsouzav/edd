#include <stdio.h>
#include <stdlib.h>

int main() {
    float C;
    
    int F,c;
    
    printf("Informe um valor de Fahrenheit para converter para Celsius: ");
    scanf("%d",&F);
        C = (F - 32.0) * (5.0 / 9.0);
        c = C;
    
    printf("Celsius(Valor decimal): %f\n",C);
    
    printf("Celsius(Valor inteiro): %d\n",c);
    
    //system("PAUSE");//
    
    return 0;
}