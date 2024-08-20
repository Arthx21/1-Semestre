/*
  EXERCICIO DO GUIA 09
  Data: 03/05/2024
  autor: Arthur Souza Carvalho

  Program v1.0

*/
#include "io.h"

void metodo0() {
  IO_println ("\n\n\tObrigado por utilizar o meu programa!!!\n");
}

void numExercicio(int x)   //funcao extra para identificar qual atividade esta sendo apresentada
{
  printf ("\nExercicio %d\n", x);
}

void readNegativeDoubleMatrix (int lin, int col, double matrix[lin][col])
{
    printf ("Digite %d valores para prencher a matrix de %d linhas e %d colunas: ", lin*col, lin, col);

    for ( int i = 0; i < lin; i++)
    {
        for ( int j = 0; j < col; j++)
        {
            do {
                scanf (" %lf", &matrix[i][j]);
                if (matrix [i][j] >= 0)
                {
                    printf ("Digite apenas valores negativos \n");
                }
            } while (matrix[i][j] >= 0);
        }
    }
}

void printDoubleMatrix (int lin, int col, double matrix[lin][col])
{
    printf ("\n");
    for ( int i = 0; i < lin; i++)
    {
        for ( int j = 0; j < col; j++)
        {
            printf (" %.2lf", matrix[i][j]);
        }
        printf ("\n");
    }
}

void metodo1()
{
    numExercicio(1);
    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin <= 0 || col <= 0);

    double NegativeMatrix[lin][col];

    readNegativeDoubleMatrix(lin, col, NegativeMatrix);
    printDoubleMatrix( lin, col, NegativeMatrix);

    IO_pause ("Aperte ENTER para continuar");
}

void fprintDoubleMatrix (char *nomearquivo, int lin, int col, double matrix[lin][col])
{
    FILE *arquivo;

    arquivo = fopen (nomearquivo, "w");

    for ( int i = 0; i < lin; i++)
    {
        for ( int j = 0; j < col; j++)
        {
            fprintf (arquivo,"%lf ", matrix[i][j]);
        }
    }
    fclose(arquivo);
}

void fscanDoubleMatrix (char *nomearquivo, int lin, int col, double matrix[lin][col])
{
    FILE *arquivo;

    arquivo = fopen (nomearquivo, "r");

    for ( int i = 0; i < lin; i++)
    {
        for ( int j = 0; j < col; j++)
        {
            fscanf (arquivo,"%lf", &matrix[i][j]);
        }
    }
    fclose(arquivo);
}

void metodo2()
{
    numExercicio(2);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin <= 0 || col <= 0);
    double NegativeMatrix[lin][col];
    double MatrixRecebeArquivo[lin][col];

    readNegativeDoubleMatrix(lin, col, NegativeMatrix);

    fprintDoubleMatrix("MATRIX_01.txt", lin , col , NegativeMatrix);

    fscanDoubleMatrix("MATRIX_01.txt", lin , col , MatrixRecebeArquivo);

    printDoubleMatrix(lin, col, MatrixRecebeArquivo);

    IO_pause ("Aperte ENTER para continuar");
}

void printDiagonalDoubleMatrix ( int lin, int col, double matrix[lin][col])
{
    printf ("\nDiagonal Principal: \n");
    for (int i = 0; i < lin; i++) {
        printf("%lf ", matrix[i][i]);
    }
    printf("\n");
}

void metodo3()
{
    numExercicio(3);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin <= 0 || col <= 0);
    double NegativeMatrix[lin][col];

    readNegativeDoubleMatrix( lin , col , NegativeMatrix);

    if ( lin == col )
    {
        printDiagonalDoubleMatrix ( lin , col , NegativeMatrix);
    }
    else
    {
        printf ("\nA matriz real NAO e quadrada\n");
    }

    IO_pause ("Aperte ENTER para continuar");
}

void printSDiagonalDoubleMatrix ( int lin , int col , double matrix[lin][col])
{
    printf ("\nDiagonal Secundaria:\n");
    int j = col-1;
    for (int i = 0; i < lin; i++) {
        printf("%lf ", matrix[i][j]);
        j--;
    }
    printf("\n");
}

