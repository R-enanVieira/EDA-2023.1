#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertion_sort(int *vect, int l, int r) { 
  for(int i = r-1; i > l; i--) cmpexch(vect[i-1], vect[i]);

  for(int i = l+2; i < r; i++) {
    int j = i;
    int temp = vect[j];
    while(temp < vect [j-1]){
      vect[j] = vect[j-1];
      j--;
    }
    vect[j] = temp;
  }
}
/*void insertion_sort(int *vect, int l, int r) { 
  for(int i = r-1; i > l; i--) {
    if(vect[i] < vect[i-1]){
      int aux = vect[i-1];
      vect[i-1] = vect[i];
      vect[i] = aux;
    }
  }

  for(int i = l+2; i < r; i++) {
    int j = i;
    int temp = vect[j];
    while(temp < vect [j-1]){
      vect[j] = vect[j-1];
      j--;
    }
    vect[j] = temp;
  }
}*/

/*void insertion_sort(int *vect, int l, int r) { 
  for(int i = l + 1; i < r; i++) {
    for(int j = i; j > l; j--){
      if(vect[j] < vect[j-1]) {
        int aux;
        aux = vect[j];
        vect[j] = vect[j-1];
        vect[j-1] = aux;
      } else break;
    }
  }
}*/

int main() {
  int *array;
  array = malloc(50000*sizeof(int));
  int tam = 0;
  while(scanf("%d", &array[tam]) != EOF) tam++;
  
  insertion_sort(array, 0, tam);

  for(int i = 0; i < tam; i++) {
    if(i == tam-1) printf("%d\n", array[i]);
    else printf("%d ", array[i]);
  }
  return 0;
}

//tomei TLE por não dar o malloc com o numero correto de elemntos maximo
