#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int empilha (celula *p, int x) {
  celula *novo;
  novo = malloc(sizeof(celula));
  if(novo == NULL) return 0;
  novo->prox = p->prox;
  p->prox = novo;
  novo->dado = x;
  return 1;
}

int desempilha(celula *p, int *y) {
  if(p->prox == NULL) return 0;
  celula *aux;
  aux = p->prox;
  *y = aux->dado;
  p->prox = aux->prox;
  free(aux);
  return 1;
}
