////
//// Created by aluno on 13/03/24.
////
//#include <libprg/libprg.h>
//
//void criarlista(int **vetor, int tam){
//    *vetor = (int*) calloc(tam, sizeof(int));
//}
//
//void povoar(int *vetor, int tam){
//    srand(0);
//    for(int i=0; i < tam; i++){
//        vetor[i] = rand()%100;
//    }
//}
//
//
//
//int buscalinear(int *vetor, int tam, int elem){
//    for(int i = 0; i < tam; i++){
//        if (elem == vetor[i]){
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int bulisentinela(int *vetor, int tam, int elem){
//    vetor[tam] = elem;
//    int i = 0;
//    while(vetor[i] != elem){
//        i++;
//    }
//    if (i!=tam){
//        return 0;
//    }
//    return 1;
//}
//
//int bulisentinelaord(int *vetor, int tam, int elem){
//    vetor[tam] = elem;
//    int i = 0;
//    while(vetor[i] < elem){
//        i++;
//    }
//    if (i==tam && vetor[i] != x){
//        return 1;
//    }
//    return 0;
//}
//
//int buscabinaria(int *vetor, int tam, int elem){
//    int ini = 0, fim= tam;
//    int meio = 0;
//    while (ini <= fim){
//        meio = ini + (ini+fim)/2;
//        if (vetor[meio] = elem){
//            return 0
//        }
//        else if (vetor[meio] < elem){
//            ini = meio+1;
//        } else {fim = meio-1;}
//
//    }
//    return 1;
//}
//
//int buscabinariarec(int *vetor, int ini, int fim, int elem){
//    if (inicio <= fim){
//        int meio = inicio +(fim-inicio)/2;
//        if (vetor[meio] = elem){
//            return 0;
//        }
//        if (vetor[meio] > elem){
//            return buscabinariarec(vetor, ini, meio-1, elem)
//        }
//        return buscabinariarec(vetor, meio+1, fim, elem);
//    }
//    return 1;
//}