//
// Created by aluno on 03/07/24.
#include "libprg/libprg.h"
int* bubblesort(int *vetor, int tamanho, bool decrescente) {
    int i, j, aux;
    for (i = 0; i < tamanho; ++i) {
        for (j = 0; j < (tamanho - i -1); ++j) {
            if (decrescente == 0) {
                if (vetor[j] < vetor[j + 1]) {
                    aux = vetor[j];
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = aux;
                }
            }
            else{
                if (vetor[j] > vetor[j + 1]) {
                    aux = vetor[j];
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = aux;
                }
            }
        }
    }
    return vetor;
}

int* insertionsort(int *vetor, int tamanho, bool decrescente) {
    int i, j, chave;
    for (i = 1; i<tamanho; ++i){
        chave = vetor[i];
        j = i - 1;
        if (decrescente==0) {
            while ((j >= 0) && (vetor[j] < chave)) {
                vetor[j + 1] = vetor[j];
                j = j - 1;
            }
        }
        else{
            while ( (j>= 0) && (vetor[j] > chave)) {
                    vetor[j + 1] = vetor[j];
                    j = j - 1;
            }
        }
        vetor[j+1] = chave;
    }
    return vetor;
}

int* selectionsort(int *vetor, int tamanho, bool decrescente){
    int i, j, aux;
    for(i=0; i<=tamanho-2; ++i){
        int min = i;
        for(j=i+1; j <=tamanho-1; ++j) {
            if (decrescente == 0) {
                if (vetor[j] > vetor[min]) {
                    min = j;
                }
            } else {
                if (vetor[j] < vetor[min]) {
                    min = j;
                }
            }
        }
        if (i != min){
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
    return vetor;
}

int* povoarvetor(int tamanho){
    int *vetor= (int*) calloc(tamanho,sizeof(int));
    srand(1);
    for(int i =0; i < tamanho; ++i){
        vetor[i] = rand();
    }
    return vetor;
}
