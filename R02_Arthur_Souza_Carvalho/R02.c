#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "array.h"
#include "matriz.h"

typedef struct {
    char nome[50];
    int codigo;
    float preco;
} Supermercado;

void exercicio1()
{
  printf ("\nExercicio (1)\n");
    int n = 0;
    int aux = 0;
  FILE* arquivo;
  arquivo = fopen("DADOS1.txt", "r");

  fscanf (arquivo, "%d", &n);
  int array[n];

  for (int i = 0; i < n; i++)
    {
      fscanf (arquivo, "%d", &array[i]);
    }

  fclose (arquivo);

  if (ehDescrecente(array, n))
  {
    printf("O array e decrescente\n\n");
  }
  else
  {
    printf("O array NAO e decrescente\n\n");
    
    do
    {
      for (int i = 0; i < n - 1; i++)
        {
          if (array[i] < array[i + 1])
          {
            aux = array[i];
            array[i] = array[i + 1];
            array[i + 1] = aux;
          }
        }
    } while (!ehDescrecente(array, n));
    
  }

  arquivo = fopen ("DECRESCENTE.txt", "w");

  fprintf (arquivo, "%d\n", n);

  for (int i = 0; i < n; i++)
    {
      fprintf (arquivo, "%d\n", array[i]);
    }
  
  fclose (arquivo);
}

void exercicio2()
{
   printf ("\nExercicio (2)\n");

  FILE* arquivo;
  int n = 0;

  arquivo = fopen ("DADOS1.txt" , "r");

  fscanf (arquivo, "%d", &n);

  int array[n];
  
  printf ("Array normal: ");
  for (int i = 0; i < n; i++)
    {
      fscanf (arquivo, "%d", &array[i]);
      printf ("[%d] ", array[i]);
    }

  fclose (arquivo);

  int *array2 = arranjo_inverter(array, n);
  
    arquivo = fopen ("INVERSAO.txt", "w");

    fprintf (arquivo, "%d\n", n);

    printf ("\nArray invertido: ");
    for (int i = 0; i < n; i++)
      {
        fprintf (arquivo, "%d\n", array2[i]);
        printf ("[%d] ", array2[i]);
      } 
    printf ("\n\n");
    free (array2);
    fclose (arquivo);
}

void exercicio3()
{
   printf ("\nExercicio (3)\n");

  int *array;

  arranjo_ler("DADOS1.txt", &array);
  printf ("\n");
  imprimir_array(array);

  float media = procurarMediana(array);

  printf ("A mediana eh: %.2f\n\n", media);
  
}

void exercicio4()
{
   printf ("\nExercicio (4)\n");

  int *array;
  int *array2;
  int *array3;
  arranjo_ler("DADOS1.txt", &array);
  arranjo_ler("DADOS2.txt", &array2);

  arranjo_filtrar(&array3, array, array2);

  printf ("\n");
  for (int i = 1; i <= array3[0] ; i++)
    {
      printf ("[%d] ", array3[i]);
    }
  printf ("\n\n");
  
  arranjo_gravar("FILTRADO.txt", array3);

}

void exercicio5()
{
   printf ("\nExercicio (5)\n");

  int array[4];

  FILE* arquivo;
  arquivo = fopen ("BINARIOS1.txt", "r");

  for (int i = 0; i < 4; i++)
    {
       fscanf (arquivo, "%d", &array[i]); 
    }
  
  fclose(arquivo);

  int x = arranjo_paraDecimal(array);

  printf ("\nO numero em decimal eh: %d\n\n", x);

}

void exercicio6()
{
   printf ("\nExercicio (6)\n");

  int **matriz1;
  int lin1, col1;

  matriz_ler("MATRIZ1.txt", &matriz1, &lin1, &col1);

  printf("Matriz lida de MATRIZ1.txt:\n");
  matriz_imprimir(matriz1, lin1, col1);

  int n;
  printf("\nDigite o valor de N para a matriz quadrada tridiagonal: ");
  scanf("%d", &n);

  int **matriz2;

  matriz_tridiagonal_crescente(n, &matriz2);

  printf("\nMatriz tridiagonal crescente:\n");
  matriz_imprimir(matriz2, n, n);
  printf ("\n");

  matriz_gravar("MATRIZ2.txt", matriz2, n, n);
  
}

void exercicio7()
{
   printf ("\nExercicio (7)\n");

  int **matriz1;
  int lin1, col1;

  matriz_ler("MATRIZ1.txt", &matriz1, &lin1, &col1);

  printf("Matriz lida de MATRIZ1.txt:\n");
  matriz_imprimir(matriz1, lin1, col1);

  int n;
  printf("\nDigite o valor de N para a matriz quadrada tridiagonal: ");
  scanf("%d", &n);

  int **matriz2;

  matriz_tridiagonal_secundaria_decrescente(n, &matriz2);

  printf("\nMatriz tridiagonal secundaria decrescente:\n");
  matriz_imprimir(matriz2, n, n);
  printf ("\n");

  matriz_gravar("MATRIZ2_descrecente.txt", matriz2, n, n);
  
}

void exercicio8()
{
   printf ("\nExercicio (8)\n");

  int linhas, colunas;
  int **matriz = ler_matriz("MATRIZ3.txt", &linhas, &colunas);

  if (matriz != NULL) {
      printf("Matriz lida de MATRIZ3.TXT:\n");
      imprimir_matriz(matriz, linhas, colunas);

      if (ehPotenciaPorLinha(matriz, linhas, colunas)) {
          printf("\nA matriz possui a característica de potências por linha.\n\n");
      } else {
          printf("\nA matriz não possui a característica de potências por linha.\n\n");
      }

      liberar_matriz(matriz, linhas);
  }

  return 0;
  
}

