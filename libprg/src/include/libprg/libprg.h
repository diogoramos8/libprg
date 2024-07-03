//
// Created by aluno on 13/03/24.
//

#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//structs
typedef struct fila fila_t;
typedef struct pilha pilha_t;
typedef struct no no_t;

////lista
//void criarlista(int **vetor, int tam);
//void povoar(int *vetor, int tam);
//
//
//int buscalinear(int *vetor,int tam, int elem);
//int bulisentinela(int *vetor, int tam, int elem);
//int bulisentinelaord(int *vetor, int tam, int elem);
//
//int buscabinariaite(int *vetor, int tam, int elem);
//int buscabinariarec(int *vetor, int ini, int fim, int elem);
//fila
fila_t* criarfila(int capacidade);
bool enfileirar(fila_t *fila, int elemento);
int desinfileirar(fila_t *fila);
int getinicio(fila_t *fila);
int getfinal(fila_t *fila);
int gettamanhofila(fila_t *fila);
bool isvaziafila(fila_t *fila);
bool ischeiafila(fila_t *fila);

//pilha
pilha_t* criarpilha(int capacidade);
bool empilhar(pilha_t *pilha, int elemento);
int desempilhar(pilha_t *pilha);
int gettamanhopilha(pilha_t *pilha);
bool ischeiapilha(pilha_t *pilha);
//lista circular encadeada não ordenada (lceno)
void adicionarlceno(no_t** inicio, int dado);
void destruirlceno(no_t** inicio);
no_t buscarlceno(no_t* inicio, int dado);
bool remover(no_t** inicio, int dado);
int getelementos(no_t** inicio, int dado);

//algoritimos de ordenação
int* bubblesort(int *vetor, int tamanho);

#endif
//#include <stdio.h>
//#include <libprg/libprg.h>
//
//int main() {
//    int capacidade;
//    printf("insira a capacidade\n");
//    scanf("%d", &capacidade);
//
//    pilha_t* pilha = criarpilha(10);
//    int tam, elemento, resultado;
//    printf("insira elemento\n");
//    scanf("%d", &elemento);
//    if (empilhar(pilha, elemento) == false){
//        printf("a pilha ja esta cheia");
//    }
//    resultado = desempilhar(pilha);
//    return 0;
//}
