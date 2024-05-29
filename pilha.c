#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de nó da pilha
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* novoNo(int data) {
    struct Node* no = (struct Node*)malloc(sizeof(struct Node));
    if (no == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    no->data = data;
    no->next = NULL;
    return no;
}

// Definição da estrutura de pilha
struct Pilha {
    struct Node* topo;
};

// Função para inicializar a pilha
void inicializarPilha(struct Pilha* pilha) {
    pilha->topo = NULL;
}

// Função para verificar se a pilha está vazia
int estaVazia(struct Pilha* pilha) {
    return (pilha->topo == NULL);
}

// Função para empilhar um valor na pilha
void empilhar(struct Pilha* pilha, int data) {
    struct Node* no = novoNo(data);
    no->next = pilha->topo;
    pilha->topo = no;
}

// Função para desempilhar um valor da pilha
int desempilhar(struct Pilha* pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return -1; // Valor de erro
    }
    int data = pilha->topo->data;
    struct Node* temp = pilha->topo;
    pilha->topo = pilha->topo->next;
    free(temp);
    return data;
}

// Função para imprimir os elementos da pilha
void imprimirPilha(struct Pilha* pilha) {
    struct Node* atual = pilha->topo;
    printf("\n---------PILHA---------\n");
    while (atual != NULL) {
        printf("%d\n", atual->data);
        atual = atual->next;
    }
    printf("\n------FIM DA PILHA-----\n");
}

int main() {
    struct Pilha pilha;
    inicializarPilha(&pilha);
    int escolha, valor;

    do {
        printf("\nEscolha uma operação:\n");
        printf("0 - Sair\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir pilha\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
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
                imprimirPilha(&pilha);
                break;
            default:
                printf("Escolha inválida! Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
