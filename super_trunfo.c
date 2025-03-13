#include <stdio.h>

// Estrutura para guardar as informações de uma cidade
typedef struct {
    char estado;            // Letra do estado (A-H)
    char codigo[4];         // Código da carta (ex: A01)
    char nome[50];          // Nome da cidade
    int populacao;          // População da cidade
    float area;             // Área da cidade (em km²)
    float pib;              // PIB da cidade (em bilhões de reais)
    int pontos_turisticos;  // Número de pontos turísticos
} Carta;

// Função para cadastrar as informações de uma cidade
void cadastrarCarta(Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);
    
    printf("Digite a letra do estado (A-H): ");
    scanf(" %c", &carta->estado);  // Recebe a letra do estado
    while(getchar() != '\n'); // Limpa o buffer para evitar problemas com a entrada

    printf("Digite o código da carta (ex: A01): ");
    scanf("%3s", carta->codigo);   // Recebe o código da carta
    while(getchar() != '\n'); // Limpa o buffer

    printf("Digite o nome da cidade: ");
    fgets(carta->nome, 50, stdin);  // Recebe o nome da cidade
    carta->nome[strcspn(carta->nome, "\n")] = 0; // Remove o '\n' do nome

    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);  // Recebe a população da cidade

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);  // Recebe a área da cidade

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta->pib);   // Recebe o PIB da cidade

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);  // Recebe o número de pontos turísticos
}

// Função para mostrar as informações de uma cidade cadastrada
void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    // Exibe o estado
    printf("Estado: %c\n", carta.estado); 
    
    printf("Código: %s\n", carta.codigo);  
     // Exibe o nome da cidade
    printf("Nome da Cidade: %s\n", carta.nome); 
     // Exibe a população
    printf("População: %d\n", carta.populacao); 
    // Exibe a área
    printf("Área: %.2f km²\n", carta.area);  
     // Exibe o PIB
    printf("PIB: %.2f bilhões de reais\n", carta.pib); 
     // Exibe o número de pontos turísticos
    printf("Número de Pontos Turísticos: %d\n", carta.pontos_turisticos); 
}

int main() {
    const int n = 2;  // cadastrar 2 cidades
    
  // armazena cartas
    Carta cartas[n];

    // Cadastra  2 cidades
    for (int i = 0; i < n; i++) {
        cadastrarCarta(&cartas[i], i + 1);
    }

    // Exibe as cartas
    printf("\n===== CARTAS CADASTRADAS =====\n");
    for (int i = 0; i < n; i++) {
        exibirCarta(cartas[i], i + 1);
    }

    return 0;
}
