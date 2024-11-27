#ifndef PACIENTE_H
#define PACIENTE_H

#include "constantes.h"

typedef struct {
    long long cpf;
    char nome[MAX_NOME];
    char endereco[MAX_ENDERECO];
    char telefone[MAX_TELEFONE];
    char email[MAX_EMAIL];
} Paciente;

#endif //PACIENTE_H
