#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int vet[], int n)
{
   int i, chave, j;

   for (i = 1; i < n; i++)
   {
       chave = vet[i];
       j = i-1;

       while (j >= 0 && vet[j] > chave)
       {
           vet[j+1] = vet[j];
           j--;
       }
       vet[j+1] = chave;
   }
}

int main()
{
  int n, i, j, c = 0, check;
  clock_t c0, c1;
  srand(time(NULL));

  scanf("%i", &n);

  int vet[n], reser[n];

  for (i = 0; i < n;)
  {
    check = rand() % n;

    for(j = 0; j <= i; j++)
      if (check == reser[j])
        c++;

      if (c == 0)
      {
        reser[i] = check;
        vet[i] = check;
        i++;
      }

      c = 0;
  }

  printf("Desordenado: ");
  for(i = 0; i < n; i++)
  {
    if (i == (n-1))
      printf("%i", vet[i]);
    else
      printf("%i--", vet[i]);
  }

  c0 = clock();
  insertionSort(vet, n);
  c1 = clock();

  printf("\nOrdenado:    ");
  for(i = 0; i < n; i++)
  {
    if (i == (n-1))
      printf("%i", vet[i]);
    else
      printf("%i--", vet[i]);
  }

  printf("\n");

  printf("\nTempo de execução: %lf\n", (double) (c1 - c0)/CLOCKS_PER_SEC);

  return 0;
}
