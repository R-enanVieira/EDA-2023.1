#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int Item;

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


head *criar_lista();
node *criar_no(Item);

int vazia(head *);
int tamanho(head *); 

node *primeiro(head *); 
node *ultimo(head *);

Item espia(head *);

void empilha(head *, Item); //insere_inicio
Item desempilha(head *);    //remove_inicio


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

int tamanho(head *lista) 
{
    return lista->num_itens;
}

node *primeiro(head *lista) 
{
    return lista->prox;
}
 
node *ultimo(head *lista)
{
    return lista->ultimo;
}
  
Item espia(head *p)
{ 
    return (p->prox->info); 
}

void empilha(head *lista, Item x) 
{
    node *novo = criar_no(x);
    if(novo){
        if(vazia(lista)) lista->ultimo = novo;
        
        novo->prox = lista->prox;
        lista->prox = novo;
        
        lista->num_itens++;
    }
}

Item desempilha(head *lista)
{
    node *topo = lista->prox;
    lista->prox = topo->prox;

    if(topo == lista->ultimo) lista->ultimo = NULL;
    lista->num_itens--;

    Item x = topo->info;
    free(topo);
    return x;
}


#define N 6
void exemplo1()
{
    int mapa[N][N] ={ {0, 1, 0, 0, 0, 0},
                      {0, 0, 1, 0, 0, 0},
                      {0, 0, 0, 0, 0, 1},
                      {0, 0, 1, 0, 1, 0},
                      {1, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0}};

    head *pilha_cidades = criar_lista();
    
    int inicio = 3;
    empilha(pilha_cidades, inicio);
    int distancia[N];

    for(int cidade=0; cidade<N; cidade++)
    {
        distancia[cidade] = N; 
    } 
    distancia[inicio] = 0;
    
    while(!vazia(pilha_cidades))
    {
        printf("Pilha a ser processada: ");
        node *a = pilha_cidades->prox;
        while(a!=NULL){
            printf("%d ", a->info);
            a = a->prox;
        }
        printf("\n");

        int partida = desempilha(pilha_cidades);
        printf("Partida %d ", partida);
        
        
        for(int cidade=0; cidade<N; cidade++)
        {
            if(mapa[partida][cidade]==1 && distancia[cidade]>=N)
            {
                distancia[cidade] = distancia[partida] + 1;
                empilha(pilha_cidades, cidade);
                
            }
                            
            if(mapa[partida][cidade]==1) printf("-> %d", cidade);
            
        }
        printf("\n\n");
        
    }
    printf("\n");
    printf("Distâncias:\n");
    for(int cidade=0; cidade<N; cidade++)
    {
        printf("3-%d = %d\n", cidade, distancia[cidade]);
    }
    printf("\n");
}


void exemplo2(char *expr)
{
    head *p = criar_lista();

    int i=0;
    while(expr[i]!='\0') {

        if(expr[i]=='*'||expr[i]=='/'||expr[i]=='_') 
        {
            if(!vazia(p) && espia(p) == expr[i]) 
            desempilha(p);
            else
            empilha(p, expr[i]);
        }
        i++;
    }

    if(vazia(p)) 
        printf("C\n\n");
    else  
        printf("E\n\n");
}

void exemplo3(char *a){
    
    head *pilha = criar_lista();
    
    for(int i=0; a[i]!='\0'; i++) {

        //operacao do operador sobre os ultimos operandos lidos
        if(a[i] == '+')
            empilha(pilha, desempilha(pilha)+desempilha(pilha));
        if(a[i] == '*')
            empilha(pilha, desempilha(pilha)*desempilha(pilha));

        //colocar zero a esquerda
        if((a[i] >= '0') && (a[i] <= '9')) empilha(pilha, 0);

        //calcular o equivalente numerico de uma 
        //  sequencia de caracteres
        while((a[i] >= '0') && (a[i] <= '9'))
            //calcula o decimal, centena ... + valor numerico 
            empilha(pilha, 10*desempilha(pilha) + (a[i++]-'0'));
    }   
    printf("%s = %d\n\n", a, desempilha(pilha));
}

int main (int argc, char *argv[]) {
    if(argc>1 && strcmp(argv[1], "1")==0)
        exemplo1();
    else if(argc>2 && strcmp(argv[1], "2")==0)
        exemplo2(argv[2]);
    else if(argc>2 && strcmp(argv[1], "3")==0)
        exemplo3(argv[2]);
    return 0;
}