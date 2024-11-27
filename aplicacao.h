#ifndef APLICACAO_H
#define APLICACAO_H

#include "lib/estrutura.h"
#include "lib/paciente.h"

int salvarPaciente(Paciente* paciente);
Paciente lerPaciente(int num_registro);

void carregarDados(NoArvore** raiz, NoLista** inicio);

void adicionar(NoArvore** raiz, NoLista** inicio);
void procurar(NoArvore* raiz);
void excluir(NoArvore** raiz, NoLista** inicio);
void relatorio(NoLista* inicio);
void alterar(NoArvore* raiz, NoLista** inicio);

#endif //APLICACAO_H
