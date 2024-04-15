#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int valor;
	struct no *proximo;	
}No;

//procedimento para inserir no início
void inserir_no_inicio(No **lista, int numero){
	No *novo_no = malloc(sizeof(No)); //criação de novo Nó
	if(novo_no){
		novo_no->valor = numero;
		novo_no->proximo = *lista;
		*lista = novo_no;
	}
	else{
		printf("Erro ao alocar memória!\n");
	}
}

//procedimento para inserir no fim
void inserir_no_fim(No **lista, int numero){
	No *auxiliar, *novo_no = malloc(sizeof(No));
		
	if(novo_no){
		novo_no->valor = numero;
		novo_no->proximo = NULL;
		//é o primeiro?
		if(*lista == NULL){
			*lista = novo_no;
		}
		else{
			auxiliar = *lista;
			while(auxiliar->proximo){
				auxiliar = auxiliar->proximo;
			}
			auxiliar->proximo = novo_no;
		}
	}
	else{
		printf("Erro ao alocar memória!\n");
	}
}

//procedimento para inserir no meio
void inserir_no_meio(No **lista, int numero, int anterior){
	No *auxiliar, *novo_no = malloc(sizeof(No));
	
	if(novo_no){
		novo_no->valor = numero;
		//é o primeiro?
		if(lista == NULL){
			novo_no->proximo = NULL;
			*lista = novo_no;
		}
		else{
			auxiliar = *lista;
			while(auxiliar->valor != anterior && auxiliar->proximo){
				auxiliar = auxiliar->proximo;
			}
			novo_no->proximo = auxiliar->proximo;
			auxiliar->proximo = novo_no;
		}
	}
	else{
		printf("Erro ao alocar memória!\n");
	}
}

void imprimir(No *no){
	printf("\n\tLista: ");
	while(no){
		printf("%d ", no->valor);
		no = no->proximo;
	}
	printf("\n\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao, valor, anterior;
	No *lista = NULL;
	
	do{
		printf("\n\tOpção 0 - Sair\n\tOpção 1 - Inserir no Início\n\tOpção 2 - Inserir no Final\n\tOpção 3 - Inserir no Meio\n\tOpção 4 - Imprimir\n");
		scanf("%d", &opcao);
		
		switch(opcao){
		case 1:
			printf("Digite um valor: ");
			scanf("%d", &valor);
			inserir_no_inicio(&lista, valor);
			break;
		case 2:
			printf("Digite um valor: ");
			scanf("%d", &valor);
			inserir_no_fim(&lista, valor);
			break;
		case 3:
			printf("Digite um valor e o valor de referência: ");
			scanf("%d %d", &valor, &anterior);
			inserir_no_meio(&lista, valor, anterior);
			break;
		case 4:
			imprimir(lista);
			break;
		default:
			if(opcao != 0){
				printf("Opção inválida!\n");
			}
		}	
	}while(opcao != 0);
	
	return 0;
}
