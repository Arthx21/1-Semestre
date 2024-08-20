#include "io.h"
#include "mymatrix.hpp"


#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause ( std::string text )
{
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
} // end pause ( )


void method_01 ( )
{
 // definir dados
    Matrix <int> int_matrix ( 2, 2, 0 );

    int_matrix.set ( 0, 0, 1 ); int_matrix.set ( 0, 1, 2 );
    int_matrix.set ( 1, 0, 3 ); int_matrix.set ( 1, 1, 4 );

 // identificar
    cout << "\nMethod_01 - v0.0\n" << endl;

 // mostrar dados
    int_matrix.print ( );

 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )


/**
   Method_02.
 */
void method_02 ( )
{
 // definir dados
    Matrix <int> matrix ( 2, 2, 0 );

 // identificar
    cout << endl << "Method_02 - v0.0" << endl;

 // ler dados
    matrix.read  ( );

 // mostrar dados
    matrix.print ( );

 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )


void method_03 ( )
{
 // definir dados
    Matrix <int> matrix ( 2, 2, 0 );

 // identificar
    cout << endl << "Method_03 - v0.0" << endl;

 // ler dados
    matrix.read  ( );

 // mostrar dados
    matrix.print ( );

 // gravar  dados
    matrix.fprint( "MATRIX1.TXT" );

 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

void method_04 ( )
{
 // definir dados
    Matrix <int> matrix ( 1, 1, 0 );

 // identificar
    cout <<  endl << "Method_04 - v0.0" << endl;

 // ler dados
    matrix.fread  ( "MATRIX1.TXT" );

 // mostrar dados
    matrix.print ( );

 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

void method_05 ( )
{
 // definir dados
    Matrix <int> int_matrix1 ( 1, 1, 0 );
    Matrix <int> int_matrix2 ( 1, 1, 0 );

 // identificar
    cout << endl << "Method_05 - v0.0" << endl;

 // ler dados
    int_matrix1.fread ( "MATRIX1.TXT" );

 // mostrar dados
    cout << "\nOriginal\n" << endl;
    int_matrix1.print ( );

 // copiar  dados
    int_matrix2 = int_matrix1;

 // mostrar dados
    cout << "\nCopia\n" << endl;
    int_matrix2.print ( );

 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )


void method_06 ( )
{
 // definir dados
    Matrix <int> int_matrix ( 2, 2, 0 );

    int_matrix.set ( 0, 0, 0 );    int_matrix.set ( 0, 1, 0 );
    int_matrix.set ( 1, 0, 0 );    int_matrix.set ( 1, 1, 0 );

 // identificar
    cout << endl << "Method_06 - v0.0" << endl;

 // mostrar dados
    int_matrix.print ( );

 // testar  condicao
    cout << "Zeros = " << int_matrix.isZeros ( ) << endl;

 // ler dados
    int_matrix.fread ( "MATRIX1.TXT" );

 // mostrar dados
    int_matrix.print ( );

 // testar  condicao
    cout << "Zeros = " << int_matrix.isZeros ( ) << endl;

 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

void method_07 ( )
{
 // definir dados
    Matrix <int> int_matrix1 ( 1, 1, 0 );
    Matrix <int> int_matrix2 ( 1, 1, 0 );

 // identificar
    cout << endl << "Method_07 - v0.0" << endl;

 // ler dados
    int_matrix1.fread ( "MATRIX1.TXT" );

 // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );

 // copiar  dados
    int_matrix2 = int_matrix1;

 // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );

 // testar  condicao
    cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;

 // alterar dados
    int_matrix2.set ( 0, 0, (-1) );

 // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );

 // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );

 // testar  condicao
    cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;

 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )


void method_08 ( )
{
 // definir dados
    Matrix <int> int_matrix1 ( 1, 1, 0 );
    Matrix <int> int_matrix2 ( 1, 1, 0 );
    Matrix <int> int_matrix3 ( 1, 1, 0 );

 // identificar
    cout << endl << "Method_08 - v0.0" << endl;

 // ler dados
    int_matrix1.fread ( "MATRIX1.TXT" );

 // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );

 // copiar  dados
    int_matrix2 = int_matrix1;

 // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );

 // operar  dados
    int_matrix3 = int_matrix1 - int_matrix2;

 // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print ( );

 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

void method_09 ( )
{
 // definir dados
    Matrix <int> int_matrix1 ( 2, 2, 0 );

    int_matrix1.set ( 0, 0, 1 );
    int_matrix1.set ( 0, 1, 0 );
    int_matrix1.set ( 1, 0, 0 );
    int_matrix1.set ( 1, 1, 1 );

    Matrix <int> int_matrix2 ( 1, 1, 0 );
    Matrix <int> int_matrix3 ( 1, 1, 0 );

 // identificar
    cout << endl << "Method_09 - v0.0" << endl;

 // ler dados
    int_matrix2.fread ( "MATRIX1.TXT" );

 // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print ( );

 // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print ( );

 // operar  dados
    int_matrix3 = int_matrix1 * int_matrix2;

 // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print ( );

 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

void method_10 ( )
{
 // definir dados
    Matrix <int> int_matrix ( 3, 3, 0 );
    int x = 0;
    int y = 0;

 // identificar
    cout <<  endl << "Method_10 - v0.0" << endl;

 // ler dados
    int_matrix.fread ( "MATRIX1.TXT" );

 // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print ( );

 // operar  dados
    for ( int x = 0; x < int_matrix.getRows ( ); x=x+1 )
    {
        for ( int y = 0; y < int_matrix.getColumns ( ); y=y+1 )
        {
            int_matrix.set ( x, y, int_matrix.get ( x, y ) * (-1) );
        } // end for
    } // end for

 // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print ( );

 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )





int main ( int argc, char** argv )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
 do
 {
 // identificar
 cout << "EXEMPLO1101 - Programa - v0.0\n " << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << " 0 - parar " << endl;
 cout << " 1 - Mostrar certa quantidade de valores " << endl;
 cout << " 2 - " << endl;
 cout << " 3 - " << endl;
 cout << " 4 - " << endl;
 cout << " 5 - " << endl;
 cout << " 6 - " << endl;
 cout << " 7 - " << endl;
 cout << " 8 - " << endl;
 cout << " 9 - " << endl;
 cout << "10 - " << endl;
 // ler do teclado
 cout << endl << "Entrar com uma opcao: ";
 cin >> x;
 // escolher acao
 switch ( x )
 {
// case 0: method_00 ( ); break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;
 case 3: method_03 ( ); break;
 case 4: method_04 ( ); break;
 case 5: method_05 ( ); break;
 case 6: method_06 ( ); break;
 case 7: method_07 ( ); break;
 case 8: method_08 ( ); break;
 case 9: method_09 ( ); break;
 case 10: method_10 ( ); break;
 default:
 cout << endl << "ERRO: Valor invalido." << endl;
 } // end switch
 }
 while ( x != 0 );
// encerrar
 pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // end main ( )

/*
Resultados dos testes:

////////////////////////////////////////

Method_01 - v0.0


1       2
3       4


Apertar ENTER para continuar

////////////////////////////////////////

Method_02 - v0.0

 0,  0 : 2
 0,  1 : 5
 1,  0 : 6
 1,  1 : 9


2       5
6       9


Apertar ENTER para continuar

////////////////////////////////////////

Method_03 - v0.0

 0,  0 : 1
 0,  1 : 4
 1,  0 : 8
 1,  1 : 2


1       4
8       2


Apertar ENTER para continuar

////////////////////////////////////////

Method_04 - v0.0

1       4
8       2


Apertar ENTER para continuar

////////////////////////////////////////

Method_05 - v0.0

Original


1       4
8       2


Copia


1       4
8       2


Apertar ENTER para continuar

////////////////////////////////////////

Method_06 - v0.0

0       0
0       0

Zeros = 1

1       4
8       2

Zeros = 0

Apertar ENTER para continuar

////////////////////////////////////////

Method_07 - v0.0

Matrix_1

1       4
8       2


Matrix_2

1       4
8       2

Diferentes = 0

Matrix_1

1       4
8       2


Matrix_2

-1      4
8       2

Diferentes = 1

Apertar ENTER para continuar

////////////////////////////////////////

Method_08 - v0.0

Matrix_1

1       4
8       2


Matrix_2

1       4
8       2


Matrix_3

0       0
0       0


Apertar ENTER para continuar

////////////////////////////////////////

Method_09 - v0.0

Matrix_1

1       0
0       1


Matrix_2

1       4
8       2


Matrix_3

1       4
8       2


Apertar ENTER para continuar

////////////////////////////////////////

Method_10 - v0.0

Matrix

1       4
8       2


Matrix

-1      -4
-8      -2


Apertar ENTER para continuar

////////////////////////////////////////

*/


