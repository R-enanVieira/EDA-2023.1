#include <stddef.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2) {
  celula *aux;
  aux = l->prox;
  while(aux != NULL) {
    if(aux->dado%2 != 0) {
      l1->prox = aux;
      l1->prox->dado = aux->dado;
      l1 = aux;
    }
    else {
      l2->prox = aux;
      l2->prox->dado = aux->dado;
      l2 = aux;
    }
    aux = aux->prox;
  }
  l1->prox = NULL;
  l2->prox = NULL;
}


