#include <stdio.h>

int main() {
    float N1, N2, PPD, EU, N3, nota_final, media_parcial;
    int flagEU, flagN3;

    printf("Digite a nota N1 (0 a 4.5): ");
    scanf("%f", &N1);
    if (N1 < 0 || N1 > 4.5) {
        printf("-Error.Code 3-\n");
        return 3;
    }

    printf("Digite a nota N2 (0 a 4.5): ");
    scanf("%f", &N2);
    if (N2 < 0 || N2 > 4.5) {
        printf("Erro: N2 fora do intervalo permitido.\n");
        return 3;
    }

    printf("Digite a nota PPD (0 a 1): ");
    scanf("%f", &PPD);
    if (PPD < 0 || PPD > 1) {
        printf("Erro: PPD fora do intervalo permitido.\n");
        return 3;
    }

    printf("O estudante realizou o Exame Unificado? (0 = Não, 1 = Sim): ");
    scanf("%d", &flagEU);
    if (flagEU < 0 || flagEU > 1) {
        printf("Erro: Flag EU fora do intervalo permitido.\n");
        return 3;
    }

    if (flagEU == 1) {
        printf("Digite a nota do Exame Unificado (0 a 1): ");
        scanf("%f", &EU);
        if (EU < 0 || EU > 1) {
            printf("Erro: Nota do Exame Unificado fora do intervalo permitido.\n");
            return 3;
        }
    } else {
        EU = 0;
    }

    media_parcial = N1 + N2 + PPD + EU;

    if (media_parcial < 11.1) {
        printf("O estudante realizou a N3? (0 = Não, 1 = Sim): ");
        scanf("%d", &flagN3);
        if (flagN3 < 0 || flagN3 > 1) {
            printf("Erro: Flag N3 fora do intervalo permitido.\n");
            return 3;
        }

        if (flagN3 == 1) {
            printf("Digite a nota N3 (0 a 4.5): ");
            scanf("%f", &N3);
            if (N3 < 0 || N3 > 4.5) {
                printf("Erro: N3 fora do intervalo permitido.\n");
                return 3;
            }

            if (N3 > N1 && N1 <= N2) {
                N1 = N3;
            } else if (N3 > N2 && N2 < N1) {
                N2 = N3;
            }
        }
    }

    nota_final = N1 + N2 + PPD + EU;

    if (nota_final < 0 || nota_final > 10) {
        printf("Erro: Nota final fora do intervalo permitido.\n");
        return 3;
    }

    printf("Nota final: %.2f\n", nota_final);
    if (nota_final >= 7) {
        printf("Aprovado\n");
    } else {
        printf("Reprovado\n");
    }

    return 0;
}