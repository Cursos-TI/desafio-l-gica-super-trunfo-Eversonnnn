#include <stdio.h>

int main() {
    // Declaração das variáveis da Carta 1
    char estado1[3], codigo1[4], nome1[50];
    int populacao1, pontos_turisticos1;
    float area1, pib1;

    // Declaração das variáveis da Carta 2
    char estado2[3], codigo2[4], nome2[50];
    int populacao2, pontos_turisticos2;
    float area2, pib2;

    // Entrada de dados da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado (sigla): ");
    scanf("%s", estado1);
    printf("Código: ");
    scanf("%s", codigo1);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome1);
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Nº de pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Entrada de dados da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado (sigla): ");
    scanf("%s", estado2);
    printf("Código: ");
    scanf("%s", codigo2);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Nº de pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculo da densidade populacional e PIB per capita
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pib_per_capita1 = (pib1 * 1000000000) / populacao1;
    float pib_per_capita2 = (pib2 * 1000000000) / populacao2;

    // Exibição dos dados das cartas
    printf("\n--- Carta 1 ---\n");
    printf("Cidade: %s (%s)\n", nome1, estado1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Pontos turísticos: %d\n", pontos_turisticos1);
    printf("Densidade populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: %.2f reais\n", pib_per_capita1);

    printf("\n--- Carta 2 ---\n");
    printf("Cidade: %s (%s)\n", nome2, estado2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Pontos turísticos: %d\n", pontos_turisticos2);
    printf("Densidade populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: %.2f reais\n", pib_per_capita2);

    // Comparação pelo atributo escolhido: População
    printf("\nComparação de Cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %d\n", nome1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d\n", nome2, estado2, populacao2);

    // Lógica de comparação usando if-else
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
