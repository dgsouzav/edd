#include <stdio.h>

main() {
    int P1, P2, P3, N1, N2, N3, MP;

    printf("digite a primeira nota: ");
    scanf("%i", &N1);

    printf("digite a segunda nota: ");
    scanf("%i", &N2);
    
    printf("digite a terceira nota: ");
    scanf("%i", &N3);
    
    printf("digite o primeiro peso: ");
    scanf("%i", &P1);
    
    printf("digite o segundo peso: ");
    scanf("%i", &P2);
    
    printf("digite o terceiro peso: ");
    scanf("%i", &P3);


    MP=((N1*P1)+(N2*P2)+(N3*P3))/(P1*P2*P3);
    printf("\na media ponderada é: %i", MP);

    return 0;
}