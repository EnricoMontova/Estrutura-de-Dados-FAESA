#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//criação da estrutura do nó
typedef struct no{
	int valor; //valor inteiro na lista
	struct no *prox;	//ponteiro para o próximo valor na lista
}No;

//procedimento para inserir no início
void inserir_no_inicio(No **lista, int num){
	No *novo = malloc(sizeof(No)); //criação de novo Nó
	if(novo){ //verificar se a alocação de memória deu certo
		novo->valor = num; //o campo valor recebe o número inserido pelo usuário
		novo->prox = *lista; //o ponteiro para o próximo recebe o valor inicial da lista
		*lista = novo; //o valor inicial da lista recebe o nó
	}
	else{
		printf("Erro ao alocar memória!\n");
	}
}

//procedimento para inserir no fim
void inserir_no_fim(No **lista, int num){
	No *aux, *novo = malloc(sizeof(No));//criação de um novo nó
		
	if(novo){
		novo->valor = num; //valor do nó recebe o número inserido pelo usuário
		novo->prox = NULL; //o ponteiro aponta para nulo, nos colocando no final da lista
	
		if(*lista == NULL){ //caso não houver valores na lista ainda
			*lista = novo; 
		}
		else{
			aux = *lista; //nó auxiliar recebe o endereço do primeiro nó da lista
			while(aux->prox){ //enquanto o ponteiro do nó auxiliar não apontar para nulo
				aux = aux->prox; //o nó auxiliar percorrerá a lista
			}
			aux->prox = novo; //ponteiro do nó auxiliar apontará para o novo nó inserido ao final da lista
		}
	}
	else{
		printf("Erro ao alocar memória!\n");
	}
}

//procedimento para inserir no meio
void inserir_no_meio(No **lista, int num, int ref){ //parâmetros recebidos: lista, número e uma referência
	No *aux, *novo = malloc(sizeof(No)); //criação de um novo nó
	
	if(novo){ 
		novo->valor = num; //valor do nó recebe o número inserido pelo usuário

		if(lista == NULL){ //caso a lista estiver vazia
			novo->prox = NULL; //ponteiro do nó será nulo
			*lista = novo; //início da lista assume o novo nó
		}
		else{
			aux = *lista; //nó auxiliar recebe o endereço do início da lista
			while(aux->valor != ref && aux->prox){ //enquanto o valor do nó auxiliar for diferente da referência e o ponteiro não apontar para nulo
				aux = aux->prox; //o nó auxiliar percorrerá a lista
			}
			novo->prox = aux->prox; //o ponteiro do novo nó apontará para o valor previamente apontado pela referência
			aux->prox = novo; //o ponteiro da referência apontará para o novo nó inserido na lista
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
		no = no->prox;
	}
	printf("\n\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao, valor, anterior;
	No *lista = NULL; //lista inicialmente vazia
	
	do{
		printf("\n\tOpção 0 - Sair\n\tOpção 1 - Inserir no Início\n\tOpção 2 - Inserir no Final\n\tOpção 3 - Inserir no Meio\n\tOpção 4 - Imprimir\n");
		scanf("%d", &opcao); //lê o comando digitado pelo usuário
		
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
	}while(opcao != 0); //enquanto o usuário não comandar para o loop finalizar 
	
	return 0;
}
