#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void enfileira(celula **f, int x) {
  celula *nova ;
  nova = malloc(sizeof(celula));
  nova->prox = (*f)->prox;
  nova->dado = x;
  (*f)->prox = nova;
}

int desenfileira (celula *f, int *y) {
  if(f->prox == f) return 0;
  celula *lixo;
  lixo = f->prox;
  f->prox = lixo->prox;
  *y = lixo->dado;
  free(lixo);
  return 1;
}

