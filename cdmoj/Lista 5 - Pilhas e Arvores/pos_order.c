#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int dado;
  struct no *esq, *dir;
} no;

typedef struct celula {
   no *conteudo; 
   struct celula *prox;
} celula;

celula *criapilha (void) {
   celula *pi;
   pi = malloc (sizeof (celula)); // cabeça
   pi->prox = NULL;
   return pi;
}

void empilha (celula *pi, no *r) { 
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->conteudo = r;
   nova->prox  = pi->prox;
   pi->prox = nova; 
}

no *desempilha (celula *pi) {
  celula *p;
  p = pi->prox;
  no *r = p->conteudo;
  pi->prox = p->prox;
  free (p);
  return r; 
}

int pilhavazia(celula *pi) {
   return (pi->prox == NULL);
}

void pos_ordem (no *raiz) {
  celula *pilha = criapilha();
  celula *pilha_aux = criapilha();
  empilha(pilha, raiz);
  while(!pilhavazia(pilha)) {
    no *node = desempilha(pilha);
    if(!node) continue;
    empilha(pilha_aux, node);
    
    if(node->esq) empilha(pilha, node->esq);
    if(node->dir) empilha(pilha, node->dir);
    
  }

  while(!pilhavazia(pilha_aux)) {
    no *imprime = desempilha(pilha_aux);
    printf("%d ", imprime->dado);
  }
}
