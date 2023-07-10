#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

celula *criarfila() {
  celula *nova;
  nova = malloc(sizeof(celula));
  nova->prox = nova;
}

celula *enfileira (celula *f, int x) {
  celula *nova;
  nova = malloc (sizeof (celula));
  nova->prox = f->prox;
  f->prox = nova;
  f->dado = x;
  return nova;
}

int desenfileira (celula *f) {
  if(f->prox == f) return 0;
  int y;
  celula *lixo;
  lixo = f->prox;
  f->prox = lixo->prox;
  y = lixo->dado;
  free(lixo);
  return y;
}

int p, r;

int main() {
  celula *fi;
  fi = criarfila();
  while(scanf("%d %d", &p, &r) && (p != 0 && r != 0)) {
    int x;
    for(int i = 0; i < p; i++) {
      scanf("%d", &x);
      enfileira(fi, x);
    }
    while(1){
      printf("%d ", desenfileira(fi));
    }
    int n, j;
    while(r--) {
      scanf("%d %d", &n, &j);
      int a;
      for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        int current; 
        current = desenfileira(fi);
        if(a == j) enfileira(fi, current);
      }
    }
    int cont = 1;
    printf("Teste %d\n", cont++);
    printf("%d\n", desenfileira(fi));

  }
  
  return 0;
}
