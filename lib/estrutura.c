#include <string.h>

#include "estrutura.h"

NoArvore* criarNoArvore(long long cpf, int num_registro) {
    NoArvore* novo = (NoArvore*)malloc(sizeof(NoArvore));
    novo->cpf = cpf;
    novo->num_registro = num_registro;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

NoArvore* inserirArvore(NoArvore* raiz, long long cpf, int num_registro) {
    if (raiz == NULL) {
        return criarNoArvore(cpf, num_registro);
    }

    if (cpf < raiz->cpf) {
        raiz->esquerda = inserirArvore(raiz->esquerda, cpf, num_registro);
    }
    else if (cpf > raiz->cpf) {
        raiz->direita = inserirArvore(raiz->direita, cpf, num_registro);
    }

    return raiz;
}

NoArvore* buscarArvore(NoArvore* raiz, long long cpf) {
    if (raiz == NULL || raiz->cpf == cpf) {
        return raiz;
    }

    if (cpf < raiz->cpf) {
        return buscarArvore(raiz->esquerda, cpf);
    }

    return buscarArvore(raiz->direita, cpf);
}

NoLista* criarNoLista(char* nome, int num_registro) {
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    strcpy(novo->nome, nome);
    novo->num_registro = num_registro;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

NoLista* inserirListaOrdenada(NoLista* inicio, char* nome, int num_registro) {
    NoLista* novo = criarNoLista(nome, num_registro);

    if (inicio == NULL) {
        return novo;
    }

    NoLista* atual = inicio;

    while (atual->proximo != NULL && strcmp(nome, atual->nome) > 0) {
        atual = atual->proximo;
    }

    if (strcmp(nome, atual->nome) <= 0) {
        if (atual->anterior == NULL) {
            novo->proximo = atual;
            atual->anterior = novo;
            return novo;
        } else {
            novo->anterior = atual->anterior;
            novo->proximo = atual;
            atual->anterior->proximo = novo;
            atual->anterior = novo;
        }
    } else {
        novo->anterior = atual;
        novo->proximo = atual->proximo;
        if (atual->proximo != NULL) {
            atual->proximo->anterior = novo;
        }
        atual->proximo = novo;
    }

    return inicio;
}

NoLista* removerDaLista(NoLista* inicio, int num_registro) {
    NoLista* atual = inicio;

    while (atual != NULL) {
        if (atual->num_registro == num_registro) {
            if (atual->anterior == NULL) {
                NoLista* proximo = atual->proximo;
                if (proximo != NULL) {
                    proximo->anterior = NULL;
                }
                free(atual);
                return proximo;
            } else {
                atual->anterior->proximo = atual->proximo;
                if (atual->proximo != NULL) {
                    atual->proximo->anterior = atual->anterior;
                }
                free(atual);
                return inicio;
            }
        }
        atual = atual->proximo;
    }
    return inicio;
}

NoArvore* encontrarMenor(NoArvore* node) {
    NoArvore* atual = node;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

NoArvore* removerDaArvore(NoArvore* raiz, long long cpf, int* num_registro) {
    if (raiz == NULL) return raiz;

    if (cpf < raiz->cpf) {
        raiz->esquerda = removerDaArvore(raiz->esquerda, cpf, num_registro);
    }
    else if (cpf > raiz->cpf) {
        raiz->direita = removerDaArvore(raiz->direita, cpf, num_registro);
    }
    else {
        *num_registro = raiz->num_registro;

        if (raiz->esquerda == NULL) {
            NoArvore* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL) {
            NoArvore* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        NoArvore* temp = encontrarMenor(raiz->direita);
        raiz->cpf = temp->cpf;
        raiz->num_registro = temp->num_registro;
        raiz->direita = removerDaArvore(raiz->direita, temp->cpf, num_registro);
    }
    return raiz;
}

