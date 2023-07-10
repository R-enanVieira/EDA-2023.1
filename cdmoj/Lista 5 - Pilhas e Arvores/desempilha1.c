#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int desempilha(celula *p, int *y) {
  if(p->prox == NULL) return 0;
  celula *aux;
  aux = p->prox;
  *y = aux->dado;
  p->prox = aux->prox;
  free(aux);
  return 1;
}
