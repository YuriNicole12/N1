#include <stdio.h>
#include <limits.h>

int main() {
    
    printf("Tipo                   | Limite Minimo          | Limite Maximo\n");
    printf("-----------------------|------------------------|----------------------\n");
    printf("char                   | %d                   | %d\n", CHAR_MIN, CHAR_MAX);
    printf("int                    | %d            | %d\n", INT_MIN, INT_MAX);
    printf("short int              | %d                 | %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned int           | 0                      | %u\n", UINT_MAX);
    printf("long int               | %ld            | %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long int      | 0                      | %lu\n", ULONG_MAX);
    printf("long long int          | %lld   | %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long int | 0                      | %llu\n", ULLONG_MAX);
    

    char overflowChar = 128; 
    printf("\nExemplo de transbordamento:\n");
    printf("Valor atribuido a char: %d\n", overflowChar);

    return 0;
}
