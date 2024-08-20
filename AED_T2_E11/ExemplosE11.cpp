#include "io.h"

/*
 Exemplo1100 - v0.0. - __ / __ / _____
 Author: ________________________
*/
// dependencias
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
// ----------------------------------------------- classes / pacotes
#include "myarray.hpp"
using namespace std;
// ----------------------------------------------- metodos
/**
 Method_00 - nao faz nada.
*/
void method_00 ( )
{
// nao faz nada
} // end method_00 ( )

/**
 Method_01 - Mostrar certa quantidade de valores.
*/
void method_01 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
 int_array.set ( 0, 1 );
 int_array.set ( 1, 2 );
 int_array.set ( 2, 3 );
 int_array.set ( 3, 4 );
 int_array.set ( 4, 5 );
// identificar
 cout << "\nMethod_01 - v0.0\n" << endl;
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
 Method_02.
*/
void method_02 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
// identificar
 cout << endl << "Method_02 - v0.0" << endl;
// ler dados
 int_array.read ( );
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
 Method_03.
*/
void method_03 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
// identificar
 cout << endl << "Method_03 - v0.0" << endl;
// ler dados
 int_array.read ( );
// mostrar dados
 int_array.fprint ( "INT_ARRAY1.TXT" );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
 Method_04.
*/
void method_04 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
// identificar
 cout << endl << "Method_04 - v0.0" << endl;
// ler dados
 int_array.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
 Method_05.
