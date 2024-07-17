//
// Created by aluno on 13/03/24.
//

#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>
#include<sys/time.h>
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
int* bubblesort(int *vetor, int tamanho, bool decrescente);
int* insertionsort(int *vetor, int tamanho, bool decrescente);
int* selectionsort(int *vetor, int tamanho, bool decrescente);
int* povoarvetor(int tamanho);
int* mergesort(int *vetor, int esquerda, int direita);
int* merge(int *vetor, int esquerda, int meio, int direita);
int* quicksort(int *vetor, int inicio, int fim);
int particiona(int *vetor, int inicio, int fim);
void trocarposicao(int *vetora, int *vetorb);
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

//cmake_minimum_required(VERSION 3.21)
//project(myapp C)
//
//set(CMAKE_C_STANDARD 17)
//
//include(FetchContent)
//
//FetchContent_Declare(
//        libprg
//#GIT_REPOSITORY https://github.com/diogoramos8/libprg.git
//GIT_TAG origin/main
//# or GIT_TAG 0.0.1
//
//        You can reference a local directory instead
//URL file:///${CMAKE_CURRENT_SOURCE_DIR}/../libprg
//)
//FetchContent_MakeAvailable(libprg)
//
//add_executable(myapp main.c)
//
//# linking libprg
//target_link_libraries(myapp PUBLIC libprg)

//#include <stdio.h>
//#include <libprg/libprg.h>
//
//
//int main() {
//    struct timeval inicio, fim;
//    printf("Hello, World!\n");
//    printf("insira tamanho do vetor\n");
//    int tamanho;
//    scanf("%d", &tamanho);
//    printf("decrescente =0, crescente =1\n");
//    bool decrescente;
//    int bol;
//    scanf("%d", &bol);
//    decrescente = bol;
//    int *vetor = povoarvetor(tamanho);
//    gettimeofday(&inicio, 0);
//    int *ord = selectionsort(vetor, tamanho, decrescente);
//    gettimeofday(&fim, 0);
//    long seg = fim.tv_sec - inicio.tv_sec;
//    long mseg = fim.tv_usec - inicio.tv_usec;
//    double tempo_total = seg + mseg * 1e-6;
//
//    printf("Tempo gasto: %f segundos.\n", tempo_total);
//    return 0;
//}
