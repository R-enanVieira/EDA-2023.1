#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int desenfileira (celula *f, int *y) {
  if(f->prox == f) return 0;
  celula *lixo;
  lixo = f->prox;
  f->prox = lixo->prox;
  *y = lixo->dado;
  free(lixo);
  return 1;
}
