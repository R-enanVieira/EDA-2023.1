#include <stdlib.h>

typedef struct fila {
  int *dados;
  int N, p, u;
} fila;

int realoca(fila *f){ 
  int i, j;
  f->dados = realloc (f->dados, 2*f->N * sizeof (int));
  if(f->dados == NULL) return 0;
    
  if(f->u != f->N-1) {
    if(f->u-1 < (f->N-f->p)){
      for(i = 0; i < f->u; i++){
        f->dados[i+f->N] = f->dados[i];
      }
      f->u = f->N + f->u;
    }else {
      int j = f->N + f->p;
      for(i = f->p; i < f->N; i++) {
        f->dados[j] = f->dados[i];
        j++;
      } 
      f->p = f->N + f->p; 
    }  
  }
  f->N *= 2;
  return 1;
}


int enfileira (fila *f, int x) {
  if((f->u + 1)%f->N == f->p && !realoca(f)) return 0;

  f->dados[f->u++] = x;
  if(f->u == f->N)
    f->u = 0;
  
  return 1;
}
