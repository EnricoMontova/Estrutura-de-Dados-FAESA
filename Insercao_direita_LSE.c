#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	struct no{
		int dado;
		struct no *prox;
	};
	struct no *lista, *p,*q;
	int sn;
	lista = NULL;
	
	// Inserção a direita em LSE
	do{
	
		if(lista==NULL){
			p = malloc(sizeof(struct no));
			scanf("%d",&p->dado);
			p->prox = lista;
			lista = p;
		}
		else{
			p = malloc(sizeof(struct no));
			scanf("%d",&p->dado);
			p->prox = NULL;
			q = lista;
			while(q->prox != NULL){
				q = q->prox;
			}
			q->prox = p;
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
