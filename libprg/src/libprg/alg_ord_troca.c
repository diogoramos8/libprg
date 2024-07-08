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

int* insertionsort(int *vetor, int tamanho) {
    int i, j, chave;
    for (i = 1; i<tamanho-1; ++i){
        chave = vetor[i];
        j = i - 1;
        while ( (j>= 0) && (vetor[j] > chave)){
            vetor[j+1] = vetor[j];
            j = j-1;
        }
        vetor[j+1] = chave;
    }
    return vetor;
}

