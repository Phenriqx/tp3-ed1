#include <stdio.h>
#include <stdlib.h>

#include "filaprocessos.h"

struct registro {
    char nome[TAM];
    char valor[TAM];
};

struct no {
    Registro reg;
    No* left;
    No* right;
};

struct escopo {
    No* raiz;
    Escopo *next;
    int n;
};

struct pilhaExecucao {
    Escopo *topo;
    int n;
};

No* noCria(Registro reg);
void destroiArvore(No **ppNo);

PilhaExecucao* criarPilha() {
    PilhaExecucao* pilha =(PilhaExecucao* ) malloc(sizeof(PilhaExecucao));
    if (pilha) {
        pilha->n = 0;
        pilha->topo = NULL;
    }

    return pilha;
}

void destroiPilha(PilhaExecucao **ppPilha) {
    if (!*ppPilha || !ppPilha)
        return;

    destroiArvore(&(*ppPilha)->topo);
    free(*ppPilha);
    *ppPilha = NULL;
}

Escopo* criarEscopo() {
    Escopo* escopo = (Escopo* ) malloc(sizeof(Escopo));
    if (escopo) {
        escopo->n = 0;
        escopo->next = NULL;
        escopo->raiz = NULL;
    }

    return escopo;
}

No* noCria(Registro reg) {
    No* pNo = (No *) malloc(sizeof(No));
    if (pNo) {
        pNo->reg = reg;
        pNo->left = NULL;
        pNo->right = NULL;
    }

    return pNo;
}

void adicionaPilha(PilhaExecucao *pPilha, Escopo *pEscopo) {

}

void destroiArvore(No **ppNo) {
    if (!*ppNo || !ppNo)
        return;

    destroiArvore(&(*ppNo)->left);
    destroiArvore(&(*ppNo)->right);
    free(*ppNo);
    *ppNo = NULL;
}

void executar(const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    // operações no arquivo...

    fclose(file);
}
