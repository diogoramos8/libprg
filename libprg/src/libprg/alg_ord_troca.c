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

