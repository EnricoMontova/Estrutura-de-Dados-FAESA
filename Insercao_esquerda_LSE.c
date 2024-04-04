#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	// Declaração do tipo nó da lista
	struct no{
		int dado;
		struct no *prox;
	};
	
	// Declaração de variáveis. Lista para cabeçalho da LSE
	// P como ponteiro dinâmico para alocação dinâmica
	struct no *lista, *p;
	int sn;
	
	// Lista vazia
	lista = NULL;
	
	// Inclusão à esquerda de nós na lista LSE
	do{	
		p = malloc(sizeof(struct no));
		//p->dado = 25;
		printf("Digite o dado a inserir na lista: ");
		scanf("%i",&p->dado);
		p->prox = lista;
		lista = p;
		
		printf("Deseja inserir um novo nó? 0-nao 1-sim");
		scanf("%i",&sn);
	}while (sn == 1);
	
	printf()
	
	return 0;
}
