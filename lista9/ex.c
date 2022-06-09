#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct sPessoa{
    char nome[50];
    int matricula;
}Pessoa;

typedef struct sCelula{
    Pessoa info;
    struct sCelula *next;
}Celula;

Celula* criarCelula(){
    Celula *nova = (Celula *) malloc(sizeof(Celula));
    return nova;
}

void inicializarLista(Celula **lista){
    (*lista)=NULL;
}

int listaVazia(Celula **lista){
    if((*lista)==NULL){
        return 1;
    }else{
        return 0;
    }
}

int inserirFim(Celula **lista, Pessoa elemento){
    Celula *novaCelula;
    Celula *auxiliar;

    novaCelula=criarCelula();
    if(novaCelula==NULL){
        printf(": memoria cheia.");
        return 0;
    }
    novaCelula->info=elemento;
    novaCelula->next=NULL;

    if(listaVazia(lista)){
        (*lista)=novaCelula;
        return 1;
    }

    auxiliar = (*lista);

    while(auxiliar->next!=NULL){
        auxiliar=auxiliar->next;
    }

    auxiliar->next=novaCelula;
    return 1;
}

int inserirInicio(Celula **lista, Pessoa elemento){
    Celula *novaCelula = criarCelula();
    if(novaCelula==NULL){
        printf(": memoria cheia.");
        return 0;
    }

    if(listaVazia(lista)){
        return inserirFim(lista, elemento);
    }
    novaCelula->info=elemento;
    novaCelula->next=(*lista);
    (*lista)=novaCelula;
    return 1;
}

void imprimirElemento(Pessoa elemento){
    printf("Nome: %s | matricula: %d\n", elemento.nome, elemento.matricula);
}

void imprimirLista(Celula **lista){
     Celula *auxiliar = (*lista);
     if(listaVazia(lista)){
        printf("\nLista Vazia.");
     }else{
         printf("Lista: \n");
         while(auxiliar != NULL){
            imprimirElemento(auxiliar->info);
            auxiliar = auxiliar->next;
         }
         printf("\n");
     }

}


Pessoa removerInicio(Celula **lista){
    Celula *removida;
    Pessoa removido;
    strcpy(removido.nome, " ");
    removido.matricula=-1;

    if(listaVazia(lista)){
        printf(": lista vazia");
        return removido;
    }

    removida=(*lista);
    removido=removida->info;

    (*lista)=(*lista)->next;

    free(removida);
    return removido;
}

Pessoa removerFim(Celula **lista){
    Celula *removida;
    Celula *anterior;

    Pessoa removido;
    strcpy(removido.nome, " ");
    removido.matricula=-1;

    if(listaVazia(lista)){
        printf(": lista vazia!\n");
        return removido;
    }

    if((*lista)->next==NULL){
        return removerInicio(lista);
    }
        

    removida=(*lista);
    while(removida->next!=NULL){
        anterior=removida;
        removida=removida->next;
    }
    removido=removida->info;
    anterior->next=NULL;
    free(removida);
    return removido;
}

Celula *pesquisarMatricula(Celula **lista, int mat){
    Celula *auxiliar;

    if(listaVazia(lista)){
        printf(": lista vazia");
        return NULL;
    }

    auxiliar=(*lista);

    while(auxiliar!=NULL){
        if(auxiliar->info.matricula==mat){
            return auxiliar;
        }
            
        auxiliar=auxiliar->next;
    }
    printf("\nPessoa inexistente.");
    return NULL;
}

Pessoa removerPessoa(Celula **lista, int mat){
    Celula *removida;
    Celula *anterior;

    Pessoa removido;
    strcpy(removido.nome, " ");
    removido.matricula=-1;

    if(listaVazia(lista)){
        printf(": lista vazia!\n");
        return removido;
    }

    removida=pesquisarMatricula(lista, mat);

    if(removida==NULL){
        printf(": matricula nao encontrada.");
        return removido;
    }

    if(removida==(*lista)){
        return removerInicio(lista);
    }

    removido=removida->info;
    anterior = (*lista);

    while(anterior->next!=removida){
        anterior=anterior->next;
    }

    anterior->next=removida->next;
    free(removida);

    return removido;
}

