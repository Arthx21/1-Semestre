#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fun��o para verificar se a soma dos quadrados dos d�gitos � igual � soma dos cubos dos d�gitos
bool verifica_afirmativa(const char *numero) {
    int soma_quadrados = 0;
    int soma_cubos = 0;

    for (int i = 0; numero[i] != '\0'; i++) {
        int digito = numero[i] - '0'; // Convertendo o caractere para o valor do d�gito

        soma_quadrados += digito * digito;
        soma_cubos += digito * digito * digito;
    }
    printf ("\n%d\n", soma_cubos);
    printf ("\n%d\n", soma_quadrados);
    return soma_quadrados == soma_cubos;
}

int main() {
    const char *numero = "153"; // Exemplo de n�mero a ser verificado

    if (verifica_afirmativa(numero)) {
        printf("O n�mero %s atende � afirmativa.\n", numero);
    } else {
        printf("O n�mero %s n�o atende � afirmativa.\n", numero);
    }

    return 0;
}
