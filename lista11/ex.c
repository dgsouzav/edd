#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 5

typedef struct fila{  // estrutura de fila
    int elemento[TAM_MAX];  // vetor de elementos
    int cabecalho, fim;  // cabecalho e fim da fila
}FILA;  // nome da estrutura

void iniciarFila(FILA *fila){  // inicia a fila
    f -> cabecalho = fila -> fim = 0;  // inicializa o cabecalho e o fim da fila
    f -> fim = 0;  // inicializa o fim da fila
}

int filaVazia (FILA *fila){  // verifica se a fila esta vazia
    return (fila -> fim == fila -> cabecalho);  // retorna 1 se a fila estiver vazia
}

int filaCheia (FILA *fila){  // verifica se a fila esta cheia
    int proximo = (fila -> fim + 1) % TAM_MAX;  // calcula o proximo elemento da fila
    return (proximo == fila -> cabecalho);  // retorna 1 se a fila estiver cheia
}

int criarFila (FILA *fila, int elemento){  // insere um elemento na fila
    int proximo;  // proximo elemento da fila
    if (filaCheia(fila)){  // verifica se a fila esta cheia
        printf("Fila cheia\n");  // imprime mensagem de erro
        return 0;  // retorna 0
    }
    proximo = (fila -> fim + 1) % TAM_MAX;  // calcula o proximo elemento da fila
    fila -> elemento[proximo] = elemento;    // insere o elemento na fila 
    fila -> fim = proximo;               // atualiza o fim da fila
    return 1;  // retorna 1
}

int desfazerFila (FILA *fila, int *elemento){  // remove um elemento da fila
    if (filaVazia(fila)){  // verifica se a fila esta vazia
        printf("Fila vazia\n");  // imprime mensagem de erro
        return 0;  // retorna 0
    }
    *elemento = fila -> elemento[fila -> cabecalho];  // atualiza o elemento
    fila -> cabecalho = (fila -> cabecalho + 1) % TAM_MAX;  // atualiza o cabecalho
    return 1;  // retorna 1
}

void imprimirFila (FILA *fila){  // imprime a fila
    while (!filaVazia(fila)){  // enquanto a fila nao estiver vazia
        int elemento;  // elemento da fila
        desfazerFila(fila, &elemento);  // remove um elemento da fila
        printf("%d\n", elemento);  // imprime o elemento
    }
}

void imprimirAuxiliar (FILA *fila){  // imprime a fila
    FILA aux;  // fila auxiliar
    iniciarFila(&aux);  // inicializa a fila auxiliar

    if (!fila Vazia(fila)){  // verifica se a fila nao esta vazia
        int elemento;  // elemento da fila
        while (!filaVazia(fila)){  // enquanto a fila nao estiver vazia
            desfazerFila(fila, &elemento);  // remove um elemento da fila
            criarFila(&aux, elemento);  // insere o elemento na fila auxiliar
        }
    }
    while (!filaVazia(&aux)){  // enquanto a fila auxiliar nao estiver vazia
        int elemento;  // elemento da fila
        desfazerFila(&aux, &elemento);  // remove um elemento da fila auxiliar
        criarFila(fila, elemento);   // insere o elemento na fila
    }
    printf("Fila vazia\n");  // imprime mensagem de erro
}

int menu(){  // menu de opcoes
    int opcao;  // opcao do menu
    printf("1 - Criar fila\n");  // opcao 1
    printf("2 - Desfazer fila\n");  // opcao 2
    printf("3 - Imprimir fila\n");  // opcao 3
    printf("4 - Inverter fila\n");  // opcao 4
    printf("5 - Sair\n");       // opcao 5
    printf("Digite a opcao desejada: "); // pede a opcao do menu
    scanf("%d", &opcao); // le a opcao do menu
    return opcao; // retorna a opcao do menu
}

int main(){ // main
    FILA fila0; // fila 0
    iniciarFila(&fila0); // inicializa a fila 0
    int aux, opcao; // auxiliar e opcao do menu
    do{ // enquanto o usuario nao digitar 5
        opcao = menu(); // le a opcao do menu   
        switch (opcao){ // switch para a opcao do menu
            case 1: // opcao 1
                printf("Digite o elemento: ");  
                scanf("%d", &aux);  // le o elemento
                criarFila(&fila0, aux); // insere o elemento na fila 0
                break; // break
            case 2: // opcao 2
                desfazerFila(&fila0, &aux); // remove o elemento da fila 0
                printf("Elemento desfechado: %d\n", aux); // imprime o elemento desfechado
                break; // break
            case 3: // opcao 3
                imprimirFila(&fila0); // imprime a fila 0
                break; // break
            case 4:     // opcao 4
                imprimirAuxiliar(&fila0);   // imprime a fila 0
                break; // break
            case 5: // opcao 5
                printf("Saindo...\n"); // imprime mensagem de saida
                break;  // break
            default: // opcao default
                printf("Opcao invalida\n"); // imprime mensagem de erro
        }
} while (opcao != 5); // enquanto o usuario nao digitar 5
    return 0; // retorna 0
}