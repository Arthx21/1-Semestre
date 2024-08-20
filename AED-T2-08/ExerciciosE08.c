/*
  EXERCICIO DO GUIA 08
  Data: 24/04/2024
  autor: Arthur Souza Carvalho

  Program v1.0

*/  // Todas a funções q criei para uma certa atividade a suas funções estão acima delas.
#include "io.h"

void numExercicio(int x)   //funcao extra para identificar qual atividade esta sendo apresentada
{
  printf ("\nExercicio %d\n", x);
}


void metodo0() {
  IO_println ("\n\n\tObrigado por utilizar o meu programa!!!\n");
}

void arrayPares(int n, int array[], int i)
{
  if (n > 0)
  {
    array[i] = i;
    if (array[i] > 0 && array[i] % 2 == 0)
    {
      array[i] = i;
      printf ("%d ", array[i]);
      return arrayPares(n - 1, array, i + 1 );
    }
    else
    {
      return arrayPares(n, array, i + 1);
    }
  }
}


void metodo1() {
  numExercicio(1);
  int n = 0;

  do  { n = IO_readint ("Insira a quantidade de valores: "); }
  while ( n < 0 );

  int array[n];
  arrayPares(n, array, 0);
  printf ("\n");

  IO_pause ("Aperte ENTER para continuar");
}

void lerArquivoint(FILE* arquivo, int *array, int n)
{
    for (int i = 0; i < n;)
    {
        fscanf (arquivo, "%d", &array[i]);
        if (array[i] > 0 && array[i] % 2 == 0)
        {
            printf ("%d ", array[i]);
            i++;
        }
    }
}

void metodo2() {
    numExercicio(2);

    int n = IO_readint ("Insira a quantidade de valores: ");
    int array[n];

    FILE* arquivo;

    arquivo = fopen ("numerosTeste.txt", "r");
    lerArquivoint(arquivo, array, n);
    fclose (arquivo);

    arquivo = fopen ("Metodo2.txt", "w");
    fprintf (arquivo, "Tamanho: %d\n Dados:\n", n);
    for (int i = 0; i < n; i++)
    {
        fprintf (arquivo, "%d\n", array[i]);
    }
    fclose (arquivo);


    printf ("\n");
    IO_pause ("Aperte ENTER para continuar");
}

int gerarInt (int max, int min)
{
    return rand() % (max - min + 1) + min;
}

void metodo3() {
    numExercicio(3);

    int n = IO_readint ("Insira a quantidade de valores: ");
    int array[n];

    int max = IO_readint ("Insira o tamanho maximo do intervalo: ");
    int min = IO_readint ("Insira o tamanho minimo do intervalo: ");

    FILE* arquivo;

    arquivo = fopen ("DADOS.txt", "w");
    fprintf (arquivo, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        array[i] = gerarInt (max, min);
        printf ("[%d] ", array[i]);
        fprintf (arquivo, "%d\n", array[i]);
    }

    fclose (arquivo);

    IO_pause ("Aperte ENTER para continuar");
}

int LerArquivo(int n, FILE* arquivo)
{
    fscanf (arquivo,"%d", &n);
    return n;
}

int acharMenorPar(int n, int *array)
{
    int menor = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {
            if (menor > array[i])
            {
                menor = array[i];
            }
        }
    }

    return menor;
}

void metodo4() {
    numExercicio(4);

    FILE* arquivo;

    arquivo = fopen("DADOS.txt", "r");

    int n = 0;
    fscanf (arquivo, "%d", &n);
    int array[n];

    for (int i = 0; i < n; i++)
    {
        array[i] = LerArquivo(n, arquivo);
        printf ("%d ", array[i]);
    }

    fclose (arquivo);
    printf ("\n");

    int menor = acharMenorPar(n, array);

    printf ("\nMenor par: [%d]", menor);


    IO_pause ("\nAperte ENTER para continuar");
}

int achaMaiorImpar (int n ,int *array)
{
    int maior = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 != 0)
        {
            if (maior < array[i])
            {
                maior = array[i];
            }
        }
    }

    return maior;
}



