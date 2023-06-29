#include <stdio.h>
#include <string.h>
#define TAMANHO 3

void push(char *pilha, char **topo, char valor)
{
    if (*topo < pilha + TAMANHO)// Aponta para posição vazia 
    {
        *(*topo) = valor;
        (*topo)++;
    }
}

int pop(char *pilha, char **topo)c// remove o elemento do topo
{
    if (*topo > pilha)
    {
        (*topo)--;
        int valorRemovido = **topo;
        return valorRemovido;
    }
    return 0;
}

void imprimir(char *pilha, char **topo) //  endereço de memória do último elemento inserido na pilha
{
    for (char *p = *topo - 1; p >= pilha; p--)
    {
        printf("[%c]\n", *p);
    }
}

int main()
{
    char pilha[TAMANHO];
    char *topo = pilha;
    push(pilha, &topo, 'c');
    push(pilha, &topo, 'e');
    push(pilha, &topo, 'g');
    pop(pilha, &topo);
    pop(pilha, &topo);
    pop(pilha, &topo);
    push(pilha, &topo, '2');
    push(pilha, &topo, 'g');
    push(pilha, &topo, '3');
    imprimir(pilha, &topo);
}