int inserirOrdenado(Celula **lista, Pessoa elemento){
    Celula *nova, *aux, *anterior;

    nova = criarCelula();
    if(nova==NULL){
        printf(": memoria cheia.\n");
        return 0;
    }

    nova->info=elemento;
    nova->next=NULL;

    if(listaVazia(lista)){
        inserirInicio(lista, nova->info);
        return 1;
    }

    aux=(*lista);

    while(aux!=NULL){
        if(nova->info.matricula<=aux->info.matricula){
            break;
        }
        anterior=aux;
        aux=aux->next;
    }

    nova->next=aux;

    if(aux==(*lista)){
        (*lista)=nova;
    }else {
        anterior->next=nova;
    }
        
    return 1;
}

int menuPrincipal(){
    int resp;

    printf("\n---Menu Principal---\n");
    printf("1-Verificar se a lista esta vazia\n");
    printf("2-Inserir Pessoa no fim na lista\n");
    printf("3-Inserir Pessoa no inicio da lista\n");
    printf("4-Imprimir lista de Pessoas\n");
    printf("5-Remover Pessoa no inicio\n");
    printf("6-Remover Pessoa do fim\n");
    printf("7-Pesquisar uma Pessoa da lista por matricula\n");
    printf("8-Remover uma da lista por matricula\n");
    printf("9-Inserir Pessoa ordenando a matricula.\n");
    printf("0-Sair\n");
    scanf("%d", &resp);
    printf("\n");
    system("cls || clear");

    return resp;
}

int main(){
    int resposta, mat; Pessoa elemento;

    Celula *inicioLista;
    Celula *pesquisa;
    inicializarLista(&inicioLista);

    do{
        resposta=menuPrincipal();

        switch(resposta)
        {
            case 1:
                if(listaVazia(&inicioLista))
                    printf("A lista esta vazia.\n");
                else
                    printf("Ha pelo menos uma Pessoa na lista.\n");
                break;
            case 2:
                printf("Entre com o nome da Pessoa a ser adicionada.\n");
                scanf(" %[^\n]", elemento.nome);
                printf("Entre com a matricula da Pessoa a ser adicionada. \n");
                scanf("%d", &elemento.matricula);
                inserirFim(&inicioLista, elemento);
                break;
            case 3:
                printf("Entre com o nome da Pessoa a ser adicionada no inicio da lista.\n");
                scanf(" %[^\n]", elemento.nome);
                printf("Entre com a matricula da Pessoa a ser adicionada no inicio da lista.\n");
                scanf("%d", &elemento.matricula);
                inserirInicio(&inicioLista, elemento);
                break;
            case 4:
                imprimirLista(&inicioLista);
                break;
            case 5:
                removerInicio(&inicioLista);
                break;
            case 6:
                removerFim(&inicioLista);
                break;
            case 7:
                printf("Entre com a matricula a ser pesquisada.\n");
                scanf("%d", &mat);
                pesquisa=pesquisarMatricula(&inicioLista, mat);
                if(pesquisa!=NULL)
                    printf("Nome: %s | Matricula: %d", pesquisa->info.nome, pesquisa->info.matricula);
                break;
            case 8:
                printf("Entre com a matricula a ser excluida.\n");
                scanf("%d", &mat);
                removerPessoa(&inicioLista, mat);
                break;
            case 9:
                printf("Entre com o nome da Pessoa a ser adicionada.\n");
                scanf(" %[^\n]", elemento.nome);
                printf("Entre com a matricula da Pessoa a ser adicionada. \n");
                scanf("%d", &elemento.matricula);
                inserirFim(&inicioLista, elemento);
                break;
            case 0:
                printf("Ate breve.\n");
                break;
            default:
                printf("Entre com valor valido.\n");
                break;
        }

    }
    while(resposta!=0);

    return 0;
}