void metodo5() {
    numExercicio(5);

    FILE* arquivo;

    arquivo = fopen("DADOS.txt", "r");

    int n = 0;
    fscanf (arquivo, "%d", &n);
    int array[n];

    for (int i = 0; i < n; i++)
    {
        array[i] = LerArquivo(n, arquivo);
        printf ("%d ", array[i]);
    }

    fclose (arquivo);
    printf ("\n");

    int maior = achaMaiorImpar(n, array);

    printf ("\nMaior Impar: [%d]", maior);

    IO_pause ("\nAperte ENTER para continuar");
}

double acharMedia(int n , int *array)
{
    double media = 0;
    double soma = 0;

    for (int i = 0; i < n; i++)
    {
        soma = soma + array[i];
    }

    media = soma / n;

    return media;
}

void metodo6() {
    numExercicio(6);

    FILE* arquivo;
    FILE* arquivo2;
    arquivo = fopen("DADOS.txt", "r");

    int n = 0;
    fscanf (arquivo, "%d", &n);
    int array[n];

    for (int i = 0; i < n; i++)
    {
        array[i] = LerArquivo(n, arquivo);
        printf ("%d ", array[i]);
    }
    fclose (arquivo);
    printf ("\n");

    double media = acharMedia(n , array);

    printf ("\nMedia dos valores: [%.2lf]", media);

    arquivo2 = fopen ("maiores.txt", "w");
    arquivo = fopen ("menoresiguais.txt", "w");
    for (int i = 0; i < n; i++)
    {
        if (array[i] <= media)
        {
            fprintf(arquivo,"%d\n",array[i]);
        }
        else
        {
            fprintf(arquivo2,"%d\n",array[i]);
        }
    }
    fclose(arquivo);
    fclose(arquivo2);

    IO_pause ("\nAperte ENTER para continuar");
}

int arrayDescrecente(int n , int *array)
{
    int x = 0;
    int j = 1;
    for (int i = 0; i < n-1; i++)
    {
        if (array[i] >= array[j])
        {
            j++;
            x = 1;
        }
        else if (array[i] < array[j])
        {
            x = 0;
            return x;
        }
    }

    return x;
}


void metodo7() {
    numExercicio(7);

    int n = IO_readint ("Insira a quantidade de valores: ");
    int array[n];

    printf ("\nDigite %d valores: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &array[i]);
    }

    int x = arrayDescrecente(n , array);

    if (x)
    {
      printf ("\nEsta ordernado em ordem descrecente");
    }
    else
    {
      printf ("\nNao esta ordernado em ordem descrecente");
    }

    IO_pause ("\nAperte ENTER para continuar");
}

int acharValor (int procurado, int i, int n, int *array)
{
    int x = 0;

    for (; i < n; i++)
    {
        if (procurado == array[i])
        {
            x = 1;
        }
    }

    return x;
}

void metodo8() {
    numExercicio(8);

    FILE *arquivo;

    arquivo = fopen ("DADOS.txt", "r");

    int n = 0;
    fscanf(arquivo,"%d", &n);
    int array[n];

    for (int i = 0; i < n; i++)
    {
        array[i] = LerArquivo(n , arquivo);
    }

    fclose (arquivo);

    int procurado = IO_readint ("Digite o valor que procura dentro do arquivo: ");

    int existe = acharValor (procurado, 0 , n , array);

    if (existe)
    {
        printf ("\nO numero que voce digitou existe dentro do arquivo!");
    }
    else
    {
        printf ("\nO numero que voce digitou NAO existe dentro do arquivo!");
    }

    IO_pause ("\nAperte ENTER para continuar");
}

int acharPosicao(int procurado, int i, int n, int *array)
{
    for (; i < n; i++)
    {
        if (procurado == array[i])
        {
            return i;
        }
    }
    return -1;
}

void metodo9() {
    numExercicio(9);

    FILE *arquivo;

    arquivo = fopen ("DADOS.txt", "r");

    int n = 0;
    fscanf(arquivo,"%d", &n);
    int array[n];

    for (int i = 0; i < n; i++)
    {
        array[i] = LerArquivo(n , arquivo);
    }

    fclose (arquivo);

    int procurado = IO_readint ("Digite o valor que procura dentro do arquivo: ");

    int onde = acharPosicao (procurado, 0 , n , array);

    if (onde == -1)
    {
        printf ("\nEste valor nao foi encontrado dentro do arquivo");
    }
    else
    {
        printf ("\nO valor procurado esta na posicao: [%d]", onde);
    }

    IO_pause ("\nAperte ENTER para continuar");
}

