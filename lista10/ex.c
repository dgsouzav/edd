#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 5


typedef struct sContainer { // struct Container 
    int codContainer;    // identificador do container
    char proprietario[60];  // nome do proprietario
    char fabricaco[11];  // data de fabricacao
}CONTAINER;


typedef struct stack {  // struct Pilha
    CONTAINER elem[TAM];  // vetor de elementos
    int topo;  // topo da pilha
}Pilha;


void inicializar(Pilha *pilha) { // configura uma pilha recem criada 
     pilha->topo = -1;  // topo da pilha
}


int pilhaVazia(Pilha *pilha) { // verifica se a pilha esta vazia
    if(pilha ->topo ==-1) { // se topo == -1, entao pilha vazia
        
        return 1;  // pilha vazia
    }
    return 0; // pilha nao vazia
}


int pilhaCheia(Pilha *pilha) { // verifica se a pilha esta cheia
    if(pilha -> topo == (TAM-1)) { // se topo == TAM-1, entao pilha cheia
        
        return 1; // pilha cheia
    }
    return 0; // pilha nao cheia
}


int push(Pilha *pilha, CONTAINER elemento) { // insere um elemento na pilha
    if(pilhaCheia(pilha)) {  // se pilha cheia, nao insere
        printf("\nERRO! Pilha Cheia. ");  // erro
        
        return 0;  // nao insere
    }
    pilha->elem[pilha->topo+1] =elemento; // insere elemento
    pilha->topo++;  // incrementa topo
    
    return 1; // inseriu com sucesso
}


CONTAINER pop(Pilha *pilha) { // remove um elemento da pilha
    CONTAINER removido;
    removido.codContainer=-1;
    
    strcpy(removido.proprietario, " ");
    strcpy(removido.fabricaco, " ");   // se pilha vazia, nao remove
    if(pilhaVazia(pilha)) {
        printf("Nao ha elemento para remover.\n"); // erro
        
        return removido; // nao remove
    }
    removido = pilha->elem[pilha->topo]; // remove elemento
    pilha->topo--; // decrementa topo
    
    return removido; // removeu com sucesso
}


CONTAINER topoEl(Pilha *pilha) { // retorna o elemento do topo da pilha
    CONTAINER topo; // elemento do topo
    topo.codContainer=-1; // inicializa com -1
   
    strcpy(topo.proprietario, " "); // inicializa com " "
    strcpy(topo.fabricaco, " "); // inicializa com " "
    if(pilhaVazia(pilha)) { // se pilha vazia, nao retorna elemento
        printf("Nao ha elemento.\n"); // erro
        
        return topo; // nao retorna elemento
    }
    topo = pilha->elem[pilha->topo]; // retorna elemento do topo
    
    return topo; // retorna elemento do topo
}

// ex
void inverterPilhas(Pilha *p1, Pilha *p2) { // inverte duas pilhas
    int total = p2->topo; // total de elementos da pilha 2

    for(int i = 0; i <= total; i++) { // para cada elemento da pilha 2
        push(p1, topoEl(p2)); // insere elemento da pilha 2 na pilha 1
        
        pop(p2); // remove elemento da pilha 2
    }
}


CONTAINER pesquisarContaier(Pilha *p, int pesquisa) { // pesquisa um container
    CONTAINER con; // container
    Pilha aux; // pilha auxiliar
    
    inicializar(&aux); // inicializa pilha auxiliar
    con.codContainer=-1; // inicializa com -1
    
    strcpy(con.proprietario, "Invalido"); // inicializa com "Invalido"
    strcpy(con.fabricaco, "Invalido"); // inicializa com "Invalido"

    if(pilhaVazia(p)) { // se pilha vazia, nao pesquisa
        printf("ERRO: pilha vazia.\n"); // erro
        return con; // nao pesquisa
    } while(p->topo!=-1) { // enquanto topo != -1
        if(p->elem[p->topo].codContainer==pesquisa) { // se codigo do container for igual ao pesquisa
            con = topoEl(p); // retorna elemento do topo
            inverterPilhas(p, &aux); // inverte pilhas
            
            return con; // retorna elemento do topo
        } else { // se nao for igual
            push(&aux, topoEl(p)); // insere elemento do topo na pilha auxiliar
            
            pop(p); // remove elemento do topo
        }
    }
    inverterPilhas(p, &aux); // inverte pilhas
    
    printf("Numero pesquisado nao existe.\n"); // erro
    
    return con; // nao pesquisa
}


