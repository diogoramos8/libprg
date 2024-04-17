//
// Created by aluno on 17/04/24.
#include <libprg/libprg.h>
typedef struct no{
    int dado;
    struct no* proximo;
}no_t;

void adicionarlceno(no_t** inicio, int dado){
no_t* novo = (no_t*) malloc (sizeof(no_t*));
novo->dado = dado;
novo->proximo = *inicio;
*inicio = novo;
}

no_t buscarlceno(no_t* inicio, int dado){
    no_t* atual = inicio;
    if (atual->dado == dado){
        inicio = atual->proximo;
        return *atual;}
    while(atual->proximo !=(NULL)){
        if (atual->dado != dado){
             atual = atual->proximo;
        }
        else {return *inicio;}
    }
no_t vazio;
vazio.proximo = (NULL);
vazio.dado = 0;
return vazio;
}

bool remover(no_t** inicio, int dado) {
no_t *atual = *inicio;
    if (atual->dado == dado){
        *inicio = atual->proximo;
        free(atual);
        return true;
    }




}