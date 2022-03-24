#include <stdio.h>
#include <stdlib.h>

main() {
    float C;
    
    int F,c;
    
    printf("informe um valor de Fahrenheit para converter para Celsius: ");
    scanf("%d",&F);
        C = (F - 32.0) * (5.0 / 9.0);
        c = C;
    
    printf("Celsius(decimal): %f\n",C);
    
    printf("Celsius(inteiro): %d\n",c);
    
    //system("PAUSE");//
    
    return 0;
}