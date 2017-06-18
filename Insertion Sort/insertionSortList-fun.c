#include "insertionSortList.h"

struct _list
{
  int number;
};

struct elemento
{
    struct _list l;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento Elem;

Lista *cria_lista()
{
  Lista *l = calloc(1, sizeof(Lista));

  if (l != NULL)
    *l = NULL;

    return l;
}

int lista_vazia(Lista *l)
{

  if (l == NULL)
    return 1;
  else if (*l == NULL)
    return 1;
  else
    return 0;

}

int insere_comeco_lista(Lista *l, int n)
{
  if (l == NULL)
    return 0;

  Elem *node = calloc(1, sizeof(Elem));

  if (node == NULL)
    return 0;

  node->l.number = n;
  node->prox = (*l);
  node->ant = NULL;

  if (*l != NULL)
    (*l)->ant = node;

  *l = node;
  return 1;
}

void imprime_lista(Lista* l)
{
    if(l == NULL)
        return;

    Elem* no = *l;

    while(no != NULL)
    {
        if(no->prox == NULL)
          printf("%i", no->l.number);
        else
          printf("%i--", no->l.number);

        no = no->prox;
    }
}

void insertionSort(Lista *l)
{
    Elem *i, *aux;

    int key;

    for(aux = (*l)->prox; aux != NULL ; aux = aux->prox){
        key = aux->l.number;
        i = aux->ant;

        for (i = aux->ant; i != NULL && i->l.number > key; i = i->ant)
            i->prox->l.number = i->l.number;

        if(i == NULL)
            (*l)->l.number = key;
        else
            i->prox->l.number = key;
    }
}
