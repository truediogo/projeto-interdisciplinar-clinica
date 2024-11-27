#include <string.h>
#include <ctype.h>

int validarCPF(long long cpf) {
    if (cpf <= 0) return 0;

    int digitos[11];
    long long temp = cpf;
    for (int i = 10; i >= 0; i--) {
        digitos[i] = temp % 10;
        temp /= 10;
    }

    int todosIguais = 1;
    for (int i = 1; i < 11; i++) {
        if (digitos[i] != digitos[0]) {
            todosIguais = 0;
            break;
        }
    }
    if (todosIguais) return 0;

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += digitos[i] * (10 - i);
    }

    int dv1 = 11 - (soma % 11);
    if (dv1 > 9) dv1 = 0;
    if (dv1 != digitos[9]) return 0;

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += digitos[i] * (11 - i);
    }
    int dv2 = 11 - (soma % 11);
    if (dv2 > 9) dv2 = 0;
    if (dv2 != digitos[10]) return 0;

    return 1;
}

int validarEmail(const char* email) {
    if (strlen(email) == 0) return 0;

    const char* arroba = strchr(email, '@');
    if (!arroba) return 0;

    if (arroba == email || *(arroba + 1) == '\0') return 0;

    const char* ponto = strchr(arroba, '.');
    if (!ponto || *(ponto + 1) == '\0') return 0;

    return 1;
}

int validarTelefone(const char* telefone) {
    if (strlen(telefone) == 0) return 0;

    int numDigitos = 0;
    for (int i = 0; telefone[i]; i++) {
        if (isdigit(telefone[i])) {
            numDigitos++;
        }
    }

    return (numDigitos == 10 || numDigitos == 11);
}

int validarCampoTexto(const char* texto, int tamanhoMinimo) {
    if (!texto || strlen(texto) < tamanhoMinimo) return 0;
    return 1;
}
