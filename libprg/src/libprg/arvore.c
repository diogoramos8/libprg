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
    arvore_t *a = criar_no(rand());
    arvore_t *arvore = a;
    for (int i = 0; i < tam; i++){
        int valor = rand();
        int j=0;
        arvore = a;
        while(j<1){
            if (valor < arvore->valor){
                if (arvore->esquerda == NULL){
                    arvore->esquerda = criar_no(valor);
                    j=1;
                } else {
                    arvore = arvore->esquerda;
                }
            }
            else {
                if (arvore->direita == NULL){
                    arvore->direita = criar_no(valor);
                    j=1;
                } else {
                    arvore = arvore->direita;
                }
            }
        }
    }
    return arvore;
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
int maiorarvore(arvore_t *no){
    while (no->direita != NULL){
        no = no->direita;
    }
    return no->valor;
}

int menorarvore(arvore_t *no){
    while (no->esquerda != NULL){
        no = no->esquerda;
    }
    return no->valor;
}

//#include <stdio.h>
//#include <libprg/libprg.h>
//int main(void) {
//    struct timeval inicio, fim;
//
//
//    printf("Hello, World!\n");
//    gettimeofday(&inicio, 0);
//
//    arvore_t *arveres = plantar(100000);
//
//    gettimeofday(&fim, 0);
//
//    long seg = fim.tv_sec - inicio.tv_sec;
//    long mseg = fim.tv_usec - inicio.tv_usec;
//    double tempo_total = seg + mseg * 1e-6;
//
//    printf("Tempo gasto: %f segundos.\n", tempo_total);
//    gettimeofday(&inicio, 0);
//    int maior = maiorarvore(arveres);
//    gettimeofday(&fim, 0);
//
//    seg = fim.tv_sec - inicio.tv_sec;
//    mseg = fim.tv_usec - inicio.tv_usec;
//    tempo_total = seg + mseg * 1e-6;
//
//    printf("mais a direita:%d\n", maior);
//    printf("Tempo gasto: %f segundos.\n", tempo_total);
//
//    gettimeofday(&inicio, 0);
//    int menor = menorarvore(arveres);
//    gettimeofday(&fim, 0);
//
//    seg = fim.tv_sec - inicio.tv_sec;
//    mseg = fim.tv_usec - inicio.tv_usec;
//    tempo_total = seg + mseg * 1e-6;
//
//    printf("mais a esquerda:%d\n", menor);
//    printf("Tempo gasto: %f segundos.\n", tempo_total);
//    return 0;
//}
