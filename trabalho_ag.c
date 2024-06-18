#include <stdio.h> // Funções de entrada e saída (ex: printf)
#include <stdlib.h> // Alocação de memória, controle de processos, conversões e outras.
#include <math.h> // Funções matemáticas
#include <time.h> // Manipulação de tempo e data

// Definição de constantes
#define TAMANHO_VETOR 10
#define TAMANHO_POPULACAO 100

// Estrutura do individuo 
struct Individuo{
    int Individuo[TAMANHO_VETOR];  
    float Valor; // Custo da Rota
};

struct Ponto{
    int Id; // Inteiro identificador do ponto
    float PX; // Latitude e Longitude
    float PY;
};

// Função para calcular o custo da rota para um indivíduo
float calcular_custo(struct Individuo *individuo, float distancias[TAMANHO_VETOR][TAMANHO_VETOR]){
    float custo = 0.0;
    int i;
    
    // Percorre os pontos do indivíduo
    for(i = 0; i < TAMANHO_VETOR - 1; i++){
        custo += distancias[individuo->Individuo[i]][individuo->Individuo[i + 1]];
    }
    // Adiciona a distância de volta ao ponto inicial
    custo += distancias[individuo->Individuo[TAMANHO_VETOR - 1]][individuo->Individuo[0]];
    
    return custo;
}

// Função de comparação para ordenar os indivíduos pelo campo Valor
int comparar(const void *a, const void *b){
    struct Individuo *indivA = (struct Individuo *)a;
    struct Individuo *indivB = (struct Individuo *)b;
    
    // Compara os custos dos indivíduos
    return (indivA->Valor - indivB->Valor);
}

// Função para inicializar pontos com valores aleatórios
void inicializar_pontos(struct Ponto pontos[TAMANHO_VETOR]){
    int i;
    
    // Gera IDs e coordenadas aleatórias para os pontos
    for(i = 0; i < TAMANHO_VETOR; i++){
        pontos[i].Id = i + 1; // IDs coincidindo com a posição no vetor
        pontos[i].PX = (float)rand() / RAND_MAX * 180 - 90; // Latitude aleatória entre -90 e 90
        pontos[i].PY = (float)rand() / RAND_MAX * 360 - 180; // Longitude aleatória entre -180 e 180
    }
}

// Função para calcular a matriz de distâncias entre pontos
void calcular_matriz_distancias(struct Ponto pontos[TAMANHO_VETOR], float distancias[TAMANHO_VETOR][TAMANHO_VETOR]){
    int i, j;
    
    // Calcula a distância Euclidiana entre todos os pares de pontos
    for(i = 0; i < TAMANHO_VETOR; i++) {
        for(j = 0; j < TAMANHO_VETOR; j++){
            float dx = pontos[j].PX - pontos[i].PX;
            float dy = pontos[j].PY - pontos[i].PY;
            distancias[i][j] = sqrt(dx * dx + dy * dy); // Armazena a distância na matriz
        }
    }
}

// Função para inicializar a população de indivíduos
void inicializar_populacao(struct Individuo populacao[TAMANHO_POPULACAO], float distancias[TAMANHO_VETOR][TAMANHO_VETOR]){
    int i, j;
    
    // Gera indivíduos com rotas aleatórias e calcula o custo de cada rota
    for(i = 0; i < TAMANHO_POPULACAO; i++){
        // Inicializa a rota com os IDs dos pontos
        for (j = 0; j < TAMANHO_VETOR; j++){
            populacao[i].Individuo[j] = j;
        }
        
        // Embaralha a rota usando o algoritmo de Fisher-Yates
        for(j = TAMANHO_VETOR - 1; j > 0; j--){
            int temp, randomIndex;
            randomIndex = rand() % (j + 1);
            temp = populacao[i].Individuo[j];
            populacao[i].Individuo[j] = populacao[i].Individuo[randomIndex];
            populacao[i].Individuo[randomIndex] = temp;
        }
        
        // Calcula o custo da rota para o indivíduo atual
        populacao[i].Valor = calcular_custo(&populacao[i], distancias);
    }
}

// Função para exibir a população ordenada
void exibir_populacao(struct Individuo populacao[TAMANHO_POPULACAO]){
    int i, j;
    
    // Exibe a população ordenada pelo custo da rota
    printf("Populacao ordenada pelo campo Valor:\n");
    for(i = 0; i < TAMANHO_POPULACAO; i++){
        printf("Individuo %d: ", i + 1);
        for (j = 0; j < TAMANHO_VETOR; j++){
            printf("%d ", populacao[i].Individuo[j] + 1); // Mostra os IDs dos pontos
        }
        printf("Custo: %.2f\n", populacao[i].Valor); // Mostra o custo da rota
    }
}

int main(){
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    
    struct Ponto pontos[TAMANHO_VETOR];
    inicializar_pontos(pontos); // Inicializa os pontos com coordenadas aleatórias
    
    float distancias[TAMANHO_VETOR][TAMANHO_VETOR];
    calcular_matriz_distancias(pontos, distancias); // Calcula a matriz de distâncias entre os pontos
    
    struct Individuo populacao[TAMANHO_POPULACAO];
    inicializar_populacao(populacao, distancias); // Inicializa a população de indivíduos
    
    qsort(populacao, TAMANHO_POPULACAO, sizeof(struct Individuo), comparar); // Ordena a população pelo custo da rota
    
    exibir_populacao(populacao); // Exibe a população ordenada
    
    return 0;
}
