#include <stdio.h>
#include <stdlib.h>

#include "filaprocessos.h"

struct no {
    char nome[TAM];
    int valor;
    No* left;
    No* right;
};

struct escopo {
    No* raiz;
};

struct pilhaExecucao {

};

void executar(const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    // operações no arquivo...

    fclose(file);
}