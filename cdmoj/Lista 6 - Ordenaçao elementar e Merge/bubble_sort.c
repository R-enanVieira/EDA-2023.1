#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *vect, int l, int r) {
  for(int i = l; i < r; i++){
    for(int j = l; j < r-1; j++)
      if(vect[j+1] < vect[j]){
        int aux = vect[j+1];
        vect[j+1] = vect[j];
        vect[j] = aux;
      }
  }
}

int main() {
  int *array;
  array = malloc(1000*sizeof(int));
  int tam = 0;
  while(scanf("%d", &array[tam]) != EOF) tam++;
  
  bubble_sort(array, 0, tam);

  for(int i = 0; i < tam; i++) {
    if(i == tam-1) printf("%d\n", array[i]);
    else printf("%d ", array[i]);
  }
  return 0;
}
