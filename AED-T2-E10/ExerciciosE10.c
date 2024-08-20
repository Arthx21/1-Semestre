/*
  EXERCICIO DO GUIA 10
  Data: 10/05/2024
  autor: Arthur Souza Carvalho

  Program v1.0

*/
#include "io.h"

#define ESCALA 1

void numExercicio(int x) // funcao extra para identificar qual atividade esta sendo apresentada
{
  printf("\nExercicio %d\n\n", x);
}

void metodo0()
{
  IO_println("\n\n\tObrigado por utilizar o meu programa!!!\n");
}

int gerarvalorint(int min, int max)
{
  return rand() % (max - min) + min;
}

void gravararquivo(int n, int *array, char *nome)
{
  FILE *arquivo;

  arquivo = fopen(nome, "w");

  fprintf(arquivo, "%d\n", n);
  for (int i = 0; i < n; i++)
  {
    fprintf(arquivo, "%d\n", array[i]);
  }

  fclose(arquivo);
}

void metodo1()
{
  numExercicio(1);

  int n = 0, min = 0, max = 0;

  n = IO_readint("Digite a quantidades de valores que deseja: ");
  min = IO_readint("Digite o valor minimo do intervalo: ");
  max = IO_readint("Digite o valor maximo do intervalo: ");
  int array[n];

  printf("\nValores gerados: ");
  for (int i = 0; i < n; i++)
  {
    array[i] = gerarvalorint(min, max);
    printf(" [%d]", array[i]);
  }

  gravararquivo(n, array, "DADOS1.txt");

  IO_pause("\nAperte ENTER para continuar");
}

int* lerArraydoArquivo(char *nome)
{
  FILE* arquivo;
  int x = 0;

  arquivo = fopen (nome, "r");

  fscanf (arquivo , "%d", &x);

  int *array = malloc ((x + 1) * sizeof(int));
  array[0] = x;
  for (int i = 1; i <= x; i++)
  {
    fscanf (arquivo, "%d" , &array[i]);
  }
  fclose(arquivo);

  return array;
}

bool arraySearch (int valor, int *array)
{
    for ( int i = 1 ; i <= array[0] ; i++ )
    {
        if ( valor == array[i] )
        {
            return true;
        }
    }
    return false;
}

void metodo2()
{
  numExercicio(2);

  int *array = lerArraydoArquivo("DADOS1.txt");

  for (int i = 1; i <= array[0]; i++)
  {
    printf (" [%d]", array[i]);
  }

    int x = IO_readint ("\nDigite o valor que procura dentro do array: ");

    if (arraySearch(x , array))
    {
        printf ("O valor %d foi encontrado dentro do array", x);
    }
    else
    {
        printf ("O valor %d NAO foi encontrado dentro do array", x);
    }

    free (array);

    IO_pause("\nAperte ENTER para continuar");
}

bool tamanhosArray(int *array1, int *array2)
{
    if (array1[0] == array2[0])
    {
        return true;
    }
    return false;
}

bool arrayCompare (int *array1 , int *array2)
{
    int i = 1;
    for (i = 1; i <= array1[0]; i++);
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }
    return true;
}

void metodo3()
{
  numExercicio(3);

    int *array1 = lerArraydoArquivo("DADOS1.txt");
    int *array2 = lerArraydoArquivo("DADOS2.txt");

    if (tamanhosArray(array1, array2))
    {
        if (arrayCompare(array1, array2))
        {
            printf ("Todos os elementos dos array sao iguais");
        }
        else
        {
            printf ("NEM todos os elementos dos arrays sao iguais");
        }
    }
    else
    {
        printf ("Os arrays possuem tamanhos diferentes e nao se pode fazer a comparacao");
    }

    free (array1);
    free (array2);

    IO_pause("\nAperte ENTER para continuar");
}

int arraySoma (int *array1, int escala, int *array2)
{
    int soma = 0;
    for ( int i = 1; i <= array1[0]; i++)
    {
        soma = soma + (array1[i] + (escala * array2[i]));
    }
    return soma;
}

