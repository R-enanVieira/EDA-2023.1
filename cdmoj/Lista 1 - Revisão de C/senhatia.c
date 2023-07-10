#include <stdio.h>
#include <ctype.h>

int main() {
	int i = 0, n, m, a, k, cm = 0, ca = 0, ck = 0;
	char senha[1001];
	scanf("%d %d %d %d %s", &n, &m, &a, &k, senha);
	while(senha[i] != '\0') {
		if(islower(senha[i]))
			cm++;
		else if(isupper(senha[i]))
			ca++;
		else if(isdigit(senha[i]))
			ck++;
		i++;
	}
	if(i >= n && cm >= m && ck >= k && ca >= a)
		printf("Ok =/\n");
	else
		printf("Ufa :)\n");
	return 0;
}
