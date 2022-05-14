#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 100

// exercicio 1
void ex1() {
    int *n1, *n2;
    n1 = (int*)malloc(sizeof(int));
    n2 = (int*)malloc(sizeof(int));

    printf("Entre com o primeiro numero: ");
    scanf("%d", n1);

    printf("Entre com o segundo numero: ");
    scanf("%d", n2);

    free(n1);
    free(n2);
    return;
}

// exercicio 2
void ex2() {
    int i, num_comp;
    float *vet;

    printf("Entre com o numero de componentes: ");
    scanf("%d", &num_comp);

    vet = (float*)malloc(num_comp * sizeof(float));

    for (i = 0; i < num_comp; i++) {
        printf("Entre com o %d numero: ", i + 1);
        scanf("%f", &vet[i]);
    }

    printf("\n Valores de vetor dinâimico: ");
    for (i = 0; i < num_comp; i++) {
        printf("%f ", vet[i]);
    }
    free(vet);
}

// exercicio 3  
// estrutura
typedef struct sCliente{
    char nome[200];
    int idade[3];
    char telefone[15];
} Cliente;

void ex3() {
    Cliente *clientes;
    int i, num_clientes;

    printf("Entre com o numero de clientes: ");
    scanf("%d", &num_clientes);

    clientes = (Cliente*)malloc(num_clientes * sizeof(Cliente));

    for (i = 0; i < num_clientes; i++) {
        printf("Entre com o nome do cliente %d: ", i + 1);
        scanf("%s", clientes[i].nome);

        printf("Entre com a idade do cliente %d: ", i + 1);
        scanf("%d", &clientes[i].idade);

        printf("Entre com o telefone do cliente %d: ", i + 1);
        scanf("%s", clientes[i].telefone);
    }
    for (int i = 0; i < num_clientes; i);
    {
        printf("\nNome: %s", clientes[i].nome);
        printf("\nIdade: %d", clientes[i].idade);
        printf("\nTelefone: %s", clientes[i].telefone);
    }
    free(clientes);
}

// exercicio 4
void ex4() {
    int x, y;  
    printf("Entre com a quantidade de linhas da matriz: ");
    scanf("%d", &x);
    printf("Entre com a quantidade de colunas da matriz: ");
    scanf("%d", &y);

    int **matriz;
    matriz = (int**)malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++) {
        matriz[i] = (int*)malloc(y * sizeof(int));
    }
     printf("\nEntre com os valores da matriz: ");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("Posicao [%d][%d]\n", i, j);
            scanf("%d", &matriz[i][j]);
        }
        for (int j = 0; j < x; j++) {
            for (int j = 0; j < y; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");      
        }
        for (int i = 0; i < x; i++) {
            free(matriz[i]);
        }
        free(matriz);
        matriz = NULL;
}

// exercicio 5
// estrutura
typedef struct sCarro {
    char marca[50];
    char modelo[50];
    int ano;
    char placa[10];
} Carro;


// cadastro
void cadastro(Carro *carro) {
    printf("Entre com a marca do carro: ");
    scanf("%s", carro->marca);
    printf("Entre com o modelo do carro: ");
    scanf("%s", carro->modelo);
    printf("Entre com o ano do carro: ");
    scanf("%d", &carro->ano);
    printf("Entre com a placa do carro: ");
    scanf("%s", carro->placa);
}

// editar
void editarCarro(Carro *carro) {
    printf("Atualizar marca do carro");
    scanf("%[^\n]+", &carro->marca);
    printf("Atualizar modelo do carro");
    scanf("%[^\n]+", &carro->modelo);
    printf("Atualizar ano do carro");
    scanf("%d", &carro->ano);
    printf("Atualizar placa do carro");
    scanf("%s", carro->placa);
}

// imprimir
void imprimirCarro(Carro *carro) {
    printf("\nMarca: %s", carro->marca);
    printf("\nModelo: %s", carro->modelo);
    printf("\nAno: %d", carro->ano);
    printf("\nPlaca: %s", carro->placa);
}

// sair 
void sair() {
    printf("\nSaindo do programa...");
}

int main() {
    Carro * veiculos;
    veiculos = (Carro*) malloc(sizeof(Carro));

    int opcao, posicao = 0, placa;

    int continuar = 1;

    do {
        printf("Lista 7");
        printf("\n1 - EX1");
        printf("\n2 - EX2");
        printf("\n3 - EX3");
        printf("\n4 - EX4");
        printf("\n5 - Cadastrar carro");
        printf("\n6 - Sair");

        scanf("%d", &continuar);
        system("cls || clear");

        switch(continuar) {
            case 1:
                ex1();
                break;
            case 2:
                ex2();
                break;
            case 3:
                ex3();
                break;
            case 4:
                ex4();
                break;
            case 5:
            do {
                printf("\n1 - Cadastrar carro\n2 - Editar carro\n3 - Imprimir carro\n4 - Sair\n");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        cadastro(&veiculos[posicao]);
                        posicao++;
                        break;
                    case 2:
                        printf("Entre com a placa do carro: ");
                        scanf("%d", &placa);
                        editarCarro(&veiculos[placa]);
                        break;
                    for (int i = 0; i < posicao; i++) {
                        if(veiculos[i], placa == placa) {
                            editarCarro(&veiculos[i]);
                        }
                    case 3:
                        for (int i = 0; i < posicao; i++) {
                            imprimirCarro(&veiculos[i]);
                        } break;
                        if(opcao!=0) {
                            printf("\nOpcao invalida!\n");
                            break;
                        } 
                    }
                    while(opcao!=0);
                    free(veiculos);
                    break;
                    case 0:
                    sair();
                    break;

                    default: printf("\nDigite uma opcao valida!\n");
                } 
            } while(continuar);
        }
    }
}