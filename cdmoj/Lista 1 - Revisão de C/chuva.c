#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int antes[n][n], depois[n][n], soma[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &antes[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &depois[i][j]);
			soma[i][j] = antes[i][j] + depois[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", soma[i][j]);
		}
		printf("\n");
	}
	return 0;
}
