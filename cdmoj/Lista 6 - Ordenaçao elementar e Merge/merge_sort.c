#include <stdio.h>
#include <stdlib.h>

static void merge(int *v, int l, int m, int r) {
	int *aux;
	aux = malloc((r-l) * sizeof(int));
	int i = l, j = m;
	int k = 0;

	while(i < m && j < r) {
		if(v[i] <= v[j]) aux[k++] = v[i++];
		else aux[k++] = v[j++];
	}
	while(i < m) aux[k++] = v[i++];	
	while(j < r) aux[k++] = v[j++];

	for(i = l; i < r; ++i) v[i] = aux[i-l];
	free(aux);
}

void merge_sort(int *v, int l, int r) {
	if(l < r-1) {
	  int middle = (l+r)/2;
	  merge_sort(v, l, middle);
	  merge_sort(v, middle, r);
	  merge(v, l, middle, r);
  }
}

int main() {
	int n;
	scanf("%d", &n);

	int *array;
	array = malloc(n*sizeof(int));

	for(int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	merge_sort(array, 0, n);

	for(int i = 0; i < n; i++) {
		if(i == n-1) {
			printf("%d\n", array[i]);
		} else {
			printf("%d ", array[i]);
		}
	}
	return 0;
}
