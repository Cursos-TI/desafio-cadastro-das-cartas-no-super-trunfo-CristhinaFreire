#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional; // Novo atributo
    float pib_per_capita;         // Novo atributo
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

    // Nível Aventureiro: Cálculo dos novos atributos
    if (carta->area != 0) {
        carta->densidade_populacional = carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }

    if (carta->populacao != 0) {
        carta->pib_per_capita = carta->pib / carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }
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

    // Nível Aventureiro: Exibir os novos atributos calculados
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per Capita: %.2f bilhões de reais por habitante\n", carta.pib_per_capita);
}

int main() {
    const int n = 2; // Continua limitando para apenas 2 cartas

    Carta carta1, carta2; // Declaração individual para evitar laços
    
    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Exibição das cartas cadastradas
    printf("\n===== CARTAS CADASTRADAS =====\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}
