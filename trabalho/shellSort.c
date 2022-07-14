#include<stdio.h>
#include<stdlib.h>
#define N 5

void shellsort(int *dados);  // Função que ordena os dados

int main(int argc, char** argv){  // Função principal
    int vetor[N], i;  // Declaração do vetor
    for (i = 0; i < N; i++){  // Preenchendo o vetor
        printf("Informe um valor: \n");  // Pedindo o valor
        scanf("%d", &vetor[i]);  // Lendo o valor
    }
    shellsort(vetor);  // Chamando a função shellsort
    for (i = 0; i < N; i++){  // Imprimindo o vetor
        printf("valor: %d \n", vetor[i]);  // Imprimindo o valor
       }
    return (0);  // Retornando 0 = falso

}
void shellsort(int *dados){  // Função shellsort
      int i, j, h, aux;     // Declaração de variáveis
      h = 1;  // Inicialização da variável h em 1
      while (h < N){  // Enquanto h for menor que N
        h = 3 * h + 1;  // h = 3h + 1
      }
      while (h > 1){  // Enquanto h for maior que 1
        h /= 3;  // Para cada interação h = h/3
        for (i = h; i< N; i++){  // Para cada i menor que N
            aux = dados[i];  // aux recebe o valor de dados[i]
            j = i - h;  // j recebe i - h
            while (j >= 0 && aux < dados[j]){  // Enquanto j for maior ou igual a 0 e aux for menor que dados[j]
                dados[j + h] = dados[j];  // dados[j + h] recebe dados[j]
                j -= h;  // j recebe j - h
            } 
            dados[j + h] = aux;  // dados[j + h] recebe aux
        }
    }
}