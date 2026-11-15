#include <stdio.h>

int QTD, Quantidade_de_despesas, opcao;
float Despesas[30];
float Salario, Despesa_total, Maior_Despesa;
float Resumo[2];

int main() {
    while (1) {
        printf("\n===== MEU CONTROLE FINANCEIRO =====\n");
        printf("\n[1] Definir orcamento mensal");
        printf("\n[2] Registrar uma despesa");
        printf("\n[3] Listar despesas");
        printf("\n[4] Ver resumo financeiro");
        printf("\n[5] Sair");

        printf("\nInforme uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 5) {
            printf("\n===========================");
            printf("\nOBRIGADO POR UTILIZAR!");
            break;
        }

        switch (opcao) {
            case 1:
                printf("Informe seu orcamento mensal: ");
                scanf("%f", &Salario);

                while (Salario < 0) {
                    printf("Informe um valor valido!: ");
                    scanf("%f", &Salario);
                }

                printf("\nOrcamento registrado!");
                break;

            case 2:
                if (Quantidade_de_despesas < 30) {
                    char entrada[20];

                    printf("[S] Digite para sair\n");
                    printf("Informe quantas despesas deseja registrar: ");
                    scanf("%19s", entrada);

                    if (entrada[0] == 'S' || entrada[0] == 's') {
                        break;
                    }

                    if (sscanf(entrada, "%d", &QTD) != 1) {
                        printf("Informe um numero valido!");
                        break;
                    }

                    while (QTD + Quantidade_de_despesas > 30 || QTD <= 0) {
                        if (QTD + Quantidade_de_despesas > 30) {
                            printf("\nInforme um valor abaixo de 30, voce registrou: %d Despesas: ", Quantidade_de_despesas);
                            scanf("%d", &QTD);
                        }
                        else {
                            printf("Informe um valor valido!");
                            scanf("%d", &QTD);
                        }
                    }

                    for (int i = 0; i < QTD; i++) {
                        printf("Despesa %d: R$", Quantidade_de_despesas + 1);
                        scanf("%f", &Despesas[Quantidade_de_despesas]);

                        while (Despesas[Quantidade_de_despesas] < 0) {
                            printf("Nao e permitido numeros negativos, informe novamente:\n");
                            printf("Despesa %d: R$", Quantidade_de_despesas + 1);
                            scanf("%f", &Despesas[Quantidade_de_despesas]);
                        }

                        Quantidade_de_despesas++;
                    }
                }
                else {
                    printf("Voce ja registrou o maximo permitido!");
                    break;
                }
                break;

            case 3:
                if (Quantidade_de_despesas == 0) {
                    printf("\nNenhuma despesa cadastrada!");
                    break;
                }

                printf("\n===== DESPESAS CADASTRADAS =====");

                for (int i = 0; i < Quantidade_de_despesas; i++) {
                    printf("\nDespesa %d : R$%.2f", i + 1, Despesas[i]);
                }
                break;

            case 4:
                if (Quantidade_de_despesas <= 0) {
                    printf("REGISTRE UMA DESPESA ANTES DO RESUMO!");
                    break;
                }

                printf("\n==== RESUMO =====");
                printf("\nOrcamento: %.2f", Salario);

                Despesa_total = 0;

                for (int i = 0; i < Quantidade_de_despesas; i++) {
                    Despesa_total += Despesas[i];

                    if (Despesas[i] > Resumo[0]) {
                        Resumo[0] = Despesas[i];
                    }
                }

                Resumo[1] = Despesa_total / Quantidade_de_despesas;

                printf("\nTotal Gasto: R$%.2f", Despesa_total);
                printf("\nSaldo restante: R$%.2f", Salario - Despesa_total);
                printf("\nMaior despesa: %.2f", Resumo[0]);
                printf("\nMedia de gastos: %.2f", Resumo[1]);

                if (Despesa_total <= Salario) {
                    printf("\nSituacao: Dentro do orcamento!");
                }
                else {
                    printf("\nSituacao: Estourou o orcamento!");
                }
                break;

            default:
                printf("Insira um numero valido");
        }
    }

    return 0;
}