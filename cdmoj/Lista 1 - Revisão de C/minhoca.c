#include <stdio.h>

int main() {
	int n, m;
	unsigned int sum_line = 0, sum_column = 0, total_line = 0, total_column = 0;
	scanf("%d %d",&n, &m);
	int campo[n][m];
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &campo[i][j]);
			sum_line += campo[i][j];
		}
		if(sum_line > total_line)
			total_line = sum_line;
		sum_line = 0;
	}
	for (int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			sum_column += campo[i][j];
		}
		if(sum_column > total_column)
			total_column = sum_column;
		sum_column = 0;
	}
	if(total_line > total_column)
		printf("%d\n", total_line);
	else
		printf("%d\n", total_column);
	return 0;
}
					
					

