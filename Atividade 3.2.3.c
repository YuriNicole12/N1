#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int func_val(int x, int b) {
    if (b == 0) {
        return 0; 
    }

    float result = (float)x / b;
    return (int)round(result);
}

int main() {
    
	int numCasos, b, i, j;

    printf("Digite o numero de casos de teste: ");
    if (scanf("%d", &numCasos) != 1) {
        fprintf(stderr, "Erro ao ler o número de casos.\n");
        return 1;
    }

    for (i = 0; i < numCasos; i++) {
    	
        printf("Digite o valor de b: ");
        if (scanf("%d", &b) != 1) {
            fprintf(stderr, "Erro ao ler o valor de b.\n");
            return 1;
        }

        char mensagemCifrada[101];
        printf("Digite a mensagem cifrada: ");
        if (scanf("%s", mensagemCifrada) != 1) {
            fprintf(stderr, "Erro ao ler a mensagem cifrada.\n");
            return 1;
        }

        int len = strlen(mensagemCifrada);
        char mensagemDecifrada[101];
        int indexDecifrado = 0;

        for (j = 0; j < len - 1; j += 2) {
            if (isdigit(mensagemCifrada[j]) && isdigit(mensagemCifrada[j + 1])) {

                int valorDecimal = (mensagemCifrada[j] - '0') * 10 + (mensagemCifrada[j + 1] - '0');
                int caractereDecifrado = func_val(valorDecimal, b);

                if (caractereDecifrado != 0) {
                    mensagemDecifrada[indexDecifrado++] = (char)caractereDecifrado;
                }
            }
        }

        mensagemDecifrada[indexDecifrado] = '\0'; 

        if (indexDecifrado > 0) {
            printf("Mensagem decifrada: %s\n", mensagemDecifrada);
        } else {
            printf("Nenhum caractere decifrado.\n");
        }
    }

    return 0;
}

