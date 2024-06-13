#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAMANHO_VETOR 10
#define TAMANHO_POPULACAO 100

// Definição da estrutura do registro
struct Individuo {
    int Individuo[TAMANHO_VETOR];
    float Valor;
};


// Função para calcular o custo da rota para um indivíduo
float calcularCusto(struct Individuo *individuo, float distancias[TAMANHO_VETOR][TAMANHO_VETOR]) {
    float custo = 0.0;
    int i;
    
    for (i = 0; i < TAMANHO_VETOR - 1; i++) {
        custo += distancias[individuo->Individuo[i]][individuo->Individuo[i + 1]];
    }
    // Adiciona a distância do último ponto de volta ao primeiro ponto para formar um ciclo
    custo += distancias[individuo->Individuo[TAMANHO_VETOR - 1]][individuo->Individuo[0]];
    return custo;
}

// Função de comparação para ordenar os indivíduos pelo campo Valor
int comparar(const void *a, const void *b) {
    struct Individuo *indivA = (struct Individuo *)a;
    struct Individuo *indivB = (struct Individuo *)b;
    return (indivA->Valor - indivB->Valor);
}

int main() {
    // Declaração do vetor de pontos
    struct Ponto {
        int Id;
        float PX;
        float PY;
    } Pontos[TAMANHO_VETOR];
    
    int i, j;

    // Preenchendo o vetor com valores aleatórios
    for (i = 0; i < TAMANHO_VETOR; i++) {
        Pontos[i].Id = i + 1; // IDs coincidindo com a posição no vetor
        Pontos[i].PX = (float)rand() / RAND_MAX * 180 - 90; // Exemplo: latitude aleatória entre -90 e 90
        Pontos[i].PY = (float)rand() / RAND_MAX * 360 - 180; // Exemplo: longitude aleatória entre -180 e 180
    }

    // Criando e preenchendo a matriz de distâncias
    float Dist[TAMANHO_VETOR][TAMANHO_VETOR];
    for (i = 0; i < TAMANHO_VETOR; i++) {
        for (j = 0; j < TAMANHO_VETOR; j++) {
            // Calcula a distância euclidiana entre os pontos i e j
            float dx = Pontos[j].PX - Pontos[i].PX;
            float dy = Pontos[j].PY - Pontos[i].PY;
            Dist[i][j] = sqrt(dx * dx + dy * dy);
        }
    }

    // Criando a população inicial
    struct Individuo Populacao[TAMANHO_POPULACAO];
    for (i = 0; i < TAMANHO_POPULACAO; i++) {
        // Inicializa o vetor do indivíduo com valores de 1 a 10 sem repetição
        for (j = 0; j < TAMANHO_VETOR; j++) {
            Populacao[i].Individuo[j] = j + 1;
        }
        // Embaralha o vetor de índices usando o algoritmo de Fisher-Yates
        for (j = TAMANHO_VETOR - 1; j > 0; j--) {
            int temp, randomIndex;
            randomIndex = rand() % (j + 1);
            temp = Populacao[i].Individuo[j];
            Populacao[i].Individuo[j] = Populacao[i].Individuo[randomIndex];
            Populacao[i].Individuo[randomIndex] = temp;
        }
        // Calcula o custo da rota para o indivíduo
        Populacao[i].Valor = calcularCusto(&Populacao[i], Dist);
    }

    // Ordenando a população pelo campo Valor
    qsort(Populacao, TAMANHO_POPULACAO, sizeof(struct Individuo), comparar);

    // Exibindo os indivíduos da população ordenada
    printf("Populacao ordenada pelo campo Valor:\n");
    for (i = 0; i < TAMANHO_POPULACAO; i++) {
        printf("Individuo %d: ", i + 1);
        for (j = 0; j < TAMANHO_VETOR; j++) {
            printf("%d ", Populacao[i].Individuo[j]);
        }
        printf("Custo: %.2f\n", Populacao[i].Valor);
    }

    return 0;
}

