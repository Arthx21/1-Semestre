#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void matriz_ler(char *nome, int ***matriz, int *lin, int *col) 
{
    FILE* arquivo;
    arquivo = fopen(nome, "r");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fscanf(arquivo, "%d %d", lin, col);

    *matriz = malloc((*lin) * sizeof(int*));
    for (int i = 0; i < *lin; i++) 
    {
        (*matriz)[i] = malloc((*col) * sizeof(int));
    }

    for (int i = 0; i < *lin; i++) 
    {
        for (int j = 0; j < *col; j++) 
        {
            fscanf(arquivo, "%d", &(*matriz)[i][j]);
        }
    }

    fclose(arquivo);
}

int **ler_matriz(char *nome_arquivo, int *linhas, int *colunas) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    fscanf(arquivo, "%d %d", linhas, colunas);
    int **matriz = (int **)malloc((*linhas) * sizeof(int *));
    for (int i = 0; i < *linhas; i++) {
        matriz[i] = (int *)malloc((*colunas) * sizeof(int));
        for (int j = 0; j < *colunas; j++) {
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }

    fclose(arquivo);
    return matriz;
}


void matriz_imprimir(int **matriz, int lin, int col)
{
    for (int i = 0; i < lin; i++) 
    {
        for (int j = 0; j < col; j++)
        {
            printf("[%d] ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimir_matriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void matriz_gravar(char *nome, int **matriz, int lin, int col)
{
    FILE* arquivo;
    arquivo = fopen(nome, "w");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < lin; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            fprintf(arquivo, "%d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

void matriz_tridiagonal_crescente(int n, int ***matriz)
{
    *matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
      {
        (*matriz)[i] = calloc(n, sizeof(int)); 
    }

    int num = 1;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
          {
            if (j >= i - 1 && j <= i + 1)
            { 
                (*matriz)[i][j] = num++;
            }
        }
    }
}

void matriz_tridiagonal_secundaria_decrescente(int n, int ***matriz) 
{
    *matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) 
    {
        (*matriz)[i] = calloc(n, sizeof(int)); 
    }

    int num = n * 3 - 2; 
    for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++) 
        {
            if (j == n - i - 1 || j == n - i || j == n - i - 2) 
            { 
                (*matriz)[i][j] = num--;
            }
        }
    }
}

int ehPotenciaPorLinha(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        int base = matriz[i][1];
        for (int j = 2; j < colunas; j++) {
            if (matriz[i][j] != pow(base, j)) {
                return 0;
            }
        }
    }
    return 1;
}

int ehPotenciaPorColuna(int **matriz, int linhas, int colunas) {
    for (int j = 0; j < colunas; j++) {
        int base = matriz[1][j];
        for (int i = 2; i < linhas; i++) {
            if (matriz[i][j] != pow(base, i)) {
                return 0;
            }
        }
    }
    return 1;
}

void liberar_matriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}