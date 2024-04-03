//
// Created by aluno on 03/04/24.
//
#include <libprg/libprg.h>
typedef struct pilha{
    int *vetor;
    int tamanho;
    int capacidade;
} pilha_t;

pilha_t* criarpilha(int capacidade){
    pilha_t* pilha = (pilha_t*) calloc(capacidade, sizeof(pilha_t));
    pilha->vetor = (int*) calloc(capacidade, sizeof(int));
    pilha->tamanho = 0;
    pilha->capacidade = capacidade;
    return pilha;
}

bool ischeiapilha(pilha_t *pilha){
    if (pilha->tamanho == pilha->capacidade){return true;}
    return false;
}
bool empilhar(pilha_t *pilha, int elemento){
    if (ischeiapilha(pilha) != true){
        pilha->tamanho++;
        pilha->vetor[pilha->tamanho] = elemento;
        return true;
    }
    return false;

}
int desempilhar(pilha_t *pilha){
    if (pilha->tamanho > 0){
        pilha->tamanho--;
        return pilha->vetor[pilha->tamanho++];
    }
    printf("a pilha ja esta vazia");
    return -1;
}
int gettamanhopilha(pilha_t *pilha){
    return pilha->tamanho;
}
