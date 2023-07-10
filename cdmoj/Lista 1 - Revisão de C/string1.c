#include <stdio.h>

int main() {
	int i = 0;
	char text[1001];
	scanf("%s", text);
	while(text[i] != '\0') {
		i++;
	}
	printf("%d\n", i);
	return 0;
}


