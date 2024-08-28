//
// Created by aluno on 13/03/24.
//
// https://emersonmello.me/ensino/prg2/tempo/
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
typedef struct no_avl no_avl_t;
typedef struct arvore arvore_t;
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
arvore_t desinfileirarvore(fila_t *fila);

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

//jesus é o jardineiro
arvore_t *criar_no(int valor);
void destruir_no(arvore_t *no);
arvore_t *inserir_valor(arvore_t *raiz, int valor);
bool busca(arvore_t *raiz, int valor);
arvore_t *remover_valor(arvore_t *raiz, int valor);
arvore_t *plantar(int tam);
int maiorarvore(arvore_t *no);
int menorarvore(arvore_t *no);
void inorder(arvore_t *no);
void preorder(arvore_t *no);
void posorder(arvore_t *no);
void percurso_largura(arvore_t *no, fila_t *fila);
fila_t* criarfilaarvore(int capacidade);
bool enfileirararvore(fila_t *fila, arvore_t *elemento);

//arvore avl
int altura(no_avl_t *v);
int fator_balanceamento(no_avl_t *v);
no_avl_t *rotacao_esquerda(no_avl_t *v);
no_avl_t *rotacao_dupla_esquerda(no_avl_t *v);
no_avl_t *rotacao_direita(no_avl_t *v);
no_avl_t *rotacao_dupla_direita(no_avl_t *v);
no_avl_t *balancear(no_avl_t *v);
no_avl_t *removerb(no_avl_t *v, int valor);
no_avl_t *criar_no_avl(int valor);
no_avl_t *plantar_avl(int tam);
no_avl_t *inserir(no_avl_t *v, int valor);
void destruir_no_avl(no_avl_t **no);
bool busca_avl(no_avl_t *raiz, int valor);
int maiorarvore_avl(no_avl_t *no);
int menorarvore_avl(no_avl_t *no);
void inorder_avl(no_avl_t *no);
void preorder_avl(no_avl_t *no);
void posorder_avl(no_avl_t *no);
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

//int main() {
//    struct timeval inicio, fim;
//    printf("Hello, World!\n");
//    printf("insira tamanho do vetor\n");
//    int tamanho;
//    scanf("%d", &tamanho);
////    printf("decrescente =0, crescente =1\n");
////    bool decrescente;
////    int bol;
////    scanf("%d", &bol);
////    decrescente = bol;
//    int *vetor = povoarvetor(tamanho);
//    gettimeofday(&inicio, 0);
//    int *ord = quicksort(vetor, 0, tamanho);
//    gettimeofday(&fim, 0);
//    long seg = fim.tv_sec - inicio.tv_sec;
//    long mseg = fim.tv_usec - inicio.tv_usec;
//    double tempo_total = seg + mseg * 1e-6;
////    for (int i =0; i<tamanho; i++){
////        printf("%d: %d\n", i, vetor[i]);
////    }
//    printf("Quick Tempo gasto: %f segundos.\n", tempo_total);
//    gettimeofday(&inicio, 0);
//    ord = mergesort(vetor, 0, tamanho-1);
//    gettimeofday(&fim, 0);
//    seg = fim.tv_sec - inicio.tv_sec;
//    mseg = fim.tv_usec - inicio.tv_usec;
//    tempo_total = seg + mseg * 1e-6;
//    printf("Merge Tempo gasto: %f segundos.\n", tempo_total);
//
//    gettimeofday(&inicio, 0);
//    ord = selectionsort(vetor, tamanho, 1);
//    gettimeofday(&fim, 0);
//    seg = fim.tv_sec - inicio.tv_sec;
//    mseg = fim.tv_usec - inicio.tv_usec;
//    tempo_total = seg + mseg * 1e-6;
//    printf("Selection Tempo gasto: %f segundos.\n", tempo_total);
//
//    gettimeofday(&inicio, 0);
//    ord = bubblesort(vetor, tamanho, 1);
//    gettimeofday(&fim, 0);
//    seg = fim.tv_sec - inicio.tv_sec;
//    mseg = fim.tv_usec - inicio.tv_usec;
//    tempo_total = seg + mseg * 1e-6;
//    printf("Bubble Tempo gasto: %f segundos.\n", tempo_total);
//
//    gettimeofday(&inicio, 0);
//    ord = insertionsort(vetor, tamanho, 1);
//    gettimeofday(&fim, 0);
//    seg = fim.tv_sec - inicio.tv_sec;
//    mseg = fim.tv_usec - inicio.tv_usec;
//    tempo_total = seg + mseg * 1e-6;
//    printf("Insertion Tempo gasto: %f segundos.\n", tempo_total);
//
//    return 0;
//}


