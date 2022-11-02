#include <stdlib.h>
#include <stdio.h>
#include "ilist.h"
#include "hashtable_ed.h"

int THED_Hash(THED *HT, int chave)
{
    return chave % HT->m;
}

THED *THED_Criar(int m, int alloc_step)
{
    THED *new = malloc(sizeof(THED));
    new->t = malloc(sizeof(ILIST *) * m);
    for (int i = 0; i < m; i++)
    {
        new->t[i] = ILIST_Criar(alloc_step);
    }
    new->m = m;
    new->n = 0;
    return new;
}

void THED_Inserir(THED *HT, int chave, int valor)
{
    int h = THED_Hash(HT, chave);
    ILIST_Inserir(HT->t[h], chave, valor);
    // HT->n++;
}

void THED_Remover(THED *HT, int chave)
{
}

INOH *THED_Buscar(THED *HT, int chave)
{
}

void THED_Imprimir(THED *HT)
{
    for (int i = 0; i < HT->m; i++)
    {
        printf("t[%d]: ", i);
        ILIST_Imprimir(HT->t[i], 0);
    }
}

size_t THED_N(THED *HT)
{
}

ILIST *THED_Chaves(THED *HT)
{
}

void THED_Destruir(THED *HT)
{
}
