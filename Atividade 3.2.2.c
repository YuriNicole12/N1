#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef REMOVE_H
#define REMOVE_H

int func_val(int x, int b);

#endif /* REMOVE_H */


int func_val(int x, int b) {
    if (b == 0) {
    	
        return 0; 
    }
    
    double result = (double)x / b; 
    return (int)round(result); 
}

int main() {
    int x, b;

    printf("Digite um valor para x: ");
    scanf("%d", &x);
    printf("Digite um valor para b: ");
    scanf("%d", &b);
    
    int resultado = func_val(x, b);

    if (resultado == 0) {
        printf("O resultado e 0, o caractere deve ser ignorado.\n");
    } else {
        printf("O resultado arredondado e: %d\n", resultado);
    }

    return 0;
}
