#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int valor;
    struct no* prox;
} NO;

NO* inicio = NULL;
NO* fim = NULL;

int tamanho = 0;

void inserir(int valor) {
    NO* novoNo = (NO*)malloc(sizeof(NO));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    if(fim != NULL) {
        fim->prox = novoNo;
    }
    fim = novoNo;
    if(inicio == NULL) {
        inicio = novoNo;
    }
    tamanho++;
    printf("EXISTEM %d NUMERO(S) NA FILA\n", tamanho);
}

void remover() {
    if(inicio != NULL) {
        NO* temp = inicio;
        int valorRemovido = temp->valor;
        inicio = inicio->prox;
        if(inicio == NULL) {
            fim = NULL;
        }
        free(temp);
        tamanho--;
        printf("NUMERO %d REMOVIDO. EXISTEM %d NUMERO(S) NA FILA\n", valorRemovido, tamanho);
    }
}

void removerTodos() {
    while(inicio != NULL) {
        NO* temp = inicio;
        inicio = inicio->prox;
        printf("NUMERO %d REMOVIDO. ", temp->valor);
        free(temp);
    }
    fim = NULL;
    tamanho = 0;
    printf("A FILA ESTA VAZIA\n");
}

void imprimir() {
    NO* temp = inicio;
    while(temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}

int main() {
    int opcao, valor;
    do {
        printf("1. Inserir Valor na Fila\n");
        printf("2. Remover Primeiro Valor da Fila\n");
        printf("3. Remover Todos os Valores da Fila\n");
        printf("4. Imprimir Fila\n");
        printf("0. Finalizar Programa\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido na fila: ");
                scanf("%d", &valor);
                inserir(valor);
                break;
            case 2:
                remover();
                break;
            case 3:
                removerTodos();
                break;
            case 4:
                imprimir();
                break;
            case 0:
                printf("Finalizando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
    return 0;
}
