#ifndef VALIDACOES_H
#define VALIDACOES_H

#include <string.h>
#include <ctype.h>

int validarCPF(long long cpf);
int validarEmail(const char* email);
int validarTelefone(const char* telefone);
int validarCampoTexto(const char* texto, int tamanhoMinimo);

#endif //VALIDACOES_H
