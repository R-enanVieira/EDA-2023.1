typedef struct fila {
  int *dados;
  int N, p, u;
} fila;

int desenfileira (fila *f, int *y) {
  if (f->p == f->u) return 0; 
  *y = f->dados[f->p++];
  if(f->p == f->N) f->p = 0;
  return 1;
}
