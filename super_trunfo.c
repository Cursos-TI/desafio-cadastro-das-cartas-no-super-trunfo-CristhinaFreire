#include <stdio.h>

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
    while(getchar() != '\n'); // Limpa buffer

    printf("Digite o código da carta (ex: A01): ");
    scanf("%3s", carta->codigo);
    while(getchar() != '\n'); // Limpa buffer

    printf("Digite o nome da cidade: ");
    fgets(carta->nome, 50, stdin);
    carta->nome[strcspn(carta->nome, "\n")] = 0; // Remove o '\n' final

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
    const int n = 2; // Define um limite fixo de 2 cartas
    
    // Declara um array estático para armazenar as cartas
    Carta cartas[n];

    // Cadastro das 2 cartas
    for (int i = 0; i < n; i++) {
        cadastrarCarta(&cartas[i], i + 1);
    }

    // Exibição das cartas cadastradas
    printf("\n===== CARTAS CADASTRADAS =====\n");
    for (int i = 0; i < n; i++) {
        exibirCarta(cartas[i], i + 1);
    }

    return 0;
}
