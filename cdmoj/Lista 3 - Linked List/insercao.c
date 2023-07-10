#include <stddef.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void insere_inicio (celula *le, int x) {
  celula *p = malloc(sizeof(p));
  p->prox = NULL;
  p->dado = x;

  p->prox = le->prox;
  le->prox = p;
}

void insere_antes(celula *le, int x, int y) {
  celula *aux;
  celula *novo = malloc(sizeof(novo));
  novo->prox = NULL;
  novo->dado = x;
  
  while(le != NULL && le->dado != y) {
    aux = le;
    le = le->prox; 
  }
  if (le == NULL) {
    aux->prox = novo;
    novo->prox = NULL;
  }
  else {
    novo->prox = aux->prox;
    aux->prox = novo;
  }
}