void metodo4()
{
  numExercicio(4);

    int *array1 = lerArraydoArquivo("DADOS1.txt");
    int *array2 = lerArraydoArquivo("DADOS2.txt");

    printf ("A constante da escala e : %d\n", ESCALA);

    if (tamanhosArray(array1, array2))
    {
        int soma = arraySoma(array1, ESCALA, array2);
        printf ("O valor da soma dos arrays eh: [%d]", soma);
    }
    else
    {
        printf ("Os tamanhos dos arrays nao sao comapativeis");
    }

    IO_pause("\nAperte ENTER para continuar");
}

bool isArrayDescrecente(int *array)
{
    for ( int i = 1 ; i < array[0] ; i++ )
    {
        if (array[i] < array[i + 1])
        {
            return false;
        }
    }
    return true;
}

void metodo5()
{
  numExercicio(5);

    int *array = lerArraydoArquivo("DADOS1.txt");

    if (isArrayDescrecente(array))
    {
        printf ("O array esta em ordem descrecente");
    }
    else
    {
        printf ("NAO esta em ordem descrecente");
    }

    IO_pause("\nAperte ENTER para continuar");
}

void lerMatrizdoArquivo(char *nome, int lin, int col, int matrix [lin][col])
{
  FILE* arquivo;
  arquivo = fopen (nome, "r");

  for (int i = 0; i < lin; i++)
  {
      for (int j = 0; j < col; j++)
      {
          fscanf (arquivo, "%d" , &matrix[i][j]);
      }
  }
  fclose(arquivo);
}

void gravarmatrizarquivo(int n, char *nome)
{
  FILE *arquivo;
  int array[n];

  arquivo = fopen(nome, "w");

  for (int i = 0; i < n; i++)
  {
    array[i] = gerarvalorint(1,100);
    fprintf(arquivo, "%d\n", array[i]);
  }

  fclose(arquivo);
}

int** matrizTransposta( int linhas, int colunas, int matriz[linhas][colunas]) {
    int** transposta = (int**)malloc(colunas * sizeof(int*));
    for (int i = 0; i < colunas; i++) {
        transposta[i] = (int*)malloc(linhas * sizeof(int));
        for (int j = 0; j < linhas; j++) {
            transposta[i][j] = matriz[j][i];
        }
    }
    return transposta;
}

void metodo6()
{
  numExercicio(6);
    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin != col);

    gravarmatrizarquivo(lin * col, "DADOSMATRIZ2.txt");

    int matriz [lin][col];
    int matriz2 [lin][col];
    lerMatrizdoArquivo("DADOSMATRIZ1.txt", lin , col , matriz);
    int** matriz22;
    if (sizeof(matriz) == sizeof(matriz2))
    {
        matriz22 = matrizTransposta( lin, col, matriz);

        for (int i = 0; i < lin ; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf (" %d", matriz22[i][j]);
            }
            printf ("\n");
        }
    }
    else
    {
        printf ("Os tamanhos nao sao compativeis");
    }

    free (matriz22);

    IO_pause("\nAperte ENTER para continuar");
}

