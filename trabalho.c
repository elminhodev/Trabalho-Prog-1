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
    printf("Mediçao registrada com sucesso.\n");
}

void salvarMedicoesArquivo(Medicao *dados, int n, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "%s,%.2lf,%.2lf\n", dados[i].dataHora, dados[i].consumo, dados[i].custo);
    }
    fclose(arquivo);
    printf("Dados salvos no arquivo '%s'.\n", nomeArquivo);
}

double calcularMedia(Medicao *dados, int n) {
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += dados[i].consumo;
    }
    return soma / n;
}