void metodo4()
{
    numExercicio(4);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin <= 0 || col <= 0);
    double NegativeMatrix[lin][col];

    readNegativeDoubleMatrix( lin , col , NegativeMatrix);

    if ( lin == col )
    {
        printSDiagonalDoubleMatrix ( lin , col , NegativeMatrix); //Diagonal secundaria
    }
    else
    {
        printf ("\nA matriz real NAO e quadrada\n");
    }

    IO_pause ("Aperte ENTER para continuar");
}

void printLDTriangleDoubleMatrix( int lin, int col, double matrix[lin][col])
{
    printf ("\nUltima linha da matriz:\n");
    int linha = lin - 1;
    for (int i = 0; i < col; i++)
    {
        printf ("%lf ", matrix[linha][i]);
    }
}

void metodo5()
{
    numExercicio(5);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin <= 0 || col <= 0);
    double NegativeMatrix[lin][col];

    readNegativeDoubleMatrix( lin , col , NegativeMatrix);

    printDiagonalDoubleMatrix(lin, col , NegativeMatrix);

    printLDTriangleDoubleMatrix( lin, col, NegativeMatrix);

    IO_pause ("\nAperte ENTER para continuar");
}

void printLUTriangleDoubleMatrix( int lin , int col , double matrix[lin][col])
{
    printf ("\nPrimeira linha da matriz:\n");
    for (int i = 0; i < col; i++)
    {
        printf ("%lf ", matrix[0][i]);
    }
}

void metodo6()
{
    numExercicio(6);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin <= 0 || col <= 0);
    double NegativeMatrix[lin][col];

    readNegativeDoubleMatrix( lin , col , NegativeMatrix);

    printDiagonalDoubleMatrix(lin, col , NegativeMatrix);

    printLUTriangleDoubleMatrix( lin, col , NegativeMatrix);

    IO_pause ("\nAperte ENTER para continuar");
}

void metodo7()
{
    numExercicio(7);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin <= 0 || col <= 0);
    double NegativeMatrix[lin][col];

    readNegativeDoubleMatrix( lin , col , NegativeMatrix);

    printSDiagonalDoubleMatrix(lin, col , NegativeMatrix);

    printLDTriangleDoubleMatrix(lin , col , NegativeMatrix);

    IO_pause ("\nAperte ENTER para continuar");
}

void metodo8()
{
    numExercicio(8);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin <= 0 || col <= 0);
    double NegativeMatrix[lin][col];

    readNegativeDoubleMatrix( lin , col , NegativeMatrix);

    printSDiagonalDoubleMatrix(lin, col , NegativeMatrix);

    printLUTriangleDoubleMatrix(lin , col , NegativeMatrix);

    IO_pause ("\nAperte ENTER para continuar");
}

bool  allZerosLTriangleDoubleMatrix (int lin, int col, double matrix[lin][col])
{
    int linha = lin - 1; int cont = 0;
    for (int i = 0; i < col; i++)
    {
        if ( matrix[linha][i] == 0 )
        {
            cont++;
        }
        if ( cont == col )
        {
            return true;
        }
    }
    return false;
}

void metodo9()
{
    numExercicio(9);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin <= 0 || col <= 0);
    double NegativeMatrix[lin][col];

    readNegativeDoubleMatrix( lin , col , NegativeMatrix);

    if (allZerosLTriangleDoubleMatrix( lin , col , NegativeMatrix))
    {
        printf ("TODOS os valores abaixo da diagonal principal sao 0");
    }
    else
    {
        printf ("NEM todos os valores abaixo da diagonal principal sao 0");
    }

    IO_pause ("\nAperte ENTER para continuar");
}

 bool allZerosUTriangleDoubleMatrix(int lin, int col, double matrix[lin][col])
 {
     int cont = 0;
     for (int i = 0; i < col; i++)
    {
        if ( matrix[0][i] == 0)
        {
            cont++;
        }
        if (cont == col)
        {
            return true;
        }
    }
     return false;
 }

void metodo10()
{
    numExercicio(10);

    int lin = 0, col = 0;

    do {
    lin = IO_readint ("Digite a quantidade de linhas: ");
    col = IO_readint ("Digite a quantidade de colunas: ");
    } while (lin <= 0 || col <= 0);
    double NegativeMatrix[lin][col];

    readNegativeDoubleMatrix( lin , col , NegativeMatrix);

    if (allZerosUTriangleDoubleMatrix(lin, col, NegativeMatrix))
    {
        printf ("TODOS os valores acima da diagonal principal sao 0");
    }
    else
    {
        printf ("NEM os valores acima da diagonal principal sao 0");
    }

    IO_pause ("\nAperte ENTER para continuar");
}


