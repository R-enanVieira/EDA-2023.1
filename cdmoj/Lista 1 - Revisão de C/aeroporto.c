#include <stdio.h>
#include <string.h>

int vect[101];

int main() {
	int a, v, x, y, teste = 1;
	while(scanf("%d %d", &a, &v) && a != 0 && v != 0){
		memset(vect, 0, sizeof(vect));
		for(int i = 0; i < v; i++) {
			scanf("%d %d", &x, &y);
			vect[x]++;
			vect[y]++;
		}
		int maior = vect[1];
		for(int i = 2; i <= a; i++){
			if(vect[i] > maior) {
				maior = vect[i];	
			}
		}
		printf("Teste %d\n", teste++);
		for(int i = 1; i <= a; i++) {
			if(vect[i] == maior) {
				printf("%d ", i);
			}
		}
		printf("\n\n");
	}
	return 0;
}
