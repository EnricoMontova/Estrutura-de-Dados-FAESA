#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de nó da pilha
typedef struct No{
    int data;
    struct No* proximo;
}No;

// Função para criar um novo nó
No* novo_no(int data){
    No* no = (No*)malloc(sizeof(No));
    if (no == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    no->data = data;
    no->proximo = NULL;
    return no;
}

// Definição da estrutura de pilha
typedef struct{
    No* topo;
}Pilha;

// Função para inicializar a pilha
void inicializar_pilha(Pilha* pilha){
    pilha->topo = NULL;
}

// Função para verificar se a pilha está vazia
int esta_vazia(Pilha* pilha){
    return (pilha->topo == NULL);
}

// Função para empilhar um valor na pilha
void empilhar(Pilha* pilha, int data){
    No* no = novo_no(data);
    no->proximo = pilha->topo;
    pilha->topo = no;
}

// Função para desempilhar um valor da pilha
int desempilhar(Pilha* pilha){
    if (esta_vazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return -1; // Valor de erro
    }
    int data = pilha->topo->data;
    No* temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(temp);
    return data;
}

// Função para imprimir os elementos da pilha
void imprimir_pilha(Pilha* pilha){
    No* atual = pilha->topo;
    printf("\n---------PILHA---------\n");
    while (atual != NULL) {
        printf("%d\n", atual->data);
        atual = atual->proximo;
    }
    printf("------FIM DA PILHA-----\n");
}

int main(){
    Pilha pilha;
    inicializar_pilha(&pilha);
    int escolha, valor;

    do{
        printf("\nEscolha uma operacao:\n");
        printf("0 - Sair\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir pilha\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha){
            case 0:
                printf("Encerrando o programa...\n");
                break;
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilhar(&pilha, valor);
                printf("%d empilhado com sucesso.\n", valor);
                break;
            case 2:
                valor = desempilhar(&pilha);
                if (valor != -1)
                    printf("%d desempilhado com sucesso.\n", valor);
                break;
            case 3:
                imprimir_pilha(&pilha);
                break;
            default:
                printf("Escolha inválida! Tente novamente.\n");
        }
    }while (escolha != 0);

    return 0;
}

