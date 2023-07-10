#include <stdio.h>

typedef struct celula {
  int dado;
  struct celula *prox;          
} celula;

void imprime(celula *le) {       
  celula *p;
  p = le->prox;
  while(p != NULL) {
    printf("%d -> ", p->dado);
    p = p->prox;
  }
  printf("NULL\n");   
}

void imprime_rec(celula *le) {
  celula *p;
  p = le->prox;

  if(p != NULL) {
    printf("%d -> ", p->dado);
    imprime_rec(p);      
  }
  else {
    printf("NULL\n");  
  }
}