int main ( )
{

  int x = 0;

  do
  {

    IO_id ( "ExerciciosE09 - Programa - v1.0" );

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
    }
  }
  while ( x != 0 );

  IO_pause ( "Apertar ENTER para terminar" );
  return ( 0 );
}


/*

Resultados dos testes:

//////////////////////////////////////////////////////

Exercicio 1
Digite a quantidade de linhas: 0
Digite a quantidade de colunas: 0
Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
Digite 9 valores para prencher a matrix de 3 linhas e 3 colunas: 1
Digite apenas valores negativos
-1 -2 -3 -4 -5 -6 -7 -8 -9

 -1.00 -2.00 -3.00
 -4.00 -5.00 -6.00
 -7.00 -8.00 -9.00

Aperte ENTER para continuar

//////////////////////////////////////////////////////

Exercicio 2
Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
Digite 9 valores para prencher a matrix de 3 linhas e 3 colunas: -1 -2 -3 -4 -5 -6 -7 -8 -9

 -1.00 -2.00 -3.00
 -4.00 -5.00 -6.00
 -7.00 -8.00 -9.00

Aperte ENTER para continuar

//////////////////////////////////////////////////////

Exercicio 3
Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
Digite 9 valores para prencher a matrix de 3 linhas e 3 colunas: -1 -2 -3 -4 -5 -6 -7 -8 -9

Diagonal Principal:
-1.000000 -5.000000 -9.000000

Aperte ENTER para continuar

//////////////////////////////////////////////////////

Exercicio 4
Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
Digite 9 valores para prencher a matrix de 3 linhas e 3 colunas: -1 -2 -3 -4 -5 -6 -7 -8 -9

Diagonal Secundaria:
-3.000000 -5.000000 -7.000000

Aperte ENTER para continuar

//////////////////////////////////////////////////////

Exercicio 5
Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
Digite 9 valores para prencher a matrix de 3 linhas e 3 colunas: -1 -2 -3 -4 -5 -6 -7 -8 -9

Diagonal Principal:
-1.000000 -5.000000 -9.000000

Ultima linha da matriz:
-7.000000 -8.000000 -9.000000

Aperte ENTER para continuar

//////////////////////////////////////////////////////

Exercicio 6
Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
Digite 9 valores para prencher a matrix de 3 linhas e 3 colunas: -1 -2 -3 -4 -5 -6 -7 -8 -9

Diagonal Principal:
-1.000000 -5.000000 -9.000000

Primeira linha da matriz:
-1.000000 -2.000000 -3.000000

Aperte ENTER para continuar

//////////////////////////////////////////////////////

Exercicio 7
Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
Digite 9 valores para prencher a matrix de 3 linhas e 3 colunas: -1 -2 -3 -4 -5 -6 -7 -8 -9

Diagonal Secundaria:
-3.000000 -5.000000 -7.000000

Ultima linha da matriz:
-7.000000 -8.000000 -9.000000

Aperte ENTER para continuar

//////////////////////////////////////////////////////

Exercicio 8
Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
Digite 9 valores para prencher a matrix de 3 linhas e 3 colunas: -1 -2 -3 -4 -5 -6 -7 -8 -9

Diagonal Secundaria:
-3.000000 -5.000000 -7.000000

Primeira linha da matriz:
-1.000000 -2.000000 -3.000000

Aperte ENTER para continuar

//////////////////////////////////////////////////////

Exercicio 9
Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
Digite 9 valores para prencher a matrix de 3 linhas e 3 colunas: -1 -2 -3 -4 -5 -6 -7 -8 -9
NEM todos os valores abaixo da diagonal principal sao 0

Aperte ENTER para continuar

//////////////////////////////////////////////////////

Exercicio 10
Digite a quantidade de linhas: 3
Digite a quantidade de colunas: 3
Digite 9 valores para prencher a matrix de 3 linhas e 3 colunas: 0
Digite apenas valores negativos
-1 -2 -3 -4 -5 -6 -7 -8 -9
NEM os valores acima da diagonal principal sao 0

Aperte ENTER para continuar

//////////////////////////////////////////////////////

*/
