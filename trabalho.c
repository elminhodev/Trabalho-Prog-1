#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICOES 1000
#define THRESHOLD 1.5

typedef struct {
    char dataHora[20];
    double consumo;  // Consumo em kWh
    double custo;    // Custo por kWh
} Medicao;

// Funções para manipular dados
void registrarConsumo(Medicao *dados, int *n) {
    if (*n >= MAX_MEDICOES) {
        printf("Limite de medições atingido.\n");
        return;
    }

    printf("Digite a data e hora (YYYY-MM-DD HH:MM): ");
    scanf(" %[^\n]", dados[*n].dataHora);

    printf("Digite o consumo em kWh: ");
    scanf("%lf", &dados[*n].consumo);

    printf("Digite o custo por kWh: ");
    scanf("%lf", &dados[*n].custo);

    (*n)++;
    printf("Medição registrada com sucesso.\n");
}
