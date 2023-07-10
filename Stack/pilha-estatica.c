#include <stdio.h>
#include <stdlib.h>

static Item *s;
static int N;

void criar(int maxN) { 
    s = malloc (maxN * sizeof *s);
    N = 0;
}

int vazia() { return N == 0; }

void empilhar(Item item) {
    s[N++] = item;
}

Item desempilhar() {
    return s[--N];
}

Item espiar(){
    return s[N-1];
}