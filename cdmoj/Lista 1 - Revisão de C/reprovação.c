#include <stdio.h>
#include <string.h>

int main() {
	int n, quant_problemas, quant_problemas_reprovado, cont = 1;
	scanf("%d", &n);
	char nome[22], nome_reprovado[22];
	while(scanf("%d", &n) != EOF) {
		quant_problemas_reprovado = 10+1;
		while(n--) {
			scanf("%s %d", nome, &quant_problemas);
			if(quant_problemas < quant_problemas_reprovado) {
				strcpy(nome_reprovado, nome);
				quant_problemas_reprovado = quant_problemas;
			} else if ((quant_problemas == quant_problemas_reprovado) && (strcmp(nome, nome_reprovado) > 0)) {
				strcpy(nome_reprovado, nome);
			}
		}
		printf("Instancia %d\n%s\n", cont++, nome_reprovado);
	}
	return 0;
}

