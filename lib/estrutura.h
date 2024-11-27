#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <stdio.h>
#include <stdlib.h>


#include "constantes.h"

typedef struct NoArvore {
    long long cpf;
    int num_registro;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;

typedef struct NoLista {
    char nome[MAX_NOME];
    int num_registro;
    struct NoLista* anterior;
    struct NoLista* proximo;
} NoLista;

NoArvore* criarNoArvore(long long cpf, int num_registro);
NoArvore* inserirArvore(NoArvore* raiz, long long cpf, int num_registro);
NoArvore* buscarArvore(NoArvore* raiz, long long cpf);
NoArvore* removerDaArvore(NoArvore* raiz, long long cpf, int* num_registro);
NoArvore* encontrarMenor(NoArvore* node);

NoLista* criarNoLista(char* nome, int num_registro);
NoLista* inserirListaOrdenada(NoLista* inicio, char* nome, int num_registro);
NoLista* removerDaLista(NoLista* inicio, int num_registro);

#endif //ESTRUTURA_H
