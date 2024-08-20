#include "My_library.h"



void metodo0() {
  println ("\n\n\tObrigado por utilizar o meu programa!!!\n");
}

void metodo1()
{
    numExercicio(1);



}

void metodo2()
{
    numExercicio(2);



}

void metodo3()
{
    numExercicio(3);



}

void metodo4()
{
    numExercicio(4);



}

void metodo5()
{
    numExercicio(5);



}

void metodo6()
{
    numExercicio(6);



}

void metodo7()
{
    numExercicio(7);



}

void metodo8()
{
    numExercicio(8);



}

int main ()
{
    int x = 0;

  do
  {

    println ( "\nExercicios da Prova 01\n" );

    printf ( "Opcoes\n" );
    printf ( "0 - parar\n" );
    printf ( "1 - Metodo_1\n" );
    printf ( "2 - Metodo_2\n" );
    printf ( "3 - Metodo_3\n" );
    printf ( "4 - Metodo_4\n" );
    printf ( "5 - Metodo_5\n" );
    printf ( "6 - Metodo_6\n" );
    printf ( "7 - Metodo_7\n" );
    printf ( "8 - Metodo_8\n" );

    x = readInt ( "\nEntrar com uma opcao: " );

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
      default:
        printf ("Valor diferente das opcoes [0,1,2,3,4,5,6,7,8]");
    }
  }
  while ( x != 0 );
}
