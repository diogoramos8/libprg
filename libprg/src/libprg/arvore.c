//
// Created by aluno on 31/07/24.
//
#include <libprg/libprg.h>

typedef struct arvore {
    int valor;
    struct arvore *esquerda;
    struct arvore *direita;
} arvore_t;

arvore_t *criar_no(int valor){
    arvore_t *no = (arvore_t *) malloc(sizeof(arvore_t));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

arvore_t *plantar(int tam){
    srand(time(NULL));
    arvore_t *a = criar_no(rand()%100);

    for (int i = 0; i < tam; i++){
        int valor = rand()%100;

    }
}
void destruir_no(arvore_t *no) {
if (no != NULL) {
destruir_no(no->esquerda);
destruir_no(no->direita);
free(no);
}
}


// tod0 nó é raiz de uma subárvore
arvore_t *inserir_valor(arvore_t *raiz, int valor){
if (raiz == NULL) {
return criar_no(valor);
} else if (valor < raiz->valor) {
raiz->esquerda = inserir_valor(raiz->esquerda, valor);
} else if (valor > raiz->valor) {
raiz->direita = inserir_valor(raiz->direita, valor);
}
return raiz;
}
bool busca(arvore_t *raiz, int valor){
if (raiz == NULL) return false;
if (valor == raiz->valor) return true;
if (valor < raiz->valor) return busca(raiz->esquerda, valor);
return busca(raiz->direita, valor);
}

arvore_t *remover_valor(arvore_t *raiz, int valor){
if (raiz == NULL) return raiz;
if (valor < raiz->valor) {

    raiz->esquerda = remover_valor(raiz->esquerda, valor);
} else if (valor > raiz->valor) {
    raiz->direita = remover_valor(raiz->direita, valor);
} else {
// IF nó folha ou nó com um filho
    if ((raiz->direita == NULL || raiz->esquerda == NULL)){
        if(raiz->esquerda != NULL){
            arvore_t *aux = raiz->esquerda;
            destruir_no(raiz->esquerda);
            raiz = aux;
            destruir_no(aux);
        } else if(raiz->direita != NULL){
            raiz = raiz->direita;
            raiz->direita;
        }else {
            destruir_no(raiz);
        }
    } else {
        arvore_t *aux = raiz->direita;
        while (aux->esquerda != NULL){
            aux= aux->esquerda;
        }
        raiz->valor = aux->valor;
        raiz = remover_valor(aux, aux->valor);
    }
// ELSE nó com dois filhos
}
return raiz;
}