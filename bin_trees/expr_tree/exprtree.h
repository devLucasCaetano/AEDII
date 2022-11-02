#pragma once

typedef enum ExprTreeTipoNo
{
    ETTN_OP,
    ETTN_CONST
} ExprTreeTipoNo;

typedef struct ExprTree
{
    struct ExprTree *esq;
    struct ExprTree *dir;
    int dado;
    ExprTreeTipoNo tipo_no;
    char op;
    int valor;
} ExprTree;

ExprTree *ET_Criar(int dado, ExprTree *e, ExprTree *d);
void ET_Destruir(ExprTree *A);
