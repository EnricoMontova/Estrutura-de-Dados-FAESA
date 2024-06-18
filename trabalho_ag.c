#include <stdio.h> // Fun��es de entrada e sa�da (ex: printf)
#include <stdlib.h> // Aloca��o de mem�ria, controle de processos, convers�es e outras.
#include <math.h> // Fun��es matem�ticas
#include <time.h> // Manipula��o de tempo e data

// Defini��o de constantes
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

// Fun��o para calcular o custo da rota para um indiv�duo
float calcular_custo(struct Individuo *individuo, float distancias[TAMANHO_VETOR][TAMANHO_VETOR]){
    float custo = 0.0;
    int i;
    
    // Percorre os pontos do indiv�duo
    for(i = 0; i < TAMANHO_VETOR - 1; i++){
        custo += distancias[individuo->Individuo[i]][individuo->Individuo[i + 1]];
    }
    // Adiciona a dist�ncia de volta ao ponto inicial
    custo += distancias[individuo->Individuo[TAMANHO_VETOR - 1]][individuo->Individuo[0]];
    
    return custo;
}

// Fun��o de compara��o para ordenar os indiv�duos pelo campo Valor
int comparar(const void *a, const void *b){
    struct Individuo *indivA = (struct Individuo *)a;
    struct Individuo *indivB = (struct Individuo *)b;
    
    // Compara os custos dos indiv�duos
    return (indivA->Valor - indivB->Valor);
}

// Fun��o para inicializar pontos com valores aleat�rios
void inicializar_pontos(struct Ponto pontos[TAMANHO_VETOR]){
    int i;
    
    // Gera IDs e coordenadas aleat�rias para os pontos
    for(i = 0; i < TAMANHO_VETOR; i++){
        pontos[i].Id = i + 1; // IDs coincidindo com a posi��o no vetor
        pontos[i].PX = (float)rand() / RAND_MAX * 180 - 90; // Latitude aleat�ria entre -90 e 90
        pontos[i].PY = (float)rand() / RAND_MAX * 360 - 180; // Longitude aleat�ria entre -180 e 180
    }
}

// Fun��o para calcular a matriz de dist�ncias entre pontos
void calcular_matriz_distancias(struct Ponto pontos[TAMANHO_VETOR], float distancias[TAMANHO_VETOR][TAMANHO_VETOR]){
    int i, j;
    
    // Calcula a dist�ncia Euclidiana entre todos os pares de pontos
    for(i = 0; i < TAMANHO_VETOR; i++) {
        for(j = 0; j < TAMANHO_VETOR; j++){
            float dx = pontos[j].PX - pontos[i].PX;
            float dy = pontos[j].PY - pontos[i].PY;
            distancias[i][j] = sqrt(dx * dx + dy * dy); // Armazena a dist�ncia na matriz
        }
    }
}

// Fun��o para inicializar a popula��o de indiv�duos
void inicializar_populacao(struct Individuo populacao[TAMANHO_POPULACAO], float distancias[TAMANHO_VETOR][TAMANHO_VETOR]){
    int i, j;
    
    // Gera indiv�duos com rotas aleat�rias e calcula o custo de cada rota
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
        
        // Calcula o custo da rota para o indiv�duo atual
        populacao[i].Valor = calcular_custo(&populacao[i], distancias);
    }
}

// Fun��o para exibir a popula��o ordenada
void exibir_populacao(struct Individuo populacao[TAMANHO_POPULACAO]){
    int i, j;
    
    // Exibe a popula��o ordenada pelo custo da rota
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
    srand(time(NULL)); // Inicializa o gerador de n�meros aleat�rios
    
    struct Ponto pontos[TAMANHO_VETOR];
    inicializar_pontos(pontos); // Inicializa os pontos com coordenadas aleat�rias
    
    float distancias[TAMANHO_VETOR][TAMANHO_VETOR];
    calcular_matriz_distancias(pontos, distancias); // Calcula a matriz de dist�ncias entre os pontos
    
    struct Individuo populacao[TAMANHO_POPULACAO];
    inicializar_populacao(populacao, distancias); // Inicializa a popula��o de indiv�duos
    
    qsort(populacao, TAMANHO_POPULACAO, sizeof(struct Individuo), comparar); // Ordena a popula��o pelo custo da rota
    
    exibir_populacao(populacao); // Exibe a popula��o ordenada
    
    return 0;
}
