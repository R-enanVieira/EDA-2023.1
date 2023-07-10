#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULLitem ((Item){})
#define info(A) (A.info)
#define key(A) (A.chave)
#define less(A, B) ((A) < (B))
#define eq(A, B) ((A) == (B))
#define exch(A, B) { Item t=A; A=B; B=t; }
#define compexch(A, B) if(less(B, A)) exch(A, B)

typedef int Key;
typedef struct data Item;
struct data {
    Key chave;
    int value;
};


typedef struct node STnode;
struct node {
    Item item;
    STnode *esq;
    STnode *dir;
};

STnode *new(Item x, STnode *e, STnode *d)
{
    STnode *no = malloc(sizeof(STnode));
    no->esq = e;
    no->dir = d;
    no->item = x;
    return no;
}


int STsearch(STnode *no, Key v)
{
  
    if(no == NULL) return -1;
    Key t = key(no->item);
    if(eq(v, t)) return no->item.value;
    if(less(v, t)) return STsearch(no->esq, v);
    else return STsearch(no->dir, v);
}

STnode *STinsert(STnode *no, Item item){
    
    if(no == NULL)
        return new(item, NULL, NULL);
    
    Key novo = key(item);
    Key atual = key(no->item);
    if(less(novo, atual))
        no->esq = STinsert(no->esq, item);
    else
        no->dir = STinsert(no->dir, item);

    return no;
}

int main() {                                      
  int n,m;
  Item dados;
  STnode *root;

  scanf("%d %d", &n, &m);
  int vect[n], vect2[m];
  for(int i = 0; i < n; i++) {
    scanf("%d", &dados.chave);
    dados.value = i;
    STinsert(root, dados);
  }
  
  for(int i = 0; i < m; i++) {
    scanf("%d", &vect2[i]);
  }
  int resultado;
  for(int i = 0; i < m; i++) {
    Key chave = vect2[i];
    resultado = STsearch(root, chave);
    if(resultado == -1) printf("-1\n");
    else printf("%d\n", resultado);
  }
  
  return 0;
}

