#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	long int vect[n];
	for(int i = 0; i < n; i++) {
		scanf("%li", &vect[i]);
	}
	for(int i = 0; i < n; i++) {
		if(vect[i]%2 == 0)
			printf("%d ", i);
	}
	printf("\n");
	for(int i = 0; i < n; i++) {
		if(vect[i]%2 != 0)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}

