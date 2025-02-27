#include <stdio.h>
#include <string.h>

// Definindo a estrutura da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float PIB;
    int pontos_turisticos;
    float densidade_populacional;
    float PIB_per_capita;
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcularDados(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->PIB_per_capita = carta->PIB / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta c) {
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.cidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f\n", c.area);
    printf("PIB: %.2f\n", c.PIB);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", c.densidade_populacional);
    printf("PIB per capita: %.2f\n", c.PIB_per_capita);
    printf("\n");
}

int main() {
    // Cadastrando duas cartas
    Carta carta1 = {"São Paulo", "SP", "São Paulo", 12300000, 1521.11, 678.9, 300};
    Carta carta2 = {"Rio de Janeiro", "RJ", "Rio de Janeiro", 6000000, 1200.27, 450.5, 250};

    // Calculando densidade populacional e PIB per capita
    calcularDados(&carta1);
    calcularDados(&carta2);

    // Exibindo os dados das cartas
    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("Carta 2:\n");
    exibirCarta(carta2);

    // Escolhendo o atributo para comparação (neste caso, População)
    char atributo_escolhido[] = "População";
    int valor_carta1 = carta1.populacao;
    int valor_carta2 = carta2.populacao;

    // Comparando as cartas
    printf("Comparação de cartas (Atributo: %s):\n", atributo_escolhido);
    printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.codigo, valor_carta1);
    printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.codigo, valor_carta2);

    if (valor_carta1 > valor_carta2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (valor_carta1 < valor_carta2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: As cartas empataram!\n");
    }

    return 0;
}