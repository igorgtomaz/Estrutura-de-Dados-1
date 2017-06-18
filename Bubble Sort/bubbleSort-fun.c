#include "bubbleSort.h"

struct aluno {
   char nome[50];
   long long int cpf;
};

void entrada_dados(tp_aluno *aluno, int n)
{
  int i, j;

  for (i = 0; i < n; i++)
  {
    __fpurge(stdin);
    printf("\nDigite o nome do aluno %i: ", (i+1));
    fgets(aluno[i].nome, 50, stdin);
    for (j = 0; j < 50; j++)
      if (aluno[i].nome[j] == '\n')
        aluno[i].nome[j] = '\0';

    printf("Digite o cpf do aluno %i: ", (i+1));
    scanf("%lli", &aluno[i].cpf);
  }
}

void imprime_estrutura(tp_aluno *aluno, int n)
{
  int i;

  for (i = 0; i < n; i++)
    printf("\nAluno %i\nNome: %s.\nCPF: %lli.\n", (i+1), aluno[i].nome, aluno[i].cpf);
}

void troca(tp_aluno *x, tp_aluno *y)
{
  tp_aluno aux;

  strcpy(aux.nome, x->nome);
  aux.cpf = x->cpf;
  strcpy(x->nome, y->nome);
  x->cpf = y->cpf;
  strcpy(y->nome, aux.nome);
  y->cpf = aux.cpf;
}

void bubbleSort(tp_aluno *aluno, int n)
{
   int i, j, ret;

   for (i = 0; i < n-1; i++)
     for (j = 0; j < n-i-1; j++)
     {
       ret = strcoll(&aluno[j].nome[0], &aluno[j+1].nome[0]);
        if (ret > 0)
        troca(&aluno[j], &aluno[j+1]);
        else if (ret == 0)
        {
          if (aluno[j].cpf > aluno[j+1].cpf)
            troca(&aluno[j], &aluno[j+1]);
        }
     }
}
