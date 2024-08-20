#include "io.h"

void metodo0() {
	IO_println ("\n\n\tObrigado por utilizar o meu programa!!!\n");
}

void writeInts ( chars fileName, int x )
{
	// definir dados
	FILE* arquivo = fopen ( fileName, "wt" );
	int y = 0;
	// repetir para a quantidade de dados
	for ( y = 1; y <= x; y = y + 1 )
	{
		// gravar valor
		fprintf ( arquivo, "%d\n", y );
	} // end for
	// fechar arquivo (INDISPENSAVEL para gravacao)
	fclose ( arquivo );
} // end writeInts ( )
/**
  Method_01 - Mostrar certa quantidade de valores.
 */
void metodo1 ( )
{
	// identificar
	IO_id ( "Method_01 - v0.0" );
	// executar o metodo auxiliar
	writeInts ( "DADOS1.TXT", 10 );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

void readInts ( chars fileName )
{
	// definir dados
	FILE* arquivo = fopen ( fileName, "rt" );
	int x = 0;
	// tentar ler o primeiro
	fscanf ( arquivo, "%d", &x );
	// repetir enquanto houver dados
	while ( ! feof ( arquivo ) )
	{
		// mostrar valor
		printf ( "%d\n", x );
		// tentar ler o proximo
		fscanf ( arquivo, "%d", &x );
	} // end while
	// fechar arquivo (RECOMENDAVEL para leitura)
	fclose ( arquivo );
} // end readInts ( )
/**
  Method_02.
 */
void metodo2 ( )
{
	// identificar
	IO_id ( "Method_02 - v0.0" );
	// executar o metodo auxiliar
	readInts ( "DADOS1.TXT" );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( 

void writeDoubles ( chars fileName, int x )
{
	// definir dados
	FILE* arquivo = fopen ( fileName, "wt" );
	int y = 0;
	// gravar quantidade de valores
	IO_fprintf ( arquivo, "%d\n", x );
	// repetir para a quantidade de dados
	for ( y = 1; y <= x; y = y + 1 )
	{
		// gravar valor
		IO_fprintf ( arquivo, "%lf\n", (0.1*y) );
	} // end for
	// fechar arquivo (INDISPENSAVEL para gravacao)
	fclose ( arquivo );
} // end writeDoubles ( )
/**
  Method_03.
 */
void metodo3 ( )
{
	// identificar
	IO_id ( "Method_03 - v0.0" );
	// executar o metodo auxiliar
	writeDoubles ( "DADOS2.TXT", 10 );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

void readDoubles ( chars fileName )
{
	// definir dados
	FILE* arquivo = fopen ( fileName, "rt" );
	int x = 0 ;
	int y = 1 ;
	double z = 0.0;
	// tentar ler a quantidade de dados
	fscanf ( arquivo, "%d", &x );
	// repetir enquanto houver dados e
	// quantidade nao tiver sido alcancada
	while ( ! feof ( arquivo ) && y <= x )
	{
		// tentar ler
		fscanf ( arquivo, "%lf", &z );
		// mostrar valor
		printf ( "%2d: %lf\n", y, z );
		// passar ao proximo
		y = y + 1;
	} // end while
	// fechar arquivo (RECOMENDAVEL para leitura)
	fclose ( arquivo );
} // end readDoubles ( )
/**
  Method_04.
 */
void metodo4 ( )
{
	// identificar
	IO_id ( "Method_04 - v0.0" );
	// executar o metodo auxiliar
	readDoubles ( "DADOS2.TXT" );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )


void writeText ( chars fileName )
{
	// definir dados
	FILE* arquivo = fopen ( fileName, "wt" );
	chars linha = IO_new_chars ( STR_SIZE );
	// repetir ate' desejar parar
	IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
	do
	{
		// ler do teclado
		strcpy ( linha, IO_readln ( "" ) );
		// gravar valor
		IO_fprintf ( arquivo, "%s\n", linha );
	}
	while ( strcmp ( "PARAR", linha ) != 0 );
	// fechar arquivo (INDISPENSAVEL para gravacao)
	fclose ( arquivo );
} // end writeText ( )
/**
  Method_05.
 */
void metodo5 ( )
{
	// identificar
	IO_id ( "Method_05 - v0.0" );
	// executar o metodo auxiliar
	writeText ( "DADOS3.TXT" );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

void readText ( chars fileName )
{
	// definir dados
	FILE* arquivo = fopen ( fileName, "rt" );
	chars linha = IO_new_chars ( STR_SIZE );
	// tentar ler o primeiro
	strcpy ( linha, IO_freadln ( arquivo ) );
	// repetir enquanto houver dados
	while ( ! feof (arquivo) &&
		strcmp ( "PARAR", linha ) != 0 )
	{
		// mostrar valor
		printf ( "%s\n", linha );
		// tentar ler o proximo
		strcpy ( linha, IO_freadln ( arquivo ) );
	} // end while
	// fechar arquivo (RECOMENDAVEL para leitura)
	fclose ( arquivo );
} // end readText ( )
/**
  Method_06.
 */
void metodo6 ( )
{
	// identificar
	IO_id ( "Method_06 - v0.0" );
	// executar o metodo auxiliar
	readText ( "DADOS3.TXT" );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

void copyText ( chars fileOut, chars fileIn )
{
	// definir dados
	FILE* saida = fopen ( fileOut, "wt" );
	FILE* entrada = fopen ( fileIn , "rt" );
	chars linha = IO_new_chars ( STR_SIZE );
	int contador = 0;
	// ler da origem
	strcpy ( linha, IO_freadln ( entrada ) );
	// repetir enquanto houver dados
	while ( ! feof ( entrada ) )
	{
		// contar linha lida
		contador = contador + 1;
		// gravar no destino,
		// EXCEPCIONALMENTE sem a ultima linha, nesse caso
		if ( strcmp ( "PARAR", linha ) != 0 )
		{
			IO_fprintln ( saida, linha );
		} // end if
		// ler da origem
		strcpy ( linha, IO_freadln ( entrada ) );
	} // end while
	// informar total de linhas copiadas
	IO_printf ( "Lines read = %d\n", contador );
	// fechar arquivos
	fclose ( saida );
	fclose ( entrada );
} // end copyText ( )
/**
  Method_07.
 */
void metodo7 ( )
{
	// identificar
	IO_id ( "Method_07 - v0.0" );
	// executar o metodo auxiliar
	copyText ( "DADOS4.TXT", "DADOS3.TXT" );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

void appendText ( chars fileName )
{
	// definir dados
	FILE* arquivo = fopen ( fileName, "at" );
	chars linha = IO_new_chars ( STR_SIZE );
	// repetir ate' desejar parar
	IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
	do
	{
		// ler do teclado
		strcpy ( linha, IO_readln ( "" ) );
		// gravar valor
		IO_fprintln ( arquivo, linha );
	}
	while ( strcmp ( "PARAR", linha ) != 0 );
	// fechar arquivo (INDISPENSAVEL para gravacao)
	fclose ( arquivo );
} // end appendText ( )
/**
  Method_08.
 */
void metodo8 ( )
{
	// identificar
	IO_id ( "EXEMPLO0710 - Method_08 - v0.0" );
	// executar o metodo auxiliar
	appendText ( "DADOS4.TXT" );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

void readWords ( chars fileName )
{
	// definir dados
	FILE* arquivo = fopen ( fileName, "rt" );
	chars linha = IO_new_chars ( STR_SIZE );
	// tentar ler a primeira
	strcpy ( linha, IO_fread ( arquivo ) );
	// repetir enquanto houver dados
	while ( ! feof (arquivo) &&
		strcmp ( "PARAR", linha ) != 0 )
	{
		// mostrar valor
		printf ( "%s\n", linha );
		// tentar ler o proximo
		strcpy ( linha, IO_fread ( arquivo ) );
	} // end while
	// fechar arquivo (RECOMENDAVEL para leitura)
	fclose ( arquivo );
} // end readWords ( )
/**
  Method_09.
 */
void metodo9 ( )
{
	// identificar
	IO_id ( "Method_09 - v0.0" );
	// executar o metodo auxiliar
	readWords ( "DADOS4.TXT" );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

bool searchWord ( chars fileName, chars word )
{
	// definir dados
	FILE* arquivo = fopen ( fileName, "rt" );
	chars linha = IO_new_chars ( STR_SIZE );
	// tentar ler a primeira
	strcpy ( linha, IO_fread ( arquivo ) );
	// repetir enquanto houver dados
	while ( ! feof (arquivo) &&
		strcmp ( word, linha ) != 0 )
	{
		// tentar ler o proximo
		strcpy ( linha, IO_fread ( arquivo ) );
	} // end while
	// fechar arquivo (RECOMENDAVEL para leitura)
	fclose ( arquivo );
	
	// retornar resultado
	return ( strcmp ( word, linha ) == 0 );
} // end ifarchdWord ( )
/**
  Method_10.
 */
void metodo10 ( )
{
	// identificar
	IO_id ( "Method_10 - v0.0" );
	// procurar palavra
	IO_printf ( "Procurar (\"%s\") = %d\n", "pqr", searchWord ( "DADOS4.TXT", "pqr" ) );
	IO_printf ( "Procurar (\"%s\") = %d\n", "pqs", searchWord ( "DADOS4.TXT", "pqs" ) );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )


int main ( )
{
	// definir dado
	int x = 0;
	// repetir até desejar parar
	do
	{
		// identificar
		IO_id ( "ExerciciosE04 - Programa - v1.0" );
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
  
  Method_02 - v0.0
  Autor: Arthur Souza Carvalho
  
  // Arquivo Criado "DADOS1"
  
  Apertar ENTER para continuar
  
  ///////////////////////////////////////////
  
  Method_02 - v0.0
  Autor: Arthur Souza Carvalho
  
  1
  2
  3
  4
  5
  6
  7
  8
  9
  10
  
  Apertar ENTER para continuar
  
  ///////////////////////////////////////////
  
  Method_03 - v0.0
  Autor: Arthur Souza Carvalho
  
  // Arquivo Criado "DADOS2"
  
  Apertar ENTER para continuar
  
  ///////////////////////////////////////////
  
  Method_04 - v0.0
  Autor: Arthur Souza Carvalho
  
  1: 0.100000
  2: 0.200000
  3: 0.300000
  4: 0.400000
  5: 0.500000
  6: 0.600000
  7: 0.700000
  8: 0.800000
  9: 0.900000
  10: 1.000000
  
  Apertar ENTER para continuar
  
  ///////////////////////////////////////////
  
  Method_05 - v0.0
  Autor: Arthur Souza Carvalho
  
  Gravar linhas (para terminar, entrar com "PARAR"):
  
  2
  PARAR
  
  Apertar ENTER para continuar
  
  ///////////////////////////////////////////
  
  Method_06 - v0.0
  Autor: Arthur Souza Carvalho
  
  2
  
  Apertar ENTER para continuar
  
  ///////////////////////////////////////////
  
  Method_07 - v0.0
  Autor: Arthur Souza Carvalho
  
  Lines read = 2
  
  Apertar ENTER para continuar
  
  ///////////////////////////////////////////
  
  EXEMPLO0710 - Method_08 - v0.0
  Autor: Arthur Souza Carvalho
  
  Gravar linhas (para terminar, entrar com "PARAR"):
  
  ola tudo bem?
  eu estou bem, obrigado!
  PARAR
  
  Apertar ENTER para continuar
  
  ///////////////////////////////////////////
  
  Method_09 - v0.0
  Autor: Arthur Souza Carvalho
  
  2
  ola
  tudo
  bem?
  eu
  estou
  bem,
  obrigado!
  
  Apertar ENTER para continuar
  
  ///////////////////////////////////////////
  
  Method_10 - v0.0
  Autor: Arthur Souza Carvalho
  
  Procurar ("pqr") = 0
  Procurar ("pqs") = 0
  
  Apertar ENTER para continuar
  
  ///////////////////////////////////////////
  
 */

