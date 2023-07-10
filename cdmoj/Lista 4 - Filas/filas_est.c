#include <stdlib.h>

typedef struct {
  int *v;
  int N;
  int inicio, fim;
} fila;

int enfileira (fila *f, int x) {
  if(f->fim+1 == f->inicio || (f->inicio==0 && f->fim+1 == f->N)) return 0;

  f->v[f->fim++] = x;
  if(f->fim == f->N)
    f->fim = 0;
  
  return 1;
}

int desenfileira (fila *f, int *y) {
  if (f->inicio == f->fim) return 0; 
  *y = f->v[f->inicio++];
  if(f->inicio == f->N) f->inicio = 0;
  return 1;
}
