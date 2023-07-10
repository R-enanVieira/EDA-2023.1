#include <stdio.h>
#include <string.h>

int main() {
	int i, encontrou, tamanho, total=0, contP=0;
	char letra, texto[1002];
	scanf("%c", &letra);
	while(scanf("%s", texto) == 1) {
		encontrou = 0;
		tamanho = strlen(texto);
		for(i = 0; i < tamanho; i++)
			if(texto[i] == letra)
				encontrou = 1;
		contP += encontrou;
		total++;
	}
	printf("%.1f\n", (contP*100.0)/total);
	
	return 0;
}
