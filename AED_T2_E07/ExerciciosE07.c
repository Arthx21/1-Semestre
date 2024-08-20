/*
  EXERCICIO DO GUIA 07
  Data: 19/04/2024
  autor: Arthur Souza Carvalho

  Program v1.0

 */


#include "io.h"

void testarquivo(FILE* arquivo)   // funcao utilizada apenas pra teste
{
    if (arquivo == NULL)
{
    printf("\nERRO! O arquivo não foi aberto!\n");
}
else
   {
     printf("O arquivo foi aberto com sucesso!\n");
   }
}

void numExercicio(int x)   //funcao extra para identificar qual atividade esta sendo apresentada
{
	printf ("\nExercicio %d\n", x);
}

void metodo0() {
	IO_println ("\n\n\tObrigado por utilizar o meu programa!!!\n");
}

void metodo1()
{
	numExercicio(1);

	int x = 4;
	int n = IO_readint("Digite um valor inteiro: ");
	printf ("\n");

	FILE *arquivo;
	arquivo = fopen("Ex1.txt", "w");

	printf (" N = %d => ", n);

	for (int i = 0; i < 5; i++)
	{
		printf ("%d ", x);
		fprintf (arquivo ,"%d;", x);
		x = x + 4;
	}


	fclose(arquivo);

	IO_pause("\nAperte ENTER para continuar");
}

void metodo2()
{
	numExercicio(2);

    int x = 5;
    int cont = 0;
	int n = IO_readint("Digite um valor inteiro: ");
	int vetor[n];
	printf ("\n");

    FILE *arquivo;
	arquivo = fopen("Ex2.txt", "w");

	printf (" N = %d => ", n);

	for (int i = 0; cont < n; i++)
	{
	    x = i * 5;
	    if (x % 5 == 0 && x % 2 != 0 && x >= 25) {
            vetor[cont] = x;
            cont++;
		}
	}

	for (int i = n-1; i != -1; i--)
    {
        printf ("%d ", vetor[i]);
        fprintf (arquivo, "%d;", vetor[i]);
    }

	fclose(arquivo);


	IO_pause("\nAperte ENTER para continuar");
}

void metodo3()
{
	numExercicio(3);

	int x = 5;
	int n = IO_readint("Digite um valor inteiro: ");
	printf ("\n");

	FILE *arquivo;
	arquivo = fopen("Ex3.txt", "w");

	printf (" N = %d => ", n);

    printf ("1 ");
    fprintf (arquivo, "1;");
	for (int i = 1; i < n; i++)
    {
        x = pow (5 , i);
        printf ("%d ", x);
        fprintf (arquivo, "%d;", x);
    }

	fclose(arquivo);


	IO_pause("\nAperte ENTER para continuar");
}

void metodo4()
{
	numExercicio(4);

	int x = 5;
	double resultado = 0;
	int cont = 0;
	int n = IO_readint("Digite um valor inteiro: ");
	double vetor[n];
	printf ("\n");

    FILE *arquivo;
	arquivo = fopen("Ex4.txt", "w");

	printf (" N = %d => ", n);

	for (int i = 0; i < n; i++)
	{
	    x = pow (5 , i);
        vetor[cont] = x;
        resultado = 1 / vetor[i];
        cont++;
	}

	for (int i = n-1; i != 0; i--)
    {
        printf ("1/%0.lf ", vetor[i]);
        resultado = 1 / vetor[i];
        fprintf (arquivo, "%lf;", resultado);
    }
    printf ("1 ");
    fprintf (arquivo, "1;");

	fclose(arquivo);

	IO_pause("\nAperte ENTER para continuar");
}

void metodo5()
{
	numExercicio(5);

    float result = 0;
    int y = 0, cont = 0;
    int n = IO_readint("Digite um valor inteiro: ");
    float x = IO_readfloat("Digite um valor real: ");

    printf ("\n");

    FILE *arquivo;
	arquivo = fopen("Ex5.txt", "w");

	printf (" N = %d => ", n);

	printf ("1 ");
	fprintf (arquivo ,"1;");

    do
    {
        y++;
        if (y % 2 != 0)
        {
            result = pow (x , y);
            printf ("1/%f ", result);
            result = 1 / result;    //nos arquivos foram registrados os resultados para facilitar a leitura
            fprintf (arquivo, "%0.f;", result);
            cont++;
        }
    } while (cont != n-1);

	fclose(arquivo);

	IO_pause("\nAperte ENTER para continuar");
}

int lerArquivoint(FILE* arquivo)
{
    int x = 0;
    fscanf (arquivo, "%d;", &x);
    return (x);
}

double lerArquivodouble(FILE* arquivo)
{
    double x = 0;
    fscanf (arquivo, "%lf;", &x);
    return (x);
}

void metodo6()
{
	numExercicio(6);

	int n = IO_readint ("Digite um valor inteiro: ");
	printf ("\n");
    float vetor [n], resultado = 0;
    FILE *arquivo;

    arquivo = fopen ("Ex5.txt", "r");
    for (int i = 0; i < n; i++)
    {
        vetor[i] = lerArquivoint(arquivo);
    }
    fclose(arquivo);

    for (int i = 0; i < n; i++)
    {
        printf ("%f ", vetor[i]);
        resultado = resultado + vetor [i];
    }

    printf ("= %2.f", resultado);



    arquivo = fopen ("Resultado06.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf (arquivo, "%f;", vetor[i]);
    }
    fprintf (arquivo, "%0.f;", resultado);
    fclose (arquivo);

	IO_pause("\nAperte ENTER para continuar");
}

