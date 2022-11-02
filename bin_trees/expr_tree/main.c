#include <stdio.h>
#include <stdlib.h>
#include "shunting_yard.h"
#include "exprtree.h"
#include "etstack.h"
#include "cstack.h"

int avaliaExpressao(ExprTree *et)
{
  int e, d;
  if (et == NULL)
    return 0;

  e = avaliaExpressao(et->esq);
  d = avaliaExpressao(et->dir);

  if (et->tipo_no == ETTN_CONST)
    return et->valor;
  else
  {
    switch (et->op)
    {
    case '+':
      return e + d;
    case '-':
      return e - d;
    case '*':
      return e * d;
    case '/':
      return e / d;
    case '^':
      return e ^ d;
    }
  }
}

int main(int argc, char **argv)
{
  ExprTree *arv_expressao;

  char *infixa = argv[1];
  char *posfixa = shunting_yard(infixa);

  printf("Infixa:%d \r Fixa:%d \n", infixa, posfixa);

  arv_expressao = ConstruirArvExpressao(posfixa);

  int resultado = avaliaExpressao(arv_expressao);

  free(posfixa);
}
