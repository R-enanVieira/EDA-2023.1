#include <stdio.h>

int main () {
	int n, flag;
	scanf("%d", &n);
	long int vect[n], menor;
	for(int i=0; i<n; i++) {
		scanf("%li", &vect[i]);
	}
	flag = 0;
	menor = vect[0];
	for (int i =1; i < n; i++) {
		if(vect[i] < menor) flag = i;
	}
	printf("%d\n", flag);
	return 0;
}
