#include <stdlib.h>

typedef struct pilha {
  int *dados;
  int N, topo;
} pilha;

int empilha (pilha *p, int x){
  if(p->topo == p->N) {
    p->N *= 2;
    p->dados = realloc(p->dados, p->N * sizeof(int));
  }
  if(p->dados == NULL) return 0;
  p->dados[p->topo++] = x;
  return 1;
}
