#include <stdio.h>
#include <string.h>

int main() {
	int i = 0, j = 0;
	char str[1001], inv[1001];
	scanf("%s", str);
	while(1){
		if(str[i] == '\0') {
			for(int k = 0; k <= j; k++) {
				if (i > 0)
					inv[k] = str[i-1];
				else
					inv[k] = '\0';
				i--;
			}
			break;
		}
		i++;
		j++;
	}
	printf("%s\n", inv);
	return 0;
}
