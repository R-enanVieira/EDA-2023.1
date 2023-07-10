#include <stddef.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int remove_depois(celula *p) {
  if(p->prox != NULL) {
    celula *lixo = p->prox;
    p->prox = lixo->prox;
    return lixo->dado;
  }
}

void remove_elemento (celula *le, int x) {
  celula *p;
  p = le->prox;

  while(p != NULL) {
    if(p->dado == x) {
      le->prox = p->prox;
      free(p);
      break;
    }
    le = le->prox;
    p = p->prox;
  }
}
void remove_todos_elementos (celula *le, int x) {

  while(le != NULL) {
    if(le->prox->dado == x) {
      remove_depois(le);
    } 
    le = le->prox;
  }
}
