#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pilha {
  char *string;
  int N, topo;
} pilha;

void empilha(pilha *p, char x) {
  if(p->topo == p->N) {
    p->N *= 2;
    p->string = realloc(p->string, p->N * sizeof(char));
  }
  p->string[p->topo++] = x;
}
char desempilha(pilha *p){
  return p->string[--p->topo];
}

int vazia(pilha *p) {
  return (p->topo == 0);
}

int main() {
  pilha *str;
  str = malloc(sizeof(pilha));

  char string[501];
  scanf("%s", string);
  int len = strlen(string);

  str->N = len;

  for(int i = 0; i != '\0'; i++) {
   empilha(str, string[i]);
  }

  while(!vazia(str)) {
    printf("%c", desempilha(str));
  }
  printf("\n");
  return 0;
}  
