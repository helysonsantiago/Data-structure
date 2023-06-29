#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef struct no {
    int valor;
    struct no* prox;
} NO;

NO* criar_no(int valor);
void inserir_final(NO** inicio, NO** fim, int valor);
void inserir_posicao(NO** inicio, int valor, int posicao);
int remover_ultimo(NO** inicio, NO** fim);
int remover_valor(NO** inicio, int valor);
int remover_posicao(NO** inicio, int posicao);
int pesquisar_valor(NO* inicio, int valor);
void imprimir_lista(NO* inicio);
int contar_elementos(NO* inicio);
void lixeiro();

int main() {
    NO* inicio = NULL;
    NO* fim = NULL;
    int opcao, valor, posicao;
    
   

    while(1) {
     	printf("\nNome: Helyson Santiago");
    	printf("\nRA: 184831\n\n");
    
        printf("\n1. Inserir Valor na Lista\n");
        printf("2. Inserir Valor na Posicao da Lista\n");
        printf("3. Remover Ultimo Valor da Lista\n");
        printf("4. Remover Valor da Lista\n");
        printf("5. Remover Posicao da Lista\n");
        printf("6. Pesquisar Valor na Lista\n");
        printf("7. Imprimir Lista\n");
        printf("0. Finalizar Programa\n\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Insira o valor: ");
                scanf("%d", &valor);
                inserir_final(&inicio, &fim, valor);
                lixeiro();
                break;
            case 2:
                printf("Insira o valor: ");
                scanf("%d", &valor);
                printf("Insira a posicao: ");
                scanf("%d", &posicao);
                inserir_posicao(&inicio, valor, posicao);
                lixeiro();
                break;
            case 3:
                remover_ultimo(&inicio, &fim);
                 lixeiro();
                break;
            case 4:
                printf("Insira o valor a ser removido: ");
                scanf("%d", &valor);
                remover_valor(&inicio, valor);
                 lixeiro();
                break;
            case 5:
                printf("Insira a posicao a ser removida: ");
                scanf("%d", &posicao);
                remover_posicao(&inicio, posicao);
                lixeiro();
                break;
            case 6:
                printf("Insira o valor a ser pesquisado: ");
                scanf("%d", &valor);
                pesquisar_valor(inicio, valor);
                lixeiro();
                break;
            case 7:
                imprimir_lista(inicio);
                lixeiro();
                break;
            case 0:
                exit(0);
            default:
                printf("Opcao invalida!\n");
                lixeiro();
        }
        
              
        	
    }

    return 0;
}

NO* criar_no(int valor) {
    NO* novo_no = (NO*) malloc(sizeof(NO));

    if(novo_no == NULL) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }

    novo_no->valor = valor;
    novo_no->prox = NULL;
    return novo_no;
}

void inserir_final(NO** inicio, NO** fim, int valor) {
    NO* novo_no = criar_no(valor);

    if(*inicio == NULL) {
        *inicio = novo_no;
    } else {
        (*fim)->prox = novo_no;
    }

    *fim = novo_no;
    printf("Existem %d numero(s) na lista\n", contar_elementos(*inicio)); 
}

void inserir_posicao(NO** inicio, int valor, int posicao) {
    if(posicao < 0 || posicao >= contar_elementos(*inicio)) {
        printf("Posicao escolhida nao existe\n");
        return;
    }

    NO* novo_no = criar_no(valor);
    if(posicao == 0) {
        novo_no->prox = *inicio;
        *inicio = novo_no;
    } else {
        NO* anterior = *inicio;
        for(int i = 0; i < posicao - 1; i++) {
            anterior = anterior->prox;
        }
        novo_no->prox = anterior->prox;
        anterior->prox = novo_no;
    }
    printf("Existem %d numero(s) na lista\n", contar_elementos(*inicio));
}


int remover_ultimo(NO** inicio, NO** fim) {
    if(*inicio == NULL) {
        printf("Lista vazia!\n");
        return -1;
    } else {
        NO* temp = *inicio;
        NO* anterior = NULL;
        while(temp->prox != NULL) {
            anterior = temp;
            temp = temp->prox;
        }
        int valor = temp->valor;
        free(temp);
        if(anterior != NULL) {
            anterior->prox = NULL;
            *fim = anterior;
        } else {
            *inicio = NULL;
            *fim = NULL;
        }
        printf("Existem %d numero(s) na lista\n", contar_elementos(*inicio));
        return valor;
    }
}

int remover_valor(NO** inicio, int valor) {


    NO* temp = *inicio;
    NO* anterior = NULL;

    while(temp != NULL && temp->valor != valor) {
        anterior = temp;
        temp = temp->prox;
    }

    if(temp == NULL) {
        printf("Valor escolhido nao existe\n");
        return -1;
    } else {
        if(anterior != NULL) {
            anterior->prox = temp->prox;
        } else {
            *inicio = temp->prox;
        }

        int valor_removido = temp->valor;
        free(temp);
        printf("Existem %d numero(s) na lista\n", contar_elementos(*inicio));
        return valor_removido;
    }
}


int remover_posicao(NO** inicio, int posicao) {
	
	if (posicao < 0) {
        printf("Posicao não existe!\n");
        return -1;
    }

    NO* temp = *inicio;
    NO* anterior = NULL;
    for(int i = 0; i < posicao; i++) {
        if(temp == NULL) {
            printf("Posicao não existe!\n");
            return -1;
        }
        anterior = temp;
        temp = temp->prox;
    }
    if(temp == NULL) {
        printf("Posicao não existe!\n");
        return -1;
    } else {
        if(anterior != NULL) {
            anterior->prox = temp->prox;
        } else {
            *inicio = temp->prox;
        }
        int valor_removido = temp->valor;
        free(temp);
        printf("Existem %d numero(s) na lista\n", contar_elementos(*inicio));
        return valor_removido;
    }
}

int pesquisar_valor(NO* inicio, int valor) {
    NO* temp = inicio;
    int posicao = 0;
    while(temp != NULL && temp->valor != valor) {
        temp = temp->prox;
        posicao++;
    }
    if(temp == NULL) {
        printf("Valor nao encontrado!\n");
        return -1;
    } else {
        printf("Valor encontrado na posicao %d\n", posicao);
        return posicao;
    }
}

void imprimir_lista(NO* inicio) {
    NO* temp = inicio;

    while(temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->prox;
    }
}

int contar_elementos(NO* inicio) {
    NO* temp = inicio;
    int cont = 0;

    while(temp != NULL) {
        cont++;
        temp = temp->prox;
    }

    return cont;
}

void lixeiro(){
	printf("\n");
	system("pause");
	system("cls");
}
