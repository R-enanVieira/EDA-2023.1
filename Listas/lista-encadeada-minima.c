#include <stdio.h>
#include <stdlib.h>

/*
Sequência de conteiners
        Inserção tempo constante
        Ideal para aplicações com grandes conjuntos de dados e, poucas ou sem remoções, ou implementações de FIFO (filas)
        Custo de remoção: O(n)
        Formas de implementação
            Aponta para o próximo elemento
            Inserção/Remoção após um elemento em tempo constante
            Sem cabeça, com cabeça, com cauda, com cabeça e cauda
            Cabeça do mesmo tipo dos elementos do corpo
            Cabeça com elementos diferentes do corpo
            
        Características
            melhor performance na inserção, remoção/extração e movimentação dos elementos
            requer menos espaço e manipulação de ponteiro do que a duplamente
            algoritmos com várias movimentações como algoritmos de ordenação
            desvantagem: 
                sem acesso direto a uma posição
                aumento da carga nas remoções de elementos arbitrários
            uso de campos adicionais: 
                    aumenta o uso da memória e um pouco da carga de inserções e remoções
                    porém aumenta a eficiência das operações em fim de lista
                        diminui o custo da função busca_fim

*/
/*
 * Tipos de dados dos elementos da lista
 *  Item: tipo do conteúdo dos nós
 *  node: tipo de cada nó
 *  head: tipo da cabeça da lista
 */
typedef int Item;


//tipo node
typedef struct registro node;
struct registro {
    Item info;
    node *prox; 
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
int tamanho_lista(head *);

void insere_inicio(head *, node *);
void insere_depois(head *, node *, node *);
void insere_fim(head *, node *); //com cabeça e apontador para o último

node *busca_inicio(head *);
node *busca_proximo(node *);
node *busca_fim(head *);//com cabeça e apontador para o último

void remove_no(head *, node *);
void remove_inicio(head *);

//OPERAÇÕES ADICIONAIS
//buscar nó antes de outro nó
//buscar nó antes de um dado/item
//inserir um nó ou um item antes de um nó
//inserir um nó ou um item antes ou depois de uma posição
//remover um item ou nó depois de um nó ou de uma posição


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
    no->prox = NULL;
    no->info = x;
    return no;
}

int vazia(head *p)
{
    return (p->prox==NULL); 
}

int tamanho_lista(head *lista)
{
    //cabeca != node
    return lista->num_itens;
    
    //cabeca == node
    //int tam = 0;
    //node *aux = busca_inicio(lista);
    //while(aux != NULL && aux->prox != NULL){
      //  aux= aux->prox;
      // tam++;
    //}
    //return tam;
    
}

void insere_inicio(head *lista, node *novo)
{  
    //cabeca != node
    if(vazia(lista)) lista->ultimo = novo;
    lista->num_itens++;  
    
    novo->prox = lista->prox;    
    lista->prox = novo;
}

void insere_fim(head *lista, node *novo)
{
    if(vazia(lista)) return insere_inicio(lista, novo);
        
    novo->prox = NULL;
        
    //cabeca != node
    lista->ultimo->prox = novo;
    lista->ultimo = novo;
    lista->num_itens++;
    
    //cabeca == node
    //node *aux = busca_fim(lista);
    //insere_depois(lista, aux, novo);
}

void insere_depois(head *lista, node *ref, node *novo)
{
    if(lista->ultimo == ref) return insere_fim(lista, novo);
      
    novo->prox = ref->prox;
    ref->prox = novo;
      
    //cabeca != node
    lista->num_itens++;
}

node *busca_inicio(head *lista)
{
  return lista->prox;
}

node *busca_proximo(node *no)
{
  return no->prox;
}

node *busca_fim(head *lista)
{

    //cabeca != node
    return lista->ultimo;
    
    //cabeca == node
    //cauda apontando para o último elemento
    
}

void remove_no(head *lista, node *lixo)
{
    node *aux = busca_inicio(lista);
    while(aux!=NULL && aux->prox!=lixo) 
        aux = busca_proximo(aux);

    if(aux){
        aux->prox = lixo->prox;
        if(lixo == lista->ultimo) lista->ultimo = aux->prox;
        lista->num_itens--;
    }
    
}

void remove_inicio(head *lista)
{
    if(!vazia(lista)){
        node *lixo = lista->prox;
        lista->prox = lista->prox->prox;

        if(lixo == lista->ultimo) lista->ultimo = NULL;
        lista->num_itens--;
    }
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////




///////////////////////////////////////////////////
///////////////////////////////////////////////////
void imprime(head *lista){
    printf("%d itens\n", lista->num_itens);
    
    node *a = lista->prox;
    while(a!=NULL) {
        printf("%3d", a->info);
        a = a->prox;
    }
    
    if(lista->ultimo) printf("\núltimo item: %d", lista->ultimo->info);
    printf("\n\n");
}

/*void criar_lista(head **le)
{
    *le = malloc(sizeof(head));
    (*le)->num_itens = 0;
    (*le)->prox = NULL;
    (*le)->ultimo = NULL;
}*/


///////////////////////////////////////////////////
///////////////////////////////////////////////////
int main(){
  head *le = criar_lista();
  //head *le;
  //criar_lista(&le);
  
  return 0;
}
