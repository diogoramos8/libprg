//
// Created by aluno on 31/07/24.
//
#include <libprg/libprg.h>

typedef struct arvore {
    int valor;
    struct arvore *esquerda;
    struct arvore *direita;
} arvore_t;

typedef struct fila{
    struct arvore *vetor;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
} fila_t;

arvore_t *criar_no(int valor){
    arvore_t *no = (arvore_t *) malloc(sizeof(arvore_t));
    no->valor = valor;
    no->esquerda =NULL;
    no->direita = NULL;
    return no;
}

arvore_t *plantar(int tam){
    srand(time(NULL));
    arvore_t *arvore = criar_no(rand()%100);
    for (int i = 0; i < tam-1; i++){
        int valor = rand()%100;
        arvore = inserir_valor(arvore, valor);
    }
    return arvore;
}
//TODO arrumar plantar
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

void inorder(arvore_t *no){
    if (no!= NULL){
        inorder(no->esquerda);
        printf("%d\n", no->valor);
        inorder(no->direita);
    }
}

void preorder(arvore_t *no){
    if (no!= NULL){
        printf("%d", no->valor);
        inorder(no->esquerda);
        inorder(no->direita);
    }
}

void posorder(arvore_t *no){
    if (no != NULL){
        inorder(no->esquerda);
        inorder(no->direita);
        printf("%d", no->valor);
    }
}

fila_t* criarfilaarvore(int capacidade){
    fila_t* fila = (fila_t*) calloc(capacidade, sizeof(fila_t));
    fila->vetor = (arvore_t *) calloc(capacidade, sizeof(arvore_t));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    return fila;
}


bool enfileirararvore(fila_t *fila, arvore_t *elemento){
    bool full = ischeiafila(fila);
    if (full != true){
        fila->vetor[fila->fim] = *elemento;
        fila->fim++;
        if (fila->fim > fila->capacidade){fila->fim = 0;}
        fila->tamanho++;
        return true;
    }
    return false;
}
arvore_t desinfileirarvore(fila_t *fila){
        fila->inicio++;
        if (fila->inicio > fila->capacidade){
            fila->inicio = 0;
            fila->tamanho--;
            return fila->vetor[fila->capacidade];

            ;}
        fila->tamanho--;
        return fila->vetor[fila->inicio-1];
}



void percurso_largura(arvore_t *no, fila_t *fila){
    while(no !=NULL) {
        printf("%d", no->valor);
        if (no->esquerda != NULL) {
            enfileirararvore(fila, no->esquerda);
        }
        if (no->direita != NULL) {
            enfileirararvore(fila, no->direita);
        }
        *no = desinfileirarvore(fila);
    }
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
