#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para verificar se a soma dos quadrados dos dígitos é igual à soma dos cubos dos dígitos
bool verifica_afirmativa(const char *numero) {
    int soma_quadrados = 0;
    int soma_cubos = 0;

    for (int i = 0; numero[i] != '\0'; i++) {
        int digito = numero[i] - '0'; // Convertendo o caractere para o valor do dígito

        soma_quadrados += digito * digito;
        soma_cubos += digito * digito * digito;
    }
    printf ("\n%d\n", soma_cubos);
    printf ("\n%d\n", soma_quadrados);
    return soma_quadrados == soma_cubos;
}

int main() {
    const char *numero = "153"; // Exemplo de número a ser verificado

    if (verifica_afirmativa(numero)) {
        printf("O número %s atende à afirmativa.\n", numero);
    } else {
        printf("O número %s não atende à afirmativa.\n", numero);
    }

    return 0;
}
