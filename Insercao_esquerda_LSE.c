#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	// Declara��o do tipo n� da lista
	struct no{
		int dado;
		struct no *prox;
	};
	
	// Declara��o de vari�veis. Lista para cabe�alho da LSE
	// P como ponteiro din�mico para aloca��o din�mica
	struct no *lista, *p;
	int sn;
	
	// Lista vazia
	lista = NULL;
	
	// Inclus�o � esquerda de n�s na lista LSE
	do{	
		p = malloc(sizeof(struct no));
		//p->dado = 25;
		printf("Digite o dado a inserir na lista: ");
		scanf("%i",&p->dado);
		p->prox = lista;
		lista = p;
		
		printf("Deseja inserir um novo n�? 0-nao 1-sim");
		scanf("%i",&sn);
	}while (sn == 1);
	
	printf()
	
	return 0;
}
