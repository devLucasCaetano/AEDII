#include <stdio.h>
#include <stdlib.h>
#include "arn.h"

ARN ARN_Criar(int dado)
{
    ARN novo;

    novo = malloc(sizeof(struct ARN));
    novo->cor = C_VERMELHO;
    novo->dado = dado;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

void rot_esq(ARN *A)
{
    ARN h;
    ARN x;
    h = *A;
    x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

void rot_dir(ARN *A)
{
    ARN h;
    ARN x;
    h = *A;
    x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

int eh_vermelho(ARN A)
{
    if (A == NULL)
        return 0;

    return A->cor == C_VERMELHO ? 1 : 0;
}

void inverter_cores(ARN h)
{
    h->cor = C_VERMELHO;
    h->esq->cor = C_PRETO;
    h->dir->cor = C_PRETO;
}

void ARN_Imprimir(ARN A, int nivel, char lado)
{
    int i;
    for (i = 0; i < nivel; i++)
    {
        printf("--> ");
    }
    if (A == NULL)
    {
        printf("(%c) NONE\n", lado);
    }
    else
    {
        printf("(%c) %c [%s]\n", lado, (char)A->dado, A->cor == C_VERMELHO ? "V" : "P");
        ARN_Imprimir(A->esq, nivel + 1, 'e');
        ARN_Imprimir(A->dir, nivel + 1, 'd');
    }
}

void ARN_Inserir(ARN *A, int dado)
{
    ARN h;
    h = *A;
    if (h == NULL)
    {
        *A = ARN_Criar(dado);
        (*A)->cor = C_PRETO;
        return;
    }

    if (eh_vermelho(h->esq) && eh_vermelho(h->dir))
    {
        inverter_cores(h);
    }

    if (dado < h->dado)
    {
        ARN_Inserir(&h->esq, dado);
    }
    else if (dado > h->dado)
    {
        ARN_Inserir(&h->dir, dado);
    }

    if (eh_vermelho(h->dir) && !eh_vermelho(h->esq))
    {
        rot_esq(A);
    }
    if (eh_vermelho(h->esq) && eh_vermelho(h->esq->esq))
    {
        rot_dir(A);
    }
}
