#include <stdio.h>
#include <string.h>

int main() {
    // Dados fixos das cartas
    char nome1[] = "Brasil";
    int populacao1 = 213000000;
    float area1 = 8515767.0;
    float pib1 = 2490.0;
    int pontos1 = 25;
    float densidade1 = populacao1 / area1;

    char nome2[] = "Argentina";
    int populacao2 = 45100000;
    float area2 = 2780400.0;
    float pib2 = 487.0;
    int pontos2 = 18;
    float densidade2 = populacao2 / area2;

    int atributo1, atributo2;

    printf("=== SUPER TRUNFO DOS PAÍSES (NÍVEL MESTRE) ===\n\n");
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &atributo1);

    // Menu dinâmico para segundo atributo
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i == atributo1) continue; // Oculta já escolhido
        switch(i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos Turísticos\n"); break;
            case 5: printf("5 - Densidade Demográfica\n"); break;
        }
    }
    printf("Digite sua opção: ");
    scanf("%d", &atributo2);

    // Validando se os atributos são diferentes e válidos
    if (atributo1 < 1 || atributo1 > 5 || atributo2 < 1 || atributo2 > 5 || atributo1 == atributo2) {
        printf("\nErro: Atributos inválidos ou repetidos. Encerrando o programa.\n");
        return 1;
    }

    // Função de comparação por atributo
    float valor1_attr1, valor2_attr1, valor1_attr2, valor2_attr2;
    char nome_attr1[30], nome_attr2[30];

    // Função auxiliar para extrair valores dos atributos
    float obter_valor(int opcao, int carta) {
        switch(opcao) {
            case 1: return carta == 1 ? populacao1 : populacao2;
            case 2: return carta == 1 ? area1 : area2;
            case 3: return carta == 1 ? pib1 : pib2;
            case 4: return carta == 1 ? pontos1 : pontos2;
            case 5: return carta == 1 ? densidade1 : densidade2;
        }
        return 0;
    }

    // Nome do atributo
    void nome_atributo(int codigo, char nome[]) {
        switch(codigo) {
            case 1: strcpy(nome, "População"); break;
            case 2: strcpy(nome, "Área"); break;
            case 3: strcpy(nome, "PIB"); break;
            case 4: strcpy(nome, "Pontos Turísticos"); break;
            case 5: strcpy(nome, "Densidade Demográfica"); break;
        }
    }

    // Obter nomes dos atributos
    nome_atributo(atributo1, nome_attr1);
    nome_atributo(atributo2, nome_attr2);

    // Obter valores
    valor1_attr1 = obter_valor(atributo1, 1);
    valor2_attr1 = obter_valor(atributo1, 2);
    valor1_attr2 = obter_valor(atributo2, 1);
    valor2_attr2 = obter_valor(atributo2, 2);

    // Mostrar valores
    printf("\nComparando %s e %s:\n", nome1, nome2);
    printf("Atributo 1 - %s:\n", nome_attr1);
    printf("  %s: %.2f\n", nome1, valor1_attr1);
    printf("  %s: %.2f\n", nome2, valor2_attr1);

    printf("Atributo 2 - %s:\n", nome_attr2);
    printf("  %s: %.2f\n", nome1, valor1_attr2);
    printf("  %s: %.2f\n", nome2, valor2_attr2);

    // Comparações considerando regra da densidade
    float soma1 = 0, soma2 = 0;

    // Atributo 1
    if (atributo1 == 5) { // densidade = menor vence
        soma1 += (valor1_attr1 < valor2_attr1) ? 1 : 0;
        soma2 += (valor2_attr1 < valor1_attr1) ? 1 : 0;
    } else {
        soma1 += (valor1_attr1 > valor2_attr1) ? 1 : 0;
        soma2 += (valor2_attr1 > valor1_attr1) ? 1 : 0;
    }

    // Atributo 2
    if (atributo2 == 5) {
        soma1 += (valor1_attr2 < valor2_attr2) ? 1 : 0;
        soma2 += (valor2_attr2 < valor1_attr2) ? 1 : 0;
    } else {
        soma1 += (valor1_attr2 > valor2_attr2) ? 1 : 0;
        soma2 += (valor2_attr2 > valor1_attr2) ? 1 : 0;
    }

    // Exibir resultado
    printf("\nSoma dos pontos por comparação:\n");
    printf("%s: %.0f ponto(s)\n", nome1, soma1);
    printf("%s: %.0f ponto(s)\n", nome2, soma2);

    if (soma1 > soma2) {
        printf("\nResultado final: %s venceu!\n", nome1);
    } else if (soma2 > soma1) {
        printf("\nResultado final: %s venceu!\n", nome2);
    } else {
        printf("\nResultado final: Empate!\n");
    }

    return 0;
}
