#include <stdlib.h>
#include <stdio.h>

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

void em_ordem(no *raiz) {
   celula *pi = criapilha();  // pilha de nós 
   empilha (pi, raiz);
   while (1) {
      no *x = desempilha(pi);
      if (x != NULL) {
         empilha(pi, x);
         empilha(pi,x->esq);
      }
      else {
         if (pilhavazia(pi)) break;
         x = desempilha(pi);
         printf("%d ", x->dado);
         empilha(pi,x->dir);
      }
   }
}
