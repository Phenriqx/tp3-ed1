#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void iniciaArvore(No **ppNo);
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

void adicionaPilha(PilhaExecucao *pPilha) {
    if (!pPilha)
        return;

    Escopo* e = criarEscopo();
    pPilha->topo = e;
    pPilha->n++;
}

void iniciaArvore(No **ppNo) {
    *ppNo = NULL;
}

void destroiArvore(No **ppNo) {
    if (!*ppNo || !ppNo)
        return;

    destroiArvore(&(*ppNo)->left);
    destroiArvore(&(*ppNo)->right);
    free(*ppNo);
    *ppNo = NULL;
}

void executar(const char *nomeArquivo, PilhaExecucao* pPilha) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    do {
        int code = lePalavras(file);

        switch (code) {
            // begin
            case 1:
                adicionaPilha(pPilha);
                break;
            // end
            case 2:
                break;
            // var
            case 3:
                break;
            // print
            case 4: 
                break;
        }

    } while (lePalavras(file) != EOF);

    fclose(file);
}

// lê uma palavra no arquivo e retorna um dado valor com base na palavra. isso se deve ao switch nao lidar com strings.
int lePalavras(FILE *file) {
    char palavra[TAM];
    if (fscanf(file, "%s", palavra) == EOF)
        return EOF;

    if (strcmp(palavra, "begin") == 0)
        return 1;
    if (strcmp(palavra, "end") == 0)
        return 2;
    if (strcmp(palavra, "var") == 0)
        return 3;
    if (strcmp(palavra, "print") == 0)
        return 4;
}