#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	Alocação dinâmica de memória com função malloc.
	retorna um ponteiro para a região de memória 
	alocada ou NULL.
*/

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int *x;
	
	x = malloc(sizeof(int));
	
	if(x != NULL){
		printf("Memoria alocada com sucesso\n");
		printf("x: %d\n", *x);
		*x = 50;
		printf("x: %d\n", *x);
	} 
	else{
		printf("Erro ao alocar memoria\n");
	}
	
	return 0;
}
