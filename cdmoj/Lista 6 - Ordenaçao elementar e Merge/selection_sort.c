#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *vect, int tam) {
  int menor;
  for(int i = 0; i < tam-1; i++) {
    menor = i;
    for(int j = i+1; j < tam; j++){
      if(vect[menor] > vect[j]) menor = j;
    }
    int aux;
    aux = vect[i];
    vect[i] = vect[menor];
    vect[menor] = aux;
  }
}

int main() {
  int *array;
  array = malloc(1000*sizeof(int));
  int tam = 0;
  while(scanf("%d", &array[tam]) != EOF) tam++;
  
  selection_sort(array, tam);

  for(int i = 0; i < tam; i++) {
    if(i == tam-1) printf("%d\n", array[i]);
    else printf("%d ", array[i]);
  }
  return 0;
}