void imprimirPilha(Pilha* p) { // imprime pilha
    Pilha aux; // pilha auxiliar
    
    inicializar(&aux); // inicializa pilha auxiliar
    CONTAINER con; // container

    if(pilhaVazia(p)!=1) { // se pilha nao vazia
        printf("Containers: \n"); // imprime containers
        while(p->topo!=-1) { // enquanto topo != -1
            con=topoEl(p); // retorna elemento do topo
            
            printf("Identificacao: %d | Proprietario: %s | Fabricacao: %s\n", 
            con.codContainer, con.proprietario, con.fabricaco); // imprime elemento do topo
            
            push(&aux, con); // insere elemento do topo na pilha auxiliar
            
            pop(p); // remove elemento do topo
        }
        inverterPilhas(p, &aux); // inverte pilhas
    } else {
        printf("ERRO: a pilha esta vazia.\n"); // erro
    }
}


int menuPrincipal() { // menu principal
    int resp; // resposta
    
    printf("--Menu Principal\n"); // imprime menu
    printf("1-Adicionar container no topo da pilha\n"); // imprime opcao 1
    printf("2-Remover o topo da pilha\n"); // imprime opcao 2
    printf("3-Pesquisar container\n");  // imprime opcao 3
    printf("4-Imprimir lista de containers\n"); // imprime opcao 4
    printf("0-Sair\n"); // imprime opcao 0
    scanf("%d", &resp); // le resposta

    printf("\n"); // pula linha
    system("cls || clear"); // limpa tela

    return resp; // retorna resposta
}


int main() { // main
    Pilha p; // pilha
    CONTAINER con; // container
    
    int resp, pesquisa; // resposta e pesquisa
    inicializar(&p); // inicializa pilha

    do { // enquanto resposta != 0
        resp=menuPrincipal(); // chama menu principal

        switch (resp) { // switch para resposta
        case 0: // opcao 0
            printf("Ate breve.\n"); 
            
            break;
        case 1: // opcao 1
            printf("Entre com o codigo de identificador do container.\n");
            scanf("%d", &con.codContainer); // le codigo de identificador
            printf("Entre com o nome do proprietario.\n");
            scanf(" %[^\n]", con.proprietario); // le nome do proprietario
            printf("Entre com a data de fabricacao (dd/mm/aaaa).\n");
            scanf(" %[^\n]", con.fabricaco); // le data de fabricacao
            push(&p, con); // insere container na pilha
            
            break; // fim opcao 1
        case 2: // opcao 2
            pop(&p); // remove container do topo
            
            break;
        case 3:  // opcao 3
            printf("Entre com a identificacao a ser pesquisada\n");
            scanf("%d", &pesquisa); // le identificacao a ser pesquisada
            
            con=pesquisarContaier(&p, pesquisa); // pesquisa container
            
            printf("Identificacao: %d | Proprietario: %s | Fabricacao: %s\n", 
            con.codContainer, con.proprietario, con.fabricaco); // imprime container
            
            break; // fim opcao 3
        case 4: // opcao 4
            imprimirPilha(&p); // imprime pilha
            
            break; // fim opcao 4
        default: // opcao invalida
            printf("Entre com uma opcao valida.\n"); // erro
           
            break; // fim opcao invalida
        }

    } while(resp!=0); // enquanto resposta != 0

    return 0;
}