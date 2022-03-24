#include <stdio.h>
#include <stdlib.h>

main() {
    
    float  altura, pesoHomem, pesoMulher;
    
    printf("Informe sua altura:");
    scanf("%f",&altura);
    
    pesoHomem =(72.7*altura)- 58;
    pesoMulher = (62.1*altura)- 44.7;
    
    printf("\n\nCaso você seja do sexo feminino, seu peso ideal será %.2f.",pesoHomem);
    printf("\nCaso você seja do sexo masculino seu peso ideal será %.2f.",pesoMulher);
}