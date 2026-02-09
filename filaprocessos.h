#ifndef FILAPROCESSOS_H
#define FILAPROCESSOS_H

#include <stdbool.h>

#define TAM 32

/*
A pilha de execução é uma pilha de escopos
O escopo é representado por uma árvore binária de busca
A árvore armazena o nome e valor de uma variável declarada dentro de um escopo.
*/
typedef struct pilhaExecucao PilhaExecucao;
typedef struct escopo Escopo;
typedef struct no No;
typedef struct registro Registro;

PilhaExecucao* criarPilha();
void destroiPilha(PilhaExecucao **ppPilha);
void adicionaPilha();
void executar(const char *nomeArquivo);

Escopo* criarEscopo();
void destroiEscopo(Escopo **ppEscopo);
// void adicionaVar();

#endif