#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "bubbleSort.h"
#include "bubbleSort-fun.c"

int main()
{
  int n;

  printf("Quantos alunos deseja cadastrar?\nResp: ");
  scanf("%i", &n);

  tp_aluno Alunos[n];

  entrada_dados(Alunos, n);

  bubbleSort(Alunos, n);

  imprime_estrutura(Alunos, n);

  return 0;
}
