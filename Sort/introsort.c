#include <stdlib.h>
#include <math.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define exch(A, B) { Item tmp = A; A = B; B = A; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int partition(int *v, int begin, int end) {
  int i = begin - 1;
  int j = end;

  for(;;) {
    while(less(v[++i], v[end])) {}
    
    while(less(v[end], v[--j])) {
      if(j == begin) {
        break;
      }
    }

    if(i >= j) {
      break;
    }

    exch(v[i], v[j]);
  }

  exch(v[i], v[end]);
  return i;
}

int deuMerda;
void quicksort(Item *v, int begin, int end, int recursion) {
  if(end - begin < 32) {
    return;
  }

  if(recursion == 0) {
    deuMerda = 1;
    return;
  }

  int mid = (begin + end)/2;
  cmpexch(v[mid],v[end]);
    cmpexch(v[begin],v[mid]);
      cmpexch(v[end],v[mid]);

  int p = partition(v, begin, end);
  quicksort(v, begin, p-1, recursion - 1);
  quicksort(v, p+1, end, recursion - 1);
}

void introsort(Item *v, int begin, int end) {
  int maxRecursion = 2*((int)log2((double)(end-begin+1)));

  deuMerda = 0;
  quicksort(v, begin, end, maxRecursion);

  if(deuMerda == 1) {
    mergeSort(v, begin, end);
  } else {
    insertionSort(v, begin, end);
  }
}
