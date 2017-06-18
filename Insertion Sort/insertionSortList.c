#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertionSortList-fun.c"
#include "insertionSortList.h"

int main()
{
  int n, i, j, c = 0, check;
  srand(time(NULL));
  clock_t c0, c1;

  scanf("%i", &n);

  Lista *p = cria_lista();
  int reser[n];

  for (i = 0; i < n;)
  {
    check = rand() % n;

    for(j = 0; j <= i; j++)
      if (check == reser[j])
        c++;

      if (c == 0)
      {
        reser[i] = check;
        insere_comeco_lista(p, check);
        i++;
      }

      c = 0;
  }

  printf("Desordenado: ");
  imprime_lista(p);

  c0 = clock();
  insertionSort(p);
  c1 = clock();

  printf("\nOrdenado:    ");
  imprime_lista(p);
  printf("\n");

  printf("\nTempo de execução: %lf\n", (double) (c1 - c0)/CLOCKS_PER_SEC);

  return 0;
}