bool matrixZero(int lin , int col , int matriz[lin][col])
{
    for (int i = 0; i < lin ; i++)
    {
        for (int j = 0; j < col ; j++)
        {
            if (matriz [i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

void metodo7()
{
  numExercicio(7);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin != col);

    int matriz [lin][col];
    lerMatrizdoArquivo("DADOSMATRIZ1.txt", lin , col , matriz);

    if (matrixZero(lin , col , matriz))
    {
        printf ("So tem valores iguais a zero");
    }
    else
    {
        printf ("NEM todos os valores sao iguais a zero");
    }


    IO_pause("\nAperte ENTER para continuar");
}

bool matrizCompare(int lin , int col, int matriz[lin][col], int matriz2[lin][col])
{
    for (int i = 0; i < lin ; i++)
    {
        for (int j = 0; j < col ; j++)
        {
            if (matriz [i][j] != matriz2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void metodo8()
{
  numExercicio(8);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin != col);

    int matriz [lin][col];
    int matriz2 [lin][col];

    lerMatrizdoArquivo("DADOSMATRIZ1.txt", lin , col , matriz);
    lerMatrizdoArquivo("DADOSMATRIZ2.txt", lin , col , matriz2);

    if (matrizCompare(lin, col, matriz, matriz2))
    {
        printf ("Todos os valores das matrizes sao iguais");
    }
    else
    {
        printf ("NEM todos os valores das matrizes sao iguais");
    }

    IO_pause("\nAperte ENTER para continuar");
}

int matrixAdd (int lin, int col, int matriz[lin][col], int matriz2[lin][col], int ESCALAINVERSA)
{
    int soma = 0;

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            soma = soma + (matriz[i][j] + ((ESCALAINVERSA) * matriz2[i][j]));
        }
    }
    return soma;
}
void metodo9()
{
  numExercicio(9);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin != col);

    int matriz [lin][col];
    int matriz2 [lin][col];

    lerMatrizdoArquivo("DADOSMATRIZ1.txt", lin , col , matriz);
    lerMatrizdoArquivo("DADOSMATRIZ2.txt", lin , col , matriz2);

    int soma = matrixAdd (lin , col , matriz , matriz2, -1);

    printf ("\nA soma das matrizes e [%d]", soma);

    IO_pause("\nAperte ENTER para continuar");
}

int matrixProduct (int lin,int col,int matriz[lin][col],int matriz2[lin][col])
{
    int produto = 0;

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            produto = produto + (matriz[i][j] * matriz2[i][j]);
        }
    }
    return produto;
}

void metodo10()
{
  numExercicio(10);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin != col);

    int matriz [lin][col];
    int matriz2 [lin][col];

    lerMatrizdoArquivo("DADOSMATRIZ1.txt", lin , col , matriz);
    lerMatrizdoArquivo("DADOSMATRIZ2.txt", lin , col , matriz2);

    int produto = matrixProduct (lin, col, matriz, matriz2);

    printf ("\nO produto das matrizes e [%d]", produto);

    IO_pause("\nAperte ENTER para continuar");
}

int main()
{

  int x = 0;

  do
  {

    IO_id("ExerciciosE08 - Programa - v1.0");

    IO_println("Opcoes");
    IO_println("0 - parar");
    IO_println("1 - Metodo_1");
    IO_println("2 - Metodo_2");
    IO_println("3 - Metodo_3");
    IO_println("4 - Metodo_4");
    IO_println("5 - Metodo_5");
    IO_println("6 - Metodo_6");
    IO_println("7 - Metodo_7");
    IO_println("8 - Metodo_8");
    IO_println("9 - Metodo_9");
    IO_println("10 - Metodo_10");
    x = IO_readint("\nEntrar com uma opcao: ");

    switch (x)
    {
    case 0:
      metodo0();
      break;
    case 1:
      metodo1();
      break;
    case 2:
      metodo2();
      break;
    case 3:
      metodo3();
      break;
    case 4:
      metodo4();
      break;
    case 5:
      metodo5();
      break;
    case 6:
      metodo6();
      break;
    case 7:
      metodo7();
      break;
    case 8:
      metodo8();
      break;
    case 9:
      metodo9();
      break;
    case 10:
      metodo10();
      break;
    default:
      IO_pause(IO_concat("Valor diferente das opcoes [0,1,2,3,4,5,6,7,8,9,10] (",
                         IO_concat(IO_toString_d(x), ")")));
    }
  } while (x != 0);

  IO_pause("Apertar ENTER para terminar");
  return (0);
}

/* Resultados dos testes Realizados:

///////////////////////////////////////////

Exercicio 1

Digite a quantidades de valores que deseja: 10
Digite o valor minimo do intervalo: 10
Digite o valor maximo do intervalo: 90

Valores gerados:  [51] [77] [24] [30] [59] [54] [48] [88] [12] [74]

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 2

 [51] [77] [24] [30] [59] [54] [48] [88] [12] [74]
Digite o valor que procura dentro do array: 54
O valor 54 foi encontrado dentro do array

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 3

NEM todos os elementos dos arrays sao iguais

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 4

A constante da escala e : 1
O valor da soma dos arrays eh: [1121]

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 5

NAO esta em ordem descrecente

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 6

Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
 42 68 94
 54 63 55
 98 83 35

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 7

Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
NEM todos os valores sao iguais a zero

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 8

Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
Todos os valores das matrizes sao iguais

Aperte ENTER para continuar

///////////////////////////////////////////  //Se são iguais logo a soma do inverso vai ser 0

Exercicio 9

Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3

A soma das matrizes e [0]

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 10

Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3

O produto das matrizes e [42852]

Aperte ENTER para continuar

///////////////////////////////////////////

*/