void exercicio9()
{
   printf ("\nExercicio (9)\n");

  int linhas, colunas;
  int **matriz = ler_matriz("MATRIZ4.txt", &linhas, &colunas);

  if (matriz != NULL) {
      printf("Matriz lida de MATRIZ4.TXT:\n");
      imprimir_matriz(matriz, linhas, colunas);

      if (ehPotenciaPorColuna(matriz, linhas, colunas)) {
          printf("\nA matriz possui a característica de potências por coluna.\n\n");
      } else {
          printf("\nA matriz não possui a característica de potências por coluna.\n\n");
      }

      liberar_matriz(matriz, linhas);
  }
}

float calcular_preco_medio(Supermercado *supermercados, int n)
{
  float soma = 0;
  for (int i = 0; i < n; i++)
    {
      soma += supermercados[i].preco;
  }
  return soma / n;
}

void imprimir_inferiores_media(Supermercado *supermercados, int n, float media)
{
  printf("Supermercados com preços inferiores à média:\n");
  for (int i = 0, count = 0; i < n && count < 2; i++)
    {
      if (supermercados[i].preco < media) 
      {
          printf("Nome: %s, Código: %d, Preço: %.2f\n", supermercados[i].nome, supermercados[i].codigo, supermercados[i].preco);
          count++;
      }
  }
}

void exercicio10()
{
   printf ("\nExercicio (10)\n");

  FILE *arquivo = fopen("DADOS3.txt", "r");

  int n;
  fscanf(arquivo, "%d", &n);

  Supermercado *supermercados = (Supermercado *)malloc(n * sizeof(Supermercado));

  for (int i = 0; i < n; i++) 
  {
      fscanf(arquivo, "%s %d %f", supermercados[i].nome, &supermercados[i].codigo, &supermercados[i].preco);
  }

  fclose(arquivo);

  float preco_medio = calcular_preco_medio(supermercados, n);
  printf("Preço médio do produto: %.2f\n", preco_medio);

  imprimir_inferiores_media(supermercados, n, preco_medio);

  printf ("\n\n");

  free(supermercados);
  
}

int main(void) 
{
  int x = 1;
  int y;

  while (x)
    {
      printf ("Exercicio - 1\n");
      printf ("Exercicio - 2\n");
      printf ("Exercicio - 3\n");
      printf ("Exercicio - 4\n");
      printf ("Exercicio - 5\n");
      printf ("Exercicio - 6\n");
      printf ("Exercicio - 7\n");
      printf ("Exercicio - 8\n");
      printf ("Exercicio - 9\n");
      printf ("Exercicio - 10\n");
      printf ("Sair - 0\n");
      
      printf ("Digite um numero de exercicio: ");
      scanf ("%d", &y);
      printf ("\n");
      
      switch (y)
        {  
          case 0 : 
          x = 0;
          printf ("\n\nOBRIGADO POR UTILIZAR O PROGRAM !!!\n\n");
          break;
          
          case 1 :
          exercicio1();
          break;

          case 2 :
          exercicio2();
          break;

          case 3 :
          exercicio3();
          break;

          case 4 :
          exercicio4();
          break;

          case 5 :
          exercicio5();
          break;

          case 6 :
          exercicio6();
          break;

          case 7 :
          exercicio7();
          break;

          case 8 :
          exercicio8();
          break;

          case 9 :
          exercicio9();
          break;

          case 10 :
          exercicio10();
          break;
        }
    }
}


/* Resultados dos testes 

////////////////////////////////////////

Exercicio (1)
O array NAO e decrescente

////////////////////////////////////////

Exercicio (2)
Array normal: [51] [77] [24] [30] [59] [54] [48] [88] [12] [74] 
Array invertido: [74] [12] [88] [48] [54] [59] [30] [24] [77] [51] 

////////////////////////////////////////

Exercicio (3)

[11] [51] [77] [24] [30] [59] [54] [48] [88] [12] [74]

A mediana eh: 59.00

////////////////////////////////////////

Exercicio (4)

[54] [12]   

////////////////////////////////////////

Exercicio (5)

O numero em decimal eh: 11

////////////////////////////////////////

Exercicio (6)
Matriz lida de MATRIZ1.txt:
[5] [2] [3] [4] 
[1] [8] [5] [9] 
[1] [5] [3] [2] 
[11] [22] [33] [66] 

Digite o valor de N para a matriz quadrada tridiagonal: 4

Matriz tridiagonal crescente:
[1] [2] [0] [0] 
[3] [4] [5] [0] 
[0] [6] [7] [8] 
[0] [0] [9] [10] 

////////////////////////////////////////

Exercicio (7)
Matriz lida de MATRIZ1.txt:
[5] [2] [3] [4] 
[1] [8] [5] [9] 
[1] [5] [3] [2] 
[11] [22] [33] [66] 

Digite o valor de N para a matriz quadrada tridiagonal: 4

Matriz tridiagonal secundaria decrescente:
[0] [0] [10] [9] 
[0] [8] [7] [6] 
[5] [4] [3] [0] 
[2] [1] [0] [0]

////////////////////////////////////////

Exercicio (8)
Matriz lida de MATRIZ3.TXT:
1 1 1 1 
1 2 4 8 
1 3 9 27 
1 4 16 64 

A matriz possui a característica de potências por linha.

////////////////////////////////////////

Exercicio (9)
Matriz lida de MATRIZ4.TXT:
1 1 1 1 
1 2 3 4 
1 4 9 16 
1 8 27 64 

A matriz possui a característica de potências por coluna

////////////////////////////////////////

Exercicio (10)
Preço médio do produto: 12.08
Supermercados com preços inferiores à média:
Nome: Macarrao, Código: 3, Preço: 9.75

////////////////////////////////////////
*/  