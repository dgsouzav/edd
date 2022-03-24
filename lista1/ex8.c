#include <stdio.h>
#include <math.h>

int main() {
    
    int N1,N2,N3,N,S,A,Soma;

    printf("entre com o numero N");
    scanf("%i",&N);
    
    S=N*3+1;
    A=N*2-1;
    Soma=S+A;
    
    printf("o sucessor do triplo do numero %i e %i e o antecessor do seu dobro e %i",N,S,A);
    printf("a soma do sucessor com o antecessor e: %i ",Soma);
    
    return 0;
}