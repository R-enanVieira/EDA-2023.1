#include <stdio.h>

int main() {
	int n, x, flag;
	scanf("%d", &n);
	long int vect[n];
	for(int i = 0; i < n; i++) {
		scanf("%li", &vect[i]);
	}
	scanf("%d", &x);

	flag = 0;
	for(int i = 0; i < n; i++) {
		if(vect[i] == x) flag = 1;
	}
	if(flag) {
		printf("pertence\n");
	}
	else {
		printf("nao pertence\n");
	}
	return 0;
}