//#include <stdbool.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef struct {
//    char *cpf;
//    char *nome;
//    char *email;
//} pessoa_t;
//typedef struct arvore {
//    char *chave;
//    pessoa_t *valor;
//    struct arvore *prox;
//} arvore_t;
//typedef struct dicionario {
//    int tamanho; // tamanho do vetor
//    arvore_t **vetor;
//} dicionario_t;
//
//dicionario_t *criar_dicionario(int m) {
//    dicionario_t *d = NULL;
//    if (m < 1) {
//        return NULL;
//    }
//    if ((d = (dicionario_t *)malloc(sizeof(dicionario_t))) == NULL) {
//        return NULL;
//    }
//    d->tamanho = m;
//    if ((d->vetor = calloc(m, sizeof(arvore_t *))) == NULL) {
//        return NULL;
//    }
//// O calloc já deve colocar NULL, mas deixo aqui de forma explícita
//    for (int i = 0; i < m; ++i) {
//        d->vetor[i] = NULL;
//    }
//    return d;
//}
//
//
//void destruir_pessoa(pessoa_t *pessoa) {
//    if (pessoa->cpf != NULL) {
//        free(pessoa->cpf);
//    }
//    if (pessoa->nome != NULL) {
//        free(pessoa->nome);
//    }
//    if (pessoa->email != NULL) {
//        free(pessoa->email);
//    }
//    free(pessoa);
//}
//
//
//void destruir_no(arvore_t *arvore) {
//    if (arvore != NULL) {
//        free(arvore->chave);
//        destruir_pessoa(arvore->valor);
//        free(arvore);
//    }
//}
//
//
//void destruir_dicionario(dicionario_t *d) {
//    if (d != NULL) {
//        for (int i = 0; i < d->tamanho; ++i) {
//            // TODO destruir lista encadeada
//            destruir_no(d->vetor[i]);
//        }
//        free(d->vetor);
//        free(d);
//    }
//}
//
//
//// método por divisão com chave alfanumérica
//int hash(const char *chave, int m) {
//    int soma = 0;
//    for (int i = 0; chave[i] != '\0'; i++) {
//        soma += (i + 1) * chave[i];
//    }
//    return soma % m;
//}
//
//
//bool inserir(dicionario_t *d, char *chave, pessoa_t *valor) {
//    int indice = hash(chave, d->tamanho);
//    arvore_t *arvore = malloc(sizeof(arvore_t));
//    if (arvore == NULL) {
//        return false;
//    }
//    // strdup reserva memória para fazer a cópia da string. Presente em string.h padrão
//    // C23 https://en.cppreference.com/w/c/string/byte/strdup
//    arvore->chave = strdup(chave);
//    if (arvore->chave == NULL) {
//        free(arvore);
//        return false;
//    }
//    arvore->valor = valor;
//    if (d->vetor[indice] != NULL){
//        d->vetor[indice]->prox = arvore;
//        arvore->prox = NULL;
//
//    }
//        // se houver colisão é necessário usar uma lista encadeada
//    else{ arvore->prox = NULL;
//        d->vetor[indice] = arvore;}
//    return true;
//}
//
//
//pessoa_t *buscar(dicionario_t *d, char *chave) {
//    int indice = hash(chave, d->tamanho);
//    if (d->vetor[indice] != NULL) {
//        // TODO Abaixo só pega o primeiro elemento da lista encadeada
//        // é necessário percorrer a lista encadeada e não apenas o primeiro
//        // elemento
//
//        if (strcmp(d->vetor[indice]->chave, chave) == 0) {
//            return d->vetor[indice]->valor;
//        }
//    }
//    return NULL;
//}
//
//
//void imprimir_pessoa(dicionario_t *d, char *chave) {
//    pessoa_t *p = buscar(d, chave);
//    if (p != NULL) {
//        printf("CPF: %s\tNome: %s\tEmail: %s\n", p->cpf, p->nome, p->email);
//    } else {
//        printf("Pessoa com CPF %s não encontrada\n", chave);
//    }
//}
//
//int main(int argc, char **argv) {
//    dicionario_t *dicionario = criar_dicionario(5);
//    if (dicionario == NULL) {
//        printf("Não foi possível reservar memória\n");
//        exit(EXIT_FAILURE);
//    }
//    pessoa_t *p = malloc(sizeof(pessoa_t));
//    pessoa_t *j = malloc(sizeof(pessoa_t));
//    // https://en.cppreference.com/w/c/string/byte/strdup
//    // strdup reserva memória para fazer a cópia da string. Presente arvore padrão C23
//    p->cpf = strdup("123");
//    p->nome = strdup("Juca");
//    p->email = strdup("juca@example.ogr");
//    // pessoa extra para teste de colisão
//    j->cpf = strdup("4");
//    j->nome = strdup("Luca");
//    j->email = strdup("Luca@example.ogr");
//    inserir(dicionario, p->cpf, p);
//    imprimir_pessoa(dicionario, "123");
//    inserir(dicionario, j->cpf, j);
//    imprimir_pessoa(dicionario, "4");
//    destruir_dicionario(dicionario);
//    return 0;
//}