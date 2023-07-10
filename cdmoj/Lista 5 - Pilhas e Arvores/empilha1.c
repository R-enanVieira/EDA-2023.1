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
