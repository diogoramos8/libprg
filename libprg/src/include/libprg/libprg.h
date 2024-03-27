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


//lista
void criarlista(int **vetor, int tam);
void povoar(int *vetor, int tam);


int buscalinear(int *vetor,int tam, int elem);
int bulisentinela(int *vetor, int tam, int elem);
int bulisentinelaord(int *vetor, int tam, int elem);

int buscabinariaite(int *vetor, int tam, int elem);
int buscabinariarec(int *vetor, int ini, int fim, int elem);
//fila
fila_t *fila criarfila(int capacidade);
bool enfileirar(fila_t *fila, int elemento);
int desinfileirar(fila_t *fila);
int getinicio(fila_t *fila);
int getfinal(fila_t *fila);
int gettamanho(fila_t *fila);
bool isvazia(fila_t *fila);
bool ischeia(fila_t *fila);
#endif