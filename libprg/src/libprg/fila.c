#include <libprg/libprg.h>

typedef struct fila{
    int *vetor;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
} fila_t;

fila_t* criarfila(int capacidade){
    fila_t* fila = (fila_t*) calloc(capacidade, sizeof(fila_t));
    fila->vetor = (int*) calloc(capacidade, sizeof(int));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    return fila;
}
bool ischeiafila(fila_t *fila){
    if (fila->tamanho == fila->capacidade){return true;}
    return false;
}
bool isvaziafila(fila_t *fila){
    if (fila->tamanho == 0){return true;}
    return false;
}

int getinicio(fila_t *fila){
    return fila->vetor[fila->inicio];
}
int getfinal(fila_t *fila){
    return fila->vetor[fila->fim-1];
}
int gettamanho(fila_t *fila){
    return fila->tamanho;
}
bool enfileirar(fila_t *fila, int elemento){
    bool full = ischeiafila(fila);
    if (full != true){
        fila->vetor[fila->fim] = elemento;
        fila->fim++;
        if (fila->fim > fila->capacidade){fila->fim = 0;}
        fila->tamanho++;
        return true;
    }
    return false;
}
int desinfileirar(fila_t *fila){
    bool empty = isvaziafila(fila);
    if (empty != true){
        fila->inicio++;
        if (fila->inicio > fila->capacidade){
            fila->inicio = 0;
            fila->tamanho--;
            return fila->vetor[fila->capacidade];

        ;}
        fila->tamanho--;
        return fila->vetor[fila->inicio-1];
    }
    printf("A fila ja esta vazia\n");
    return -1;
}

