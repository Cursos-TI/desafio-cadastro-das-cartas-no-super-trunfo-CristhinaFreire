#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);
    printf("Digite a letra do estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome); // Corrigido para ler nome com espaços

    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

int main() {
    int n;
    
    // Solicita a quantidade de cartas que o usuário deseja cadastrar
    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &n);

    // Aloca memória dinamicamente para as cartas
    Carta *cartas = (Carta*) malloc(n * sizeof(Carta));
    if (cartas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Cadastro das cartas
    for (int i = 0; i < n; i++) {
        cadastrarCarta(&cartas[i], i + 1);
    }

    // Exibição das cartas cadastradas
    printf("\n===== CARTAS CADASTRADAS =====\n");
    for (int i = 0; i < n; i++) {
        exibirCarta(cartas[i], i + 1);
    }

    // Libera a memória alocada
    free(cartas);

    return 0;
}
