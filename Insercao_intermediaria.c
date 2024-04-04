#include <stdio.h>
#include <stdlib.h>

		

int main(int argc, char *argv[]) {
	
	struct no{
		int dado;
		struct no *prox;
	};
	struct no *lista, *p,*q;
	int sn, cont, pos;
	lista = NULL;
	cont = 0;
	
	// Inserção intermediaria em LSE
	
	//contar quantos nos a lista tem
	
	do{
		
		//contar a lista
		if(lista=NULL){
			cont = 0;
		}
		else{
			q = lista;
			cont = 1;
			while(q->prox != NULL){
				q = q->prox;
				cont++;
			}	
		}
		
		//usuario informa posicao do no a ser incluido
		
		printf("Posicao a ser inserida: ");
		scanf("%d", &pos);
		
		if(pos > cont+1){
			printf("posicao invalida\n");
		}
		else{
			if(pos==cont+1){
				//insercao a direita
				p = malloc(sizeof(struct no));
				scanf("%d",&p->dado);
				p->prox = NULL;
				q = lista;
				while(q->prox != NULL){
					q = q->prox;
				}
				q->prox = p;
			}
			else{
				//insercao intermediaria
				
			}
		}

		printf("Deseja inserir outro no a direita? 0-nao  1-sim ");
		scanf("%d",&sn);
	}while(sn==1);
	
	printf("\n\n\n");	
	p=lista;	
	while(p!=NULL){
		printf("%d  ",p->dado);
		p = p->prox;
	}
	return 0;
}
