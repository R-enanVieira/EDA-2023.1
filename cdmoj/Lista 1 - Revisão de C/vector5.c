#include <stdio.h>

int main() {
	int n, x, flag = 0;
	scanf("%d", &n);
	long int vect[n];
	for(int i = 0; i < n; i++) {
		scanf("%li", &vect[i]);
	}
	scanf("%d", &x);
	for(int i = 0; i < n; i++) {
		if(vect[i] == x) {
			flag = 1;
		}
	}
	if(flag == 1)
		printf("pertence\n");
		
	else
		printf("nao pertence\n");
	return 0;
}
