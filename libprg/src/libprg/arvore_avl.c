//
// Created by User on 28/08/2024.
//
#include <libprg/libprg.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

typedef struct no_avl {
    int valor;
    int altura; // altura da subárvore
    struct no_avl *esquerda;
    struct no_avl *direita;
} no_avl_t;


no_avl_t *criar_no_avl(int valor){
    no_avl_t *no = (no_avl_t *) malloc(sizeof(no_avl_t));
    no->valor = valor;
    no->esquerda =NULL;
    no->direita = NULL;
    no->altura = 1;
    return no;
}

no_avl_t *plantar_avl(int tam){
    srand(time(NULL));
    no_avl_t *arvore = criar_no_avl((rand()%100)+1);
    for (int i = 0; i < tam-1; i++){
        int valor = (rand()%100)+1;
        arvore = inserir(arvore, valor);
    }
    return arvore;
}

void destruir_no_avl(no_avl_t *no) {
    if (no != NULL) {
        destruir_no(no->esquerda);
        destruir_no(no->direita);
        free(no);
    }
}

bool busca_avl(no_avl_t *raiz, int valor){
    if (raiz == NULL) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca_avl(raiz->esquerda, valor);
    return busca_avl(raiz->direita, valor);
}

int maiorarvore_avl(no_avl_t *no){
    while (no->direita != NULL){
        no = no->direita;
    }
    return no->valor;
}

int menorarvore_avl(no_avl_t *no){
    while (no->esquerda != NULL){
        no = no->esquerda;
    }
    return no->valor;
}

void inorder_avl(no_avl_t *no){
    if (no!= NULL){
        inorder_avl(no->esquerda);
        printf("%d ", no->valor);
        inorder_avl(no->direita);
    }
}

void preorder_avl(no_avl_t *no){
    if (no!= NULL){
        printf("%d ", no->valor);
        preorder_avl(no->esquerda);
        preorder_avl(no->direita);
    }
}

void posorder_avl(no_avl_t *no){
    if (no != NULL){
        posorder_avl(no->esquerda);
        posorder_avl(no->direita);
        printf("%d ", no->valor);
    }
}



int altura(no_avl_t *v) {
    if (v == NULL) {
        return 0;
    } else {
        return v->altura;
    }
}
int fator_balanceamento(no_avl_t *v) {
    if (v == NULL) {
        return 0;
    } else {
        return altura(v->esquerda) - altura(v->direita);
    }
}

no_avl_t *rotacao_esquerda(no_avl_t *v) {
// u é (7) na figura ao lado
    no_avl_t *u = v->direita;
// filho direito de v será o filho esquerdo de u (8)
    v->direita = u->esquerda;
// filho esquerdo de u será v (6)
    u->esquerda = v;
// atualiza a altura de v
    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;
// atualiza a altura de u
    u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;
// retorna o novo nó raiz da subárvore
    return u;
}

no_avl_t *rotacao_direita(no_avl_t *v) {
// u é (7) na figura ao lado
    no_avl_t *u = v->esquerda;
// filho direito de v será o filho esquerdo de u (8)
    v->esquerda = u->direita;
// filho esquerdo de u será v (6)
    u->direita = v;
// atualiza a altura de v
    v->altura = max(altura(v->direita), altura(v->esquerda)) + 1;
// atualiza a altura de u
    u->altura = max(altura(u->direita), altura(u->esquerda)) + 1;
// retorna o novo nó raiz da subárvore
    return u;
}

no_avl_t *rotacao_dupla_esquerda(no_avl_t *v) {
    // rotação simples à esquerda no filho esquerdo de v
    v->direita = rotacao_direita(v->direita);
    // rotação simples à direita em v
    return rotacao_esquerda(v);
}

// v é o nó desregulado (20) na figura ao lado
no_avl_t *rotacao_dupla_direita(no_avl_t *v) {
    // rotação simples à esquerda no filho esquerdo de v
    v->esquerda = rotacao_esquerda(v->esquerda);
    // rotação simples à direita em v
    return rotacao_direita(v);
}

no_avl_t *balancear(no_avl_t *v) {
    int fb = fator_balanceamento(v);

    if (fb > 1){// nó desregulado tem filho desregulado à esquerda
        if (fator_balanceamento(v->esquerda) > 0) {
            // caso esquerda−esquerda
            return rotacao_direita(v);
        } else {
            // caso esquerda−direita
            return rotacao_dupla_direita(v);
        }
    } else if (fb < -1) { // nó desregulado tem filho desregulado à direita
        if (fator_balanceamento(v->direita) < 0) {
            // caso direita−direita
            return rotacao_esquerda(v);
        } else {
            // caso direita−esquerda
            return rotacao_dupla_esquerda(v);
        }
    }
    return v;
}

no_avl_t *inserir(no_avl_t *v, int valor) {
    if (v == NULL) {
        v = criar_no_avl(valor);
    } else if (valor < v->valor) {
        v->esquerda = inserir(v->esquerda, valor);
    } else if (valor > v-valor) {
        v->direita = inserir(v->direita, valor);
    }
    v->altura= 1 + max(altura(v->esquerda), altura(v->direita));
    v = balancear(v); // é necessário balancear após cada inserção
    return v;
}

no_avl_t *removerb(no_avl_t *v, int valor) {
    if (v == NULL) { return NULL;
    } else if (valor < v->valor) {
        v->esquerda = removerb(v->esquerda, valor);
    } else if (valor > v->valor) {
        v->direita = removerb(v->direita, valor);
    } else { // valor == v−>valor
        if (v->esquerda == NULL || v->direita == NULL) { // nó folha ou nó com um filho
            if(v->esquerda != NULL){
                arvore_t *aux = v->esquerda;
                destruir_no(v->esquerda);
                v = aux;
                destruir_no(aux);
            } else if(v->direita != NULL){
                v = v->direita;
                v->direita;
            }else {
                destruir_no(v);
            }

        } else{ // nó com dois filhos
            no_avl_t *aux = v->esquerda;
            while (aux->direita != NULL) {
                aux = aux->direita;
            }
            v->valor = aux->valor;
            v->esquerda = removerb(v->esquerda, aux->valor);
        }
    }
    if (v != NULL) {
        v->altura = 1 + max(altura(v->esquerda), altura(v->direita));
        v = balancear(v); // é necessário balancear após cada remoção
    }
    return v;
}