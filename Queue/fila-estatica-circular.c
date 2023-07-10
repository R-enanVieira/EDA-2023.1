#include <stdio.h>
#include <stdlib.h>

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
            Operações básicas:
                vazia
                tamanho
                primeiro - busca_inicio
                ultimo - busca_fim
                enfileira - insere_fim 
                desenfileira - remove_inicio
        
    Implementação em vetor com redimensionamento
        Ver em: https://www.ime.usp.br/~pf/algoritmos/aulas/fila.html
        
    Implementação com lista estática circular
        https://www.ime.usp.br/~pf/algoritmos/aulas/fila.html


    vazia  se   u == p  e
    cheia  se   u+1 == p   ou   u+1 == N e p == 0 


*/

#define N 10
int fila[N];
int p, u;

void criar_fila ()
{
   p = u = 0;
}

int vazia()
{
   return p == u;
}


int desenfileira()
{
    int x = fila[p++];
    if (p == N) p = 0;
    return x;
}

void enfileira (int y)
{
    fila[u++] = y;
    if (u == N) u = 0;
}

void imprime()
{
    
    if(p<u){
        printf("p=%d  :  u=%d\n", p, u);
        for(int i=p; i<u; i++) printf("%3d", fila[i]);
    }
    else {
        printf("p=%d-%d  :  u=0:%d\n", p, N-1, u);
        for(int i=p; i<N; i++) printf("%3d", fila[i]);
        for(int i=0; i<u; i++) printf("%3d", fila[i]);
    }
    printf("\n\n");
}


int main()
{
    criar_fila();
    printf("enfileirar 9\n");
    for(int i=0; i<9; i++) enfileira(i);

    imprime();

    printf("desenfileirar 3\n");
    for(int i=p; i<3; i++) desenfileira();
    imprime();


    printf("enfileirar mais 4\n");
    for(int i=0; i<4; i++) enfileira(i);

    imprime();

    
    printf("memória contígua 0 - %d\n", N+2);
    printf("p=%d  :  u=%d\n", p, u);
    for(int i=0; i<N+2; i++) printf("%3d", fila[i]);
    printf("\n");



    return 0;
}
