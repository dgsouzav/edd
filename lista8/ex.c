#include <stdlib.h>
#include <stdio.h>
#$define MAX_SIZE 10

typedef struct sList {
    char element[MAX_SIZE];
    int last;
}List;

void iniciateList(List *list) {
    list->last = -1;
}

int fullList(List *list) {
    if (list->last ==(MAX_SIZE -1)) {
        return 0;
    }
}

int emptyList(List *list) {
    if (list->last == -1) {
        return 0;
    }
}

int insertEnd(List *list, char element) {
    if (fullList(list)) {
        printf("Lista cheia\n");
        return 0;
    }
    list->last++;
    list->element[list->last] = element;
    return 1;
}

int modifyElement(List *list, int position, char element) {
    if (!emptyList(list)) {
        if (position >= 0 && position < list->last + 1/* condition */){
            list->element[position] = element;
            return 1;
        }
    }
    return 1;
}

int removeElement(List *list, int position) {
    int i;
    if(emptyList(list)) {
        printf("Lista vazia\n");
        return 0;
    }
    if(position < 0 || position > list->last) {
        printf("Posicao invalida\n");
        return 0;
    }
    for(i = position; i < list->last; i++) {
        list->element[i] = list->element[i+1];
    }
    list->last--;
    return 1;
}

char accessElement(List *list, int position) {
    if(emptyList(list)) {
        printf("Lista vazia\n");
        return '';
    }
    if(position < 0 || position > list->last) {
        printf("Posicao invalida\n");
        return '';
    }
    return list->element[position];
}

int searchElement(List *list, char element) {
    int i;
    if(emptyList(list)) {
        printf("Lista vazia\n");
        return 0;
    }
    for(i = 0; i <= list->last; i++) {
        if(list->element[i] == element) {
            return 1;
        }
        return -1;
    }
}

int listSize(List *list) {
    return list->last + 1;
}

int mainMenu() {
    int returnQuestion;

    printf("Menu\n");
    printf("Escolha uma opcao\n");
    printf("1 - Inserir elemento no final\n");
    printf("2 - Imprimir\n");
    printf("3 - Inserir elemento\n");
    printf("4 - Inverter\n");
    printf("5 - Ordenar\n");
    printf("0 - Sair\n");

    scanf("%d", &returnQuestion);
    printf("\n");

    return returnQuestion;
}

// ex1
void printoutList(Lista *lista) {
    if(!emptyList(lista)) {
        for(i = 0; i <= lista.last; i++) {
            printf("%c\n", lista.element[i]);
        }
    }
    else {
        printf("Lista vazia\n");
    }
}

// ex2
void insertList(Lista *lista, int t, char element) {
    if(!fullList(lista)) {
        for(int i = list->last; i>t; i--)
            list->element[i+1] = list->element[i];
        list->element[t] = element;
        list->last++;
    }
    else {
        printf("Lista vazia\n");
    }
}

// ex3
void invertedList(Lista *list) {
    char element[list->last];
    if(!emptyList(list)) {
        for(int i = 0; i <= list->last; i++){
            element[i] = list->element[list->last - i];
        }
        for(int i = 0; i <= list->last; i++) {
            list->element[i] = element[i];
        }
        printf("Lista invertida\n");
    }
    else {
        printf("Lista vazia\n");
    }
}

// ex4 
void sortList(Lista *list) {
    int i, j, length = list->last + 1;
    char switch;
    if(!emptyList(list)) {
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < length; j++) {
                if(list->element[i] > list->element[j]) {
                    switch = list->element[i];
                    list->element[i] = list->element[j];
                    list->element[j] = switch;
                }
            }
        }
        printf("Lista ordenada\n");
    }
    else {
        printf("Lista vazia\n");
    }
}

int main() {
    int answer; char element; int t;
    List *list1 = (List *) malloc(sizeof(List));
    iniciateList(list1);

    for(int i = 0; i <= MAX_SIZE; i++) {
        list1->element[i] = '';
    }
    list1->element[0] = 'b';
    list1->last++;

    list1->element[1] = 'a';
    list1->last++;

    list1->element[2] = 'c';
    list1->last++;

    do {
        answer = mainMenu();
        switch(answer) {
            case 1:
                printf("Digite um elemento para inserir no final da lista\n");
                scanf("%c", &element);
                insertEnd(list1, element);
                break;
            case 2:
                printoutList(list1);
                break;
            case 3:
                printf("Digite um elemento para inserir na lista\n");
                scanf("%c", &element);
                printf("Digite a posicao para inserir o elemento\n");
                scanf("%d", &t);
                insertList(list1, t, element);
                break;
            case 4:
                invertedList(list1);
                break;
            case 5:
                sortList(list1);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while(answer != 0);
    free(list1);

    return 0;
}