#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definindo a estrutura do n�
typedef struct no{
    int dado;
    struct no* proximo;
}No;

// Definindo a estrutura da lista com descritor
typedef struct DescritorLista{
    int tamanho;
    No* inicio;
}list_descritor;

// Fun��o para inicializar a lista com descritor
void inicializar_lista(list_descritor* ld){
    ld->tamanho = 0;
    ld->inicio = NULL;
}

// Fun��o para inserir um novo n� de forma ordenada na lista
void inserir_ordenado(list_descritor* ld, int novo_dado){
    No* novo_no = (No*)malloc(sizeof(No));
    No* atual = ld->inicio;
    No* anterior = NULL;

    novo_no->dado = novo_dado;
    novo_no->proximo = NULL;

    // Se a lista estiver vazia ou o novo n� deve ser inserido no in�cio
    if(atual == NULL || atual->dado >= novo_dado) {
        novo_no->proximo = atual;
        ld->inicio = novo_no;
        ld->tamanho++;
        return;
    }

    // Encontrar a posi��o correta para inserir o novo n�
    while(atual != NULL && atual->dado < novo_dado) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Inserir o novo n� na posi��o correta
    novo_no->proximo = atual;
    anterior->proximo = novo_no;
    ld->tamanho++;
}

// Fun��o para imprimir os elementos da lista
void imprimir_lista(list_descritor* ld){
    No* atual = ld->inicio;
    printf("Lista criada: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

// Fun��o para calcular o valor m�dio dos n�s na lista
double calcular_media(list_descritor* ld) {
    double soma = 0;
    No* atual = ld->inicio;
    while (atual != NULL) {
        soma += atual->dado;
        atual = atual->proximo;
    }
    printf("M�dia da lista: %.2f\n", (soma/ld->tamanho));
    return soma / ld->tamanho;
}

// Fun��o para remover o primeiro n� com valor imediatamente superior ao valor m�dio
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

    printf("Informe o n�mero de n�s a inserir na lista: ");
    scanf("%d", &num_nos);

    for(i = 0; i < num_nos; i++){
        printf("Informe o valor do n� %d: ", i + 1);
        scanf("%d", &dado);
        inserir_ordenado(&ld, dado);
    }

    imprimir_lista(&ld);

    remover_maior(&ld);

    printf("Lista ap�s remo��o: ");
    imprimir_lista(&ld);

    return 0;
}