void metodo7()
{
	numExercicio(7);

    int n = IO_readint ("Digite um valor inteiro: ");
    double vetor[n];
    double resultado = 0;
	printf ("\n");

	FILE *arquivo;
	arquivo = fopen("Ex4.txt", "r");

	for (int i = 0; i < n; i++)
    {
        vetor[i] = lerArquivodouble(arquivo);

    }
	fclose (arquivo);

	arquivo = fopen ("Resultado07.txt", "w");

	for (int i = 0; i < n; i++)
    {
         printf ("%lf ", vetor[i]);
         fprintf (arquivo, "%lf;", vetor[i]);
         resultado = resultado + vetor[i];
    }
    printf ("= %lf", resultado);
    fprintf (arquivo, "%lf;", resultado);

    fclose (arquivo);

	IO_pause("\nAperte ENTER para continuar");
}


int fibonacci(int n, int cont, int *primeiro, int *segundo, int proximo)
{
    while (cont < n)
    {
        proximo = *primeiro + *segundo;
        *primeiro = *segundo;
        *segundo = proximo;
        if (proximo % 2 == 0)
        {
            cont++;
            return proximo;
        }
    }
}

void metodo8()
{
	numExercicio(8);

    int n = IO_readint ("Digite um valor inteiro: ");
    int x = 0, cont = 0, primeiro = 0, segundo = 1, proximo;
    printf ("\n");

    FILE *arquivo;
    arquivo = fopen ("Resultado08.txt", "w");

    for (int i = 0; i < n; i++)
    {
        proximo = fibonacci(n , cont, &primeiro, &segundo, proximo);
        printf ("%d ", proximo);
        fprintf (arquivo, "%d;", proximo);
    }

    fclose (arquivo);

	IO_pause("\nAperte ENTER para continuar");
}

int gravaString(FILE *arquivo, char* palavra)
{
    if (arquivo == NULL)
    {
        return 0;
    }
    else
    {
        fputs (palavra , arquivo);
        return 1;
    }
}


void metodo9()
{

	numExercicio(9);

    char palavra[50];
    int cont = 0;

    printf ("Digite uma palavra: ");
    fgets (palavra, 50, stdin);
    printf ("\n");
    FILE *arquivo;

    arquivo = fopen ("Resultado09.txt", "w");

    int x = gravaString(arquivo, palavra);

    if (x == 0) // TESTE
    {
        printf ("Erro ao detectar o arquivo!\n");
    }

    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
        {
            cont++;
        }
    }
    printf ("%s", palavra);
    printf ("%d", cont);
    fprintf (arquivo, "%d", cont);

    fclose (arquivo);

	IO_pause("\nAperte ENTER para continuar");
}

void metodo10()
{
	numExercicio(10);

	char palavra[50];
    int cont = 0;

    printf ("Digite uma palavra: ");
    fgets (palavra, 50, stdin);
    printf ("\n");

    FILE *arquivo;

    arquivo = fopen ("Resultado10.txt", "w");
    int x = gravaString(arquivo, palavra);
    if (x == 0) // TESTE
    {
        printf ("Erro ao detectar o arquivo!\n");
    }

    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] >= '5' && palavra[i] <= '9')
        {
            cont++;
        }
    }

    printf ("%s", palavra);
    printf ("%d", cont);
    fprintf (arquivo, "%d", cont);
    fclose (arquivo);

	IO_pause("\nAperte ENTER para continuar");
}

int main ( )
{
	// definir dado
	int x = 0;
	// repetir at� desejar parar
	do
	{
		// identificar
		IO_id ( "ExerciciosE07 - Programa - v1.0" );
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
Digite um valor inteiro: 5


N = 5 => 4 8 12 16 20

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 2
Digite um valor inteiro: 5


N = 5 => 65 55 45 35 25

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 3
Digite um valor inteiro: 5

 N = 5 => 1 5 25 125 625

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 4
Digite um valor inteiro: 5

 N = 5 => 1/625 1/125 1/25 1/5 1

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 5
Digite um valor inteiro: 5
Digite um valor real: 0.5

 N = 5 => 1 1/0.500000 1/0.125000 1/0.031250 1/0.007813

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 6
Digite um valor inteiro: 5

1.000000 2.000000 8.000000 32.000000 128.000000 = 171

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 7
Digite um valor inteiro: 5

0.001600 0.008000 0.040000 0.200000 1.000000 = 1.249600

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 8
Digite um valor inteiro: 5

2 8 34 144 610

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 9
Digite uma palavra: PaReDe de TiJoLoS AmaRElOs

PaReDe de TiJoLoS AmaRElOs
12

Aperte ENTER para continuar

///////////////////////////////////////////

Exercicio 10
Digite uma palavra: P4R3D3 de T1J0L05 4maR3105

P4R3D3 de T1J0L05 4maR3105
2

Aperte ENTER para continuar

///////////////////////////////////////////

 */
