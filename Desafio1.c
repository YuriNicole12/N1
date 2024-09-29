#include <stdio.h>
#include <math.h>
#include <string.h>

double calcular_f(int x, int b) {
    double a0 = 186752;
    double a1 = -148235;
    double a2 = 34504.9;
    double a3 = -3509.1;
    double a4 = 0.183166;
    double a5 = -0.00513554;
    double a6 = 0.0000735464;
    double a7 = -4.22038 * pow(10,-7);

    return a0 + (a1 + b) * x + a2 * pow(x, 2) + a3 * pow(x, 3) +
           a4 * pow(x, 4) + a5 * pow(x, 5) +
           a6 * pow(x, 6) + a7 * pow(x, 7);
}

int hex_para_decimal(char c1, char c2) {
    int d1, d2;

    if (c1 >= '0' && c1 <= '9') {
        d1 = c1 - '0';
    } else if (c1 >= 'A' && c1 <= 'F') {
        d1 = c1 - 'A' + 10;
    } else {
        d1 = c1 - 'a' + 10;
    }

    if (c2 >= '0' && c2 <= '9') {
        d2 = c2 - '0';
    } else if (c2 >= 'A' && c2 <= 'F') {
        d2 = c2 - 'A' + 10;
    } else {
        d2 = c2 - 'a' + 10;
    }

    return d1 * 16 + d2;
}

int main() {
    int num_mensagens, b, i, j;
    char mensagem[101];

    printf("Digite o número de mensagens interceptadas: ");
    scanf("%d", &num_mensagens);

    for ( i = 0; i < num_mensagens; i++) {
        printf("Digite o valor de b para a mensagem %d: ", i + 1);
        scanf("%d", &b);

        printf("Digite a mensagem codificada em hexadecimal (100 caracteres): ");
        scanf("%s", mensagem);

        int len = strlen(mensagem);
        int posicao = 1;

        for ( j = 0; j < len; j += 2) {
            if (mensagem[j] == '0' && mensagem[j + 1] == '0') {
                break;
            }

            int valor_ascii = hex_para_decimal(mensagem[j], mensagem[j + 1]);
            double valor_f = calcular_f(posicao, b);

            if ((int)valor_f % 2 == 0) {
                printf("%c", valor_ascii);
            }

            posicao++;
        }

        printf("\n");
    }

    return 0;
}
