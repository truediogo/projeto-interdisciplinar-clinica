cmake_minimum_required(VERSION 3.28)
project(clinica C)

set(CMAKE_C_STANDARD 99)

add_executable(clinica main.c
        lib/validacoes.c
        lib/validacoes.h
        lib/estrutura.c
        lib/estrutura.h
        lib/constantes.h
        lib/paciente.h
        aplicacao.c
        aplicacao.h
)
