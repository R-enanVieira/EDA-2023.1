#include <stdio.h>
#include <stdlib.h>
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

void enfileira(head *, Item); //insere_fim
Item desenfileira(head *);  //remove_inicio .. busca_inicio .. remove_no


/*
    FILAS
        TIPO ABSTRATO DE DADOS
            Conjunto de dados encapsulados como um objeto, com um comportamento bem definido
            Esconder internamente as estruturas de dados e a lógica nos procedimentos
            Ocultamento de informação (caixa preta)
            Manipulação da fila somente através da funções
        
        FIFO (first-in first-out) 
            Primeiro elemento inserido é o primeiro a ser processado/retirado
            Operações/funções para acesso aos elementos (fechado/caixa preta)
            Inserções no fim, remoções no início
            COMPLEXIDADE CONSTANTE
            Operações básicas:
                vazia
                tamanho
                primeiro - busca_inicio
                ultimo - busca_fim
                enfileira - insere_fim 
                desenfileira - remove_inicio

    Implementação com lista encadeada
        Com cabeça

        ind vazia(head *lista)
            Complexidade - constante

        int tamanho(head *lista)
            Complexidade - constante

        node *primeiro(head *lista)
            Devolve o primeiro elemento da lista
            Elemento mais velho da fila
            Complexidade - constante


        node *ultimo(head *lista)
            Devolve o último elemento da lista
            Elemento mais novo da fila
            Complexidade - constante

            
        void enfileira(head *lista, node *novo)
            Insere no fim da lista
            Complexidade - busca pelo último


        Item desenfileira(head *lista)
            Remove o elemento mais velho 
            free
            Complexidade - constante

    DEQUE
        Uma fila dupla (= deque, pronuncia-se deck) permite inserção e remoção em qualquer das duas pontas
*/

/*
 * Tipos abstrato de dados
 *  FIFO - first in first out
 *  FILA
 */



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
  
void enfileira(head *lista, Item x) 
{
    node *novo = criar_no(x);
    if(novo){
        
        novo->prox = NULL;
        
        //cabeca != node
        if(!vazia(lista)) lista->ultimo->prox = novo;
        else lista->prox = novo;

        lista->ultimo = novo;
        lista->num_itens++;
    }
}

Item desenfileira(head *lista)
{
    node *lixo = primeiro(lista);
    lista->prox = lista->prox->prox;

    //cabeca != node
    if(lixo == lista->ultimo) lista->ultimo = NULL;
    lista->num_itens--;

    Item x = lixo->info;
    free(lixo);
    return x;
}


///////////////////////////////////////////////////
///////////////////////////////////////////////////
/*
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
*/




///////////////////////////////////////////////////
///////////////////////////////////////////////////

#define N 6

int main(){

    int mapa[N][N] ={ {0, 1, 0, 0, 0, 0},
                      {0, 0, 1, 0, 0, 0},
                      {0, 0, 0, 0, 1, 0},
                      {0, 0, 1, 0, 1, 0},
                      {1, 0, 0, 0, 0, 0},
                      {0, 1, 0, 0, 0, 0}};

    // Como armazenar as cidades alcançáveis?
        // criar uma fila
            head *fila_cidades = criar_lista();
    
    //
    // cidade inicial
        int inicio = 3;
    //
    // fila de cidades
        enfileira(fila_cidades, inicio);

    //
    // Como saber quantas estradas foram necessárias para chegar em uma cidade?
    //    contador para cada cidade
    //    vetor: cada índice é uma cidade
        int distancia[N];

    //
    // Como saber se um cidade já foi visitada?
    //   Um valor para cidade desconhecida ou inalcançável
    //      infinito: N (rota máxima - linha reta)
    //      diferente de infinito = cidade já visitada
        for(int cidade=0; cidade<N; cidade++)
        {
            distancia[cidade] = N; 
        } 
        distancia[inicio] = 0;
    
    //
    // Verificar as rotas possíveis 
        while(!vazia(fila_cidades))
        {
            //A partir da cidade
                int partida = desenfileira(fila_cidades);
                printf("%d ", partida);
            
            //
            //Verificar as estradas
                for(int cidade=0; cidade<N; cidade++)
                {
                    //Se existe estrada e ainda não foi visitada
                        if(mapa[partida][cidade]==1 && distancia[cidade]>=N)
                        {
                            //calcula-se a distância a partir do ponto inicial 
                                distancia[cidade] = distancia[partida] + 1;
                            
                            //
                            //enfileirar as cidades alcançáveis
                                enfileira(fila_cidades, cidade);
                            
                        }
                                     
                        if(mapa[partida][cidade]==1) printf("-> %d", cidade);
                    
                }
                printf("\n");
            
        }
    
    //
    // Imprimir as distâncias
        printf("\n");
        printf("Distâncias:\n");
        for(int cidade=0; cidade<N; cidade++)
        {
            printf("3-%d = %d\n", cidade, distancia[cidade]);
        }
        printf("\n");
    
    //
    return 0;
}