int acharQuantos(int procurado, int i, int n, int *array)
{
    int cont = 0;

    for (; i < n; i++)
    {
        if (procurado == array[i])
        {
            cont++;
        }
    }

    return cont;
}

void metodo10() {
    numExercicio(10);

    FILE *arquivo;

    arquivo = fopen ("DADOS.txt", "r");

    int n = 0;
    fscanf(arquivo,"%d", &n);
    int array[n];

    for (int i = 0; i < n; i++)
    {
        array[i] = LerArquivo(n , arquivo);
    }
    fclose (arquivo);

    int procurado = IO_readint ("Digite o valor que procura dentro do arquivo: ");

    int vezes = acharQuantos(procurado, 0 , n , array);

    printf ("\nO numero [%d] foi encontrado (%d) vezes", procurado, vezes);

    IO_pause ("\nAperte ENTER para continuar");
}

int main ( )
{
  // definir dado
  int x = 0;
  // repetir até desejar parar
  do
  {
    // identificar
    IO_id ( "ExerciciosE08 - Programa - v1.0" );
    // ler do teclado
    IO_println ( "Opcoes" );
    IO_println ( "0 - parar" );
    IO_println ( "1 - Metodo_1" );
    IO_println ( "2 - Metodo_2" );
    IO_println ( "3 - Metodo_3" );
    IO_println ( "4 - Metodo_4" );
    IO_println ( "5 - Metodo_5" );
    IO_println ( "6 - Metodo_6" );
    IO_println ( "7 - Metodo_7" );
    IO_println ( "8 - Metodo_8" );
    IO_println ( "9 - Metodo_9" );
    IO_println ( "10 - Metodo_10" );
    x = IO_readint ( "\nEntrar com uma opcao: " );
    // testar valor
    switch ( x )
    {
      case 0: metodo0 ( ); break;
      case 1: metodo1 ( ); break;
      case 2: metodo2 ( ); break;
      case 3: metodo3 ( ); break;
      case 4: metodo4 ( ); break;
      case 5: metodo5 ( ); break;
      case 6: metodo6 ( ); break;
      case 7: metodo7 ( ); break;
      case 8: metodo8 ( ); break;
      case 9: metodo9 ( ); break;
      case 10: metodo10 ( ); break;
      default:
        IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1,2,3,4,5,6,7,8,9,10] (",
          IO_concat ( IO_toString_d ( x ), ")" ) ) );
    } // end switch
  }
  while ( x != 0 );
  // encerrar
  IO_pause ( "Apertar ENTER para terminar" );
  return ( 0 );
} // end main


/* Resultados dos testes Realizados:

///////////////////////////////////////////

Exercicio 1
Insira a quantidade de valores: 5
2 4 6 8 10

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 2
Insira a quantidade de valores: 5
2 4 6 8 10

Aperte ENTER para continuar         //Resultado no arquivo Metodo2.txt

///////////////////////////////////////////

// A quantidade de valores dos proximos exercicios são definidos nesse arquivo.

Exercicio 3
Insira a quantidade de valores: 20
Insira o tamanho maximo do intervalo: 50
Insira o tamanho minimo do intervalo: 20
[21] [48] [20] [45] [30] [46] [39] [27] [42] [31] [47] [23] [47] [49] [33] [33] [50] [43] [22] [44]
Aperte ENTER para continuar

//Resultado no arquivo dados.txt

///////////////////////////////////////////

Exercicio 4
21 48 20 45 30 46 39 27 42 31 47 23 47 49 33 33 50 43 22 44

Menor par: [20]

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 5
21 48 20 45 30 46 39 27 42 31 47 23 47 49 33 33 50 43 22 44

Maior Impar: [49]

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 7
Insira a quantidade de valores: 6

Digite 6 valores: 10 8 5 3 2 1

Esta ordernado em ordem descrecente

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 8
Digite o valor que procura dentro do arquivo: 42

O numero que voce digitou existe dentro do arquivo!

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 9
Digite o valor que procura dentro do arquivo: 27

O valor procurado esta na posicao: [7]

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 10
Digite o valor que procura dentro do arquivo: 33

O numero [33] foi encontrado (2) vezes

Aperte ENTER para continuar

///////////////////////////////////////////

*/
