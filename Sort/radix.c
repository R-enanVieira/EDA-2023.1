#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;

#define key(A) A
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t=A; A=B; B=t; }
#define compexch(A, B) if(less(B, A)) exch(A, B)


#define maxstring 101
#define bitsbyte 8
#define bytesword 4
#define R (1 << bitsbyte)


void show(Item v[][maxstring], int l, int r){
    for(int i=l; i<=r; i++){
        printf("%s ", v[i]);
    }
    printf("\n");
}

/* void quickB(Item *v, int l, int r, int w){
    int i=l, j=r;
    
    if(r<=l || w > bitsword) return;
    while(j!=i){
        while(digit(v[i], w) == 0 && (i<j)){
            i++;   
        } 
        while(digit(v[j], w) == 1 && (j>i)){
            j--;
        } 
        exch(v[i], v[j]);
    }
    if(digit(v[r], w) == 0) j++;
    quickB(v, l, j-1, w+1);
    quickB(v, j, r, w+1);
} */

int charAt(char s[], int d)
{ 
    if (d < strlen(s)) return s[d];
    else return -1; //não possui o d-esimo caractere
                    //soma 1 no count[0]
                    //count[0] = quantidade de palavras menores que d
                    //o que isso implica?
}

//Ordena para o d-ésimo caractere
void radixMSD(char a[][maxstring],  int l, int r, int d)
{ 
    if(r<=l) return;
    
    char aux[r-l+1][maxstring];
    int count[R+1];
    for(int i=0; i<=R; i++)
        count[i] = 0;

    for (int i = l; i <= r; i++)
        count[charAt(a[i], d) + 1]++; //frequencia do d-ésimo caractere
    
    for (int i = 1; i<=R; i++)
        count[i] += count[i-1]; //acha as posições

    for (int i = l; i <= r; i++) 
        strcpy(aux[count[charAt(a[i], d)]++], a[i]); //ordena em aux

    for (int i = l; i <= r; i++)
        strcpy(a[i], aux[i - l]); //copia para o original
    
    //Recursivamente ordena as palavras com caractere na d-esima posição
    //ordenar palavras com o caractere i no d-ésimo dígito
    for (int i = 1; i <= R; i++){
        //count[i] posição da próxima chave com o caractere i
        //count[i]-1 posição da última chave com o caractere i
        
        //count[i-1] posição da próxima chave com o caractere i-1
        //           posição da primeira chave com o caractere i

        radixMSD(a, l + count[i-1], l + count[i]-1, d+1);
    }

}


void radixLSD(char a[][maxstring],  int l, int r, int w)
{ 
    //strings de tamanho w
    char aux[r-l+1][w];
    int count[R+1];
    
    for(int d=w-1; d>=0; d--){
        for(int i=0; i<=R; i++)
            count[i] = 0;
    
        for (int i=l; i<=r; i++)
            count[charAt(a[i], d) + 1]++;
        
        for (int i=1; i<=R; i++)
            count[i] += count[i-1];

        for (int i=l; i<=r; i++)
            strcpy(aux[count[charAt(a[i], d)]++], a[i]);

        for (int i = l; i <= r; i++)
            strcpy(a[i], aux[i - l]); 

    }
}

int main() {
    char a[5][maxstring] = {"cavalo", "bexiga", "nabo", "praca", "cafe"};
    char b[5][maxstring] = {"caro", "beta", "nabo", "pera", "cafe"};

    //show(b, 0, 4);
    //radixLSD(b, 0, 4, 5);
    //show(b, 0, 4);

    show(a, 0, 4);
    radixMSD(a, 0, 4, 0); //ordena para o caractere na posição 0
                          //posição 0 = primeiro caractere ()
    show(a, 0, 4);
}