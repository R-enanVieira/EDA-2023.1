#include <stdio.h>
#include <stdlib.h>


/*
    Listas Duplamente Encadeadas Circulares
        O primeiro e último elementos estão conectados
        Requer atualização adicional nos terminais da lista
*/

typedef int Item;
//tipo node
typedef struct registro node;
struct registro {
    Item info;
    node *prox; 
    node *ant; 
};

//tipo head
typedef struct cabeca head;
struct cabeca {
    int num_itens;
    node *prox;
    node *ultimo;
};


//PROTÓTIPO DAS OPERAÇÕES BÁSICAS
head * criar_lista();
node *criar_no(Item);

int vazia(head *);

void insere_inicio(head *, node *);
void insere_fim(head *, node *);
void insere_depois(head *, node *, node *);
void insere_antes(head *, node *, node *);

node *busca_inicio(head *);
node *busca_fim(head *);

node *busca_anterior(head *, node *);
node *busca_proximo(head *, node *);

node *busca_loop_anterior(node *);
node *busca_loop_proximo(node *);

void remove_no(head *, node *);

//OPERAÇÕES ADICIONAIS
//UTILIZAR FUNÇÕES BASES



head * criar_lista()
{
    head *le = malloc(sizeof(head));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;
    return le;
}

node *criar_no(Item x)
{
    node *no = malloc(sizeof(node));
    no->ant = NULL;
    no->prox = NULL;
    no->info = x;
    return no;
}

int vazia(head *p)
{ 
    return (p->prox==NULL); 
}

void insere_inicio(head *lista, node *novo)
{  
    if(vazia(lista)) {
        lista->ultimo = novo;
        lista->prox = novo;      //<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        novo->ant = novo;
        novo->prox = novo; 

    } else {
        novo->ant = lista->ultimo;
        novo->prox = lista->prox; 

        novo->ant->prox = novo;
        novo->prox->ant = novo;

    }
    lista->prox = novo;

    lista->num_itens++;  
}

void insere_fim(head *lista, node *novo)
{
    if(vazia(lista)) return insere_inicio(lista, novo);
    
    novo->ant = lista->ultimo; 
    novo->prox = lista->prox; //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    
    lista->prox->ant = novo;  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    
    //cabeca != node
    lista->ultimo->prox = novo;
    lista->ultimo = novo;
    lista->num_itens++;
  
    //cabeca == node
    //node *aux = busca_ultimo(lista);
    //insere_depois(lista, aux, novo);
}

void insere_depois(head *lista, node *ref, node *novo)
{
    if(lista->ultimo == ref) return insere_fim(lista, novo);
    
    novo->ant = ref;
    novo->prox = ref->prox;
    ref->prox->ant = novo;
    ref->prox = novo;
      
    //cabeca != node
    lista->num_itens++;
}

void insere_antes(head *lista, node *ref, node *novo)
{
    if(lista->prox == ref) return insere_inicio(lista, novo);
     
    return insere_depois(lista, ref->ant, novo);
}

node *busca_inicio(head *lista)
{
  return lista->prox;
}

node *busca_fim(head *lista)
{

    //cabeca != node
    return lista->ultimo;
    
}

//se for o primeiro retorna null ou a cabeça
node *busca_anterior(head *lista, node *no)
{
  if(no->ant==lista->ultimo) return NULL;
  return no->ant;
}

//se for o ultimo retorna null ou a cabeça 
node *busca_proximo(head *lista, node *no)
{
  if(no->prox==lista->prox) return NULL;
  return no->prox;
}
       
//se for o primeiro retorna o último 
node *busca_loop_anterior(node *no)
{
  return no->ant;
}

//se for o ultimo retorna o primeiro
node *busca_loop_proximo(node *no)
{
  return no->prox;
}

void remove_no(head *lista, node *lixo)
{
    if(busca_loop_proximo(lixo) == lixo) {
        lista->prox = NULL;
        lista->ultimo = NULL;
        
    } else {
        lixo->ant->prox = lixo->prox; 
        lixo->prox->ant = lixo->ant;

        if(lixo==lista->prox) lista->prox = lixo->prox;
        if(lixo==lista->ultimo) lista->ultimo = lixo->ant;
    }
    lista->num_itens--;
}



///////////////////////////////////////////////////
///////////////////////////////////////////////////
void imprime(head *lista){
    printf("%d itens\n", lista->num_itens);
    
    node *a = lista->prox;
    while(a!=NULL) {
        printf("%3d", a->info);
        a = busca_proximo(lista, a);
        //a = busca_loop_proximo(a); ?????
    }
    
    if(lista->ultimo) printf("\núltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}

void imprime_reverso(head *lista){
    printf("Imprime reverso\n");
    printf("%d itens\n", lista->num_itens);
    
    node *a = busca_fim(lista);
    while(a!=NULL) {
        printf("%3d", a->info);
        a = busca_anterior(lista, a);
    }
    
    if(lista->ultimo) printf("\núltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}




///////////////////////////////////////////////////
///////////////////////////////////////////////////

int main(){
    head *le = criar_lista();

    for(int i=5; i>0; i--){
        node *novo = criar_no(i);
        insere_inicio(le, novo);
    }

    for(int i=6; i<10; i++){
        node *novo = criar_no(i);
        insere_fim(le, novo);
    }
    imprime(le);
    imprime_reverso(le);


    node *a = busca_inicio(le);
    for(int i=1; i<5; i++){
        node *b = busca_proximo(le, a);
        remove_no(le, a);
        free(a);
        a = b;
    }
    imprime(le);

    a = busca_fim(le);
    for(int i=0; i<5; i++){
        node *b = busca_anterior(le, a);
        remove_no(le, a);
        free(a);
        a = b;
    }
    imprime(le);
    return 0;
}
