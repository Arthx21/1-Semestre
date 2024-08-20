#include <stdio.h>
#include <stdlib.h>

void imprimir_array(int *array)
{
  for (int i = 0; i < array[0]; i++)
    {
      printf("[%d] ", array[i]);
    }  
  printf ("\n\n");
}

bool ehDescrecente(int *array, int n)
{
  for (int i = 0; i < n-1; i++)
    {
      if (array[i] < array[i + 1])
      {
        return false;
      }
    }
  return true;
}

int* arranjo_inverter(int *array, int n)
{ 
  int aux ;
  for (int i = 0; i < n/2; i++)
    {
      aux = array[i];
      array[i] = array[n - i - 1];
      array[n - i - 1] = aux;    
    }
  return (array);
}

void arranjo_ler(char *nome, int **array)
{
  FILE* arquivo;
  int n;

  arquivo = fopen (nome, "r");

  fscanf (arquivo, "%d", &n);

  *array = malloc((n + 1) * sizeof(int));
  (*array)[0] = n + 1;

  for (int i = 1; i < n + 1; i++)
    {
      fscanf (arquivo, "%d", &((*array)[i]));
    }

  fclose (arquivo);
}

float procurarMediana(int *array)
{
  float media = 0;

  if (array[0] % 2 == 0)
  {
    media = (array[(array[0]/2) + 1] + array[(array[0]/2) - 1])/2;
  }
  else
  {
    int aux = array[0]/2;
    media = array[aux];
  }

  return media;
}

void arranjo_filtrar(int **array3, int *array1, int *array2)
{
    int aux = 1; 
    *array3 = malloc(2 * sizeof(int)); 

    for (int i = 1; i <= array1[0]; i++) 
    {
        for (int j = 1; j <= array2[0]; j++) 
        {
            if (array1[i] == array2[j])
            {
               (*array3)[aux] = array1[i]; 
               aux++;
               *array3 = realloc(*array3, (aux + 1) * sizeof(int));
                break; 
            }
        }
    }
    (*array3)[0] = aux - 2; 
}

void arranjo_gravar (char *nome, int *array)
{
  FILE* arquivo;

  arquivo = fopen (nome, "w");

  fprintf (arquivo, "%d\n", array[0]);

  for (int i = 1; i <= array[0]; i++)
    {
      fprintf (arquivo, "%d\n", array[i]);
    }
  fclose (arquivo);
}

int arranjo_paraDecimal(int *array)
{
  int decimal = 0;
  for (int i = 0; i < 4; i++) {
      decimal += array[i] * (1 << (4 - i - 1));
  }
  return decimal;
}