*/
void method_05 ( )
{
// definir dados
 int other [ ] = { 1, 2, 3, 4, 5 };
 Array <int> int_array ( 5, other );
// identificar
 cout << endl << "Method_05 - v0.0" << endl;
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array.print ( );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
 Method_06.
*/
void method_06 ( )
{
// definir dados
 Array <int> int_array1 ( 1, 0 );
// identificar
 cout << endl << "Method_06 - v0.0" << endl;
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 cout << "\nOriginal\n" << endl;
 int_array1.print ( );
// criar copia
 Array <int> int_array2 ( int_array1 );
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array2.print ( );
// reciclar espaco
 int_array1.free ( );
 int_array2.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )


/**
 Method_07.
*/
void method_07 ( )
{
// definir dados
 Array <int> int_array1 ( 1, 0 );
 Array <int> int_array2 ( 1, 0 );
// identificar
 cout << endl << "Method_07 - v0.0" << endl;
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 cout << "\nOriginal\n" << endl;
 int_array1.print ( );
// copiar dados
 int_array2 = int_array1;
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array2.print ( );
// reciclar espaco
 int_array1.free ( );
 int_array2.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )


/**
 Method_08.
*/
void method_08 ( )
{
// definir dados
 int other [ ] = { 1, 2, 3 };
 Array <int> int_array1 ( 3, other );
 Array <int> int_array2 ( 3, other );
 int x;
// identificar
 cout << endl << "Method_08 - v0.0" << endl;
// mostrar dados
 cout << endl;
 cout << "Array_1";
 int_array1.print ( );
// mostrar dados
 cout << "Array_2";
 int_array2.print ( );
// mostrar comparacao
 cout << "Igualdade = " << (int_array1==int_array2) << endl;
// alterar dado
 int_array2.set ( 0, (-1) );
// mostrar dados
 cout << endl;
 cout << "Array_1" << endl;
 int_array1.print ( );

 cout << "Array_2" << endl;
 int_array2.print ( );
// mostrar comparacao
 cout << "Igualdade = " << (int_array1==int_array2) << endl;
// reciclar espaco
 int_array1.free ( );
 int_array2.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
 Method_09.
*/
void method_09 ( )
{
// definir dados
 Array <int> int_array1 ( 1, 0 );
 Array <int> int_array2 ( 1, 0 );
 Array <int> int_array3 ( 1, 0 );
// identificar
 cout << endl << "EXEMPLO1110 - Method_09 - v0.0" << endl;
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// copiar dados
 int_array2 = int_array1;
// somar dados
 int_array3 = int_array2 + int_array1;
// mostrar dados
 cout << endl;
 cout << "Original" << endl;
 int_array1.print ( );
// mostrar dados
 cout << "Copia" << endl;
 int_array2.print ( );
// mostrar dados
 cout << "Soma" << endl;
 int_array3.print ( );
// reciclar espaco
 int_array1.free ( );
 int_array2.free ( );
 int_array3.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
 Method_10.
*/
void method_10 ( )
{
// definir dados
 int other [ ] = { 1, 2, 3, 4, 5 };
 Array <int> int_array ( 5, other );
 int x;
// identificar
 cout << endl << "Method_10 - v0.0" << endl;
// mostrar dados
 cout << "\nAcesso externo" << endl;
 for ( x=0; x<int_array.getLength( ); x=x+1 )
 {
 cout << endl << setw( 3 ) << x << " : " << int_array [ x ];
 } // fim repetir
 cout << endl << "\nFora dos limites:";
 cout << endl << "[-1]: " << int_array.get(-1) << endl;
 cout << endl << "[" << int_array.getLength( ) << "]: "
 << int_array [ int_array.getLength( ) ] << endl;
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )


// ----------------------------------------------- acao principal
/*
 Funcao principal.
 @return codigo de encerramento
*/
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
 cout << " 1 - mostrar dados inteiros em arranjo " << endl;
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
 case 0: method_00 ( ); break;
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


  0 :         1
  1 :         2
  2 :         3
  3 :         4
  4 :         5


Apertar ENTER para continuar

////////////////////////////////////////

Method_02 - v0.0

  0 : 2
  1 : 23
  2 : 45
  3 : 65
  4 : 32


  0 :         2
  1 :        23
  2 :        45
  3 :        65
  4 :        32


Apertar ENTER para continuar

////////////////////////////////////////

Method_03 - v0.0

  0 : 2
  1 : 3
  2 : 65
  3 : 95
  4 : 6


Apertar ENTER para continuar

////////////////////////////////////////

Method_04 - v0.0

  0 :         2
  1 :         3
  2 :        65
  3 :        95
  4 :         6


Apertar ENTER para continuar

////////////////////////////////////////

Method_05 - v0.0

Copia


  0 :         1
  1 :         2
  2 :         3
  3 :         4
  4 :         5


Apertar ENTER para continuar

////////////////////////////////////////

Method_06 - v0.0

Original


  0 :         2
  1 :         3
  2 :        65
  3 :        95
  4 :         6


Copia


  0 :         2
  1 :         3
  2 :        65
  3 :        95
  4 :         6


Apertar ENTER para continuar

////////////////////////////////////////

Method_07 - v0.0

Original


  0 :         2
  1 :         3
  2 :        65
  3 :        95
  4 :         6


Copia


  0 :         2
  1 :         3
  2 :        65
  3 :        95
  4 :         6


Apertar ENTER para continuar

////////////////////////////////////////

Method_08 - v0.0

Array_1
  0 :         1
  1 :         2
  2 :         3

Array_2
  0 :         1
  1 :         2
  2 :         3

Igualdade = 1

Array_1

  0 :         1
  1 :         2
  2 :         3

Array_2

  0 :        -1
  1 :         2
  2 :         3

Igualdade = 0

Apertar ENTER para continuar

////////////////////////////////////////

EXEMPLO1110 - Method_09 - v0.0

Original

  0 :         2
  1 :         3
  2 :        65
  3 :        95
  4 :         6

Copia

  0 :         2
  1 :         3
  2 :        65
  3 :        95
  4 :         6

Soma

  0 :         4
  1 :         6
  2 :       130
  3 :       190
  4 :        12


Apertar ENTER para continuar

////////////////////////////////////////

Method_10 - v0.0

Acesso externo

  0 : 1
  1 : 2
  2 : 3
  3 : 4
  4 : 5

Fora dos limites:
[-1]: 1875945840

[5]:

ERROR: Invalid position.

5

Apertar ENTER para continuar

////////////////////////////////////////

*/

