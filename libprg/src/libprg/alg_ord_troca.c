//
// Created by aluno on 03/07/24.
#include "libprg/libprg.h"

void trocarposicao(int *vetor,int a, int b);

void trocarposicao(int *vetor, int a, int b){
    int aux = vetor[b];
    vetor[b] = vetor[a];
    vetor[a] = aux;
}

int* bubblesort(int *vetor, int tamanho, bool decrescente) {
    int i, j, aux;
    for (i = 0; i < tamanho; ++i) {
        for (j = 0; j < (tamanho - i -1); ++j) {
            if (decrescente == 0) {
                if (vetor[j] < vetor[j + 1]) {
                    trocarposicao(vetor,j+1, j);
                }
            }
            else{
                if (vetor[j] > vetor[j + 1]) {
                    trocarposicao(vetor,j+1, j);
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
            trocarposicao(vetor,min, i);
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

int* merge(int *vetor, int esquerda, int meio, int direita){
    int aux[direita - esquerda +1];
    int i = esquerda, j = meio+1, k = 0;
    while(i<= meio && j<= direita){
        if(vetor[i] <= vetor[j]){
            aux[k] = vetor[i];
            i++;
        } else {
                aux[k] = vetor[j];
                j++;
        }
        k++;
    }
    while ( i<= meio){
        aux[k] = vetor[i];
        i++;
        k++;
    }
    while ( j<= direita) {
        aux[k] = vetor[j];
        j++;
        k++;
    }
    for (i = esquerda; i <= direita; i++){
        vetor[i] = aux [i - esquerda];
    }
}

int* mergesort(int *vetor, int esquerda, int direita){
    if( esquerda < direita){
        int meio = esquerda + (direita - esquerda)/2; //divisão
        //ordene as duas metades(conquista)
        mergesort(vetor, esquerda, meio);
        mergesort(vetor, meio+1, direita);
        //mescle as metades (combinação)
        merge(vetor, esquerda, meio, direita);
    }
    return  vetor;
}

int particiona(int *vetor, int inicio, int fim){
    int pivo = vetor[fim];
    int i = inicio -1;
    int aux;
        for (int j = inicio; j < fim; j++){
            if (vetor[j] <= pivo){
                i++;
                trocarposicao(vetor,i, j);
            }
        }
        i++;
    trocarposicao(vetor,i, fim);
    return i;
}

int* quicksort(int *vetor, int inicio, int fim){
    if (inicio < fim){
        int p = particiona(vetor, inicio, fim);
        quicksort(vetor, inicio, p-1);
        quicksort(vetor, p+1, fim);
    }
    return vetor;
}
