#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definindo a estrutura do nó
typedef struct no{
    int dado;
    struct no* proximo;
}No;

// Definindo a estrutura da lista com descritor
typedef struct DescritorLista{
    int tamanho;
    No* inicio;
}list_descritor;

// Função para inicializar a lista com descritor
void inicializar_lista(list_descritor* ld){
    ld->tamanho = 0;
    ld->inicio = NULL;
}

// Função para inserir um novo nó de forma ordenada na lista
void inserir_ordenado(list_descritor* ld, int novo_dado){
    No* novo_no = (No*)malloc(sizeof(No));
    No* atual = ld->inicio;
    No* anterior = NULL;

    novo_no->dado = novo_dado;
    novo_no->proximo = NULL;

    // Se a lista estiver vazia ou o novo nó deve ser inserido no início
    if(atual == NULL || atual->dado >= novo_dado) {
        novo_no->proximo = atual;
        ld->inicio = novo_no;
        ld->tamanho++;
        return;
    }

    // Encontrar a posição correta para inserir o novo nó
    while(atual != NULL && atual->dado < novo_dado) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Inserir o novo nó na posição correta
    novo_no->proximo = atual;
    anterior->proximo = novo_no;
    ld->tamanho++;
}

// Função para imprimir os elementos da lista
void imprimir_lista(list_descritor* ld){
    No* atual = ld->inicio;
    printf("Lista criada: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para calcular o valor médio dos nós na lista
double calcular_media(list_descritor* ld) {
    double soma = 0;
    No* atual = ld->inicio;
    while (atual != NULL) {
        soma += atual->dado;
        atual = atual->proximo;
    }
    printf("Média da lista: %.2f\n", (soma/ld->tamanho));
    return soma / ld->tamanho;
}

// Função para remover o primeiro nó com valor imediatamente superior ao valor médio
void remover_maior(list_descritor* ld){
    double media = calcular_media(ld);
    No* atual = ld->inicio;
    No* anterior = NULL;

    while(atual != NULL){
        if(atual->dado > media){
            if(anterior == NULL) {
                ld->inicio = atual->proximo;
            }else{
                anterior->proximo = atual->proximo;
            }
            free(atual);
            ld->tamanho--;
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
    int num_nos, dado, i;
    list_descritor ld;

    inicializar_lista(&ld);

    printf("Informe o número de nós a inserir na lista: ");
    scanf("%d", &num_nos);

    for(i = 0; i < num_nos; i++){
        printf("Informe o valor do nó %d: ", i + 1);
        scanf("%d", &dado);
        inserir_ordenado(&ld, dado);
    }

    imprimir_lista(&ld);

    remover_maior(&ld);

    printf("Lista após remoção: ");
    imprimir_lista(&ld);

    return 0;
}
