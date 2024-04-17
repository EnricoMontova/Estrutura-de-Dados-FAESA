#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//cria��o da estrutura do n�
typedef struct no{
	int valor; //valor inteiro na lista
	struct no *prox;	//ponteiro para o pr�ximo valor na lista
}No;

//procedimento para inserir no in�cio
void inserir_no_inicio(No **lista, int num){
	No *novo = malloc(sizeof(No)); //cria��o de novo N�
	if(novo){ //verificar se a aloca��o de mem�ria deu certo
		novo->valor = num; //o campo valor recebe o n�mero inserido pelo usu�rio
		novo->prox = *lista; //o ponteiro para o pr�ximo recebe o valor inicial da lista
		*lista = novo; //o valor inicial da lista recebe o n�
	}
	else{
		printf("Erro ao alocar mem�ria!\n");
	}
}

//procedimento para inserir no fim
void inserir_no_fim(No **lista, int num){
	No *aux, *novo = malloc(sizeof(No));//cria��o de um novo n�
		
	if(novo){
		novo->valor = num; //valor do n� recebe o n�mero inserido pelo usu�rio
		novo->prox = NULL; //o ponteiro aponta para nulo, nos colocando no final da lista
	
		if(*lista == NULL){ //caso n�o houver valores na lista ainda
			*lista = novo; 
		}
		else{
			aux = *lista; //n� auxiliar recebe o endere�o do primeiro n� da lista
			while(aux->prox){ //enquanto o ponteiro do n� auxiliar n�o apontar para nulo
				aux = aux->prox; //o n� auxiliar percorrer� a lista
			}
			aux->prox = novo; //ponteiro do n� auxiliar apontar� para o novo n� inserido ao final da lista
		}
	}
	else{
		printf("Erro ao alocar mem�ria!\n");
	}
}

//procedimento para inserir no meio
void inserir_no_meio(No **lista, int num, int ref){ //par�metros recebidos: lista, n�mero e uma refer�ncia
	No *aux, *novo = malloc(sizeof(No)); //cria��o de um novo n�
	
	if(novo){ 
		novo->valor = num; //valor do n� recebe o n�mero inserido pelo usu�rio

		if(lista == NULL){ //caso a lista estiver vazia
			novo->prox = NULL; //ponteiro do n� ser� nulo
			*lista = novo; //in�cio da lista assume o novo n�
		}
		else{
			aux = *lista; //n� auxiliar recebe o endere�o do in�cio da lista
			while(aux->valor != ref && aux->prox){ //enquanto o valor do n� auxiliar for diferente da refer�ncia e o ponteiro n�o apontar para nulo
				aux = aux->prox; //o n� auxiliar percorrer� a lista
			}
			novo->prox = aux->prox; //o ponteiro do novo n� apontar� para o valor previamente apontado pela refer�ncia
			aux->prox = novo; //o ponteiro da refer�ncia apontar� para o novo n� inserido na lista
		}
	}
	else{
		printf("Erro ao alocar mem�ria!\n");
	}
}

void imprimir(No *no){ 
	printf("\n\tLista: ");
	while(no){
		printf("%d ", no->valor);
		no = no->prox;
	}
	printf("\n\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao, valor, anterior;
	No *lista = NULL; //lista inicialmente vazia
	
	do{
		printf("\n\tOp��o 0 - Sair\n\tOp��o 1 - Inserir no In�cio\n\tOp��o 2 - Inserir no Final\n\tOp��o 3 - Inserir no Meio\n\tOp��o 4 - Imprimir\n");
		scanf("%d", &opcao); //l� o comando digitado pelo usu�rio
		
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
			printf("Digite um valor e o valor de refer�ncia: ");
			scanf("%d %d", &valor, &anterior);
			inserir_no_meio(&lista, valor, anterior);
			break;
		case 4:
			imprimir(lista);
			break;
		default:
			if(opcao != 0){
				printf("Op��o inv�lida!\n");
			}
		}	
	}while(opcao != 0); //enquanto o usu�rio n�o comandar para o loop finalizar 
	
	return 0;
}
