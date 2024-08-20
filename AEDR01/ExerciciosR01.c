#include "io.h"

void numExercicio(int x)   //funcao extra para identificar qual atividade esta sendo apresentada
{
  printf ("\nExercicio %d\n", x);
}

void metodo0() {
  IO_println ("\n\n\tObrigado por utilizar o meu programa!!!\n");
}

int soma_divisores_impares(int x)
{
  int soma = 0;
  for (int i = 1; i < x; i++)
    {
      if (i % 2 != 0)
      {
        if (x % i == 0)
        {
          soma += i;
        }
      }
    }
  return soma;
}

void metodo1()
{
  numExercicio(1);

  int n = IO_readint("Digite um valor inteiro para quantidade: ");
  int x[n];

  for (int i = 0; i < n; i++)
    {
      x[i] = IO_readint("Digite um valor inteiro: ");
    }

  for (int i = 0; i < n; i++)
    {
      int resposta = soma_divisores_impares(x[i]);
      printf ("\nA soma dos divisores impares do valor %d e igual a %d\n", x[i],  resposta);
    }

}

bool primo(int x)
{
  if (x < 0 || x == 1)
  {
    return false;
  }

  for (int i = 2; i < x; i++)
    {
      if (x % i == 0)
      {
        return false;
      }
    }

  return true;
}

void metodo2()
{
  numExercicio(2);

  int n = IO_readint("Digite um valor inteiro para quantidade: ");
  int x[n];

  for (int i = 0; i < n; i++)
    {
      x[i] = IO_readint("Digite um valor inteiro: ");
    }

  for (int i = 0; i < n; i++)
    {
      if (primo(x[i]))
      {
        printf ("\nO numero %d e primo", x[i]);
      }
      else
      {
        printf ("\nO numero %d NAO e primo", x[i]);
      }
    }
}

bool ehMinusculo(char x)
{
  if (x >= 'a' && x <= 'z')
  {
    return true;
  }
  return false;
}

bool ehMaiusculo(char x)
{
  if (x >= 'A' && x <= 'Z')
  {
    return true;
  }
  return false;
}

bool ehDigito(char x)
{
  if (x >= '0' && x <= '9')
  {
    return true;
  }
  return false;
}

bool ehLetra(char x)
{
  if (ehMinusculo(x) || ehMaiusculo(x))
  {
    return true;
  }
  return false;
}

bool ehOperadorlogico(char x)
{
  switch (x)
  {
  case '&':
  case '|':
  case '!':
    return true;
  default:
    return false;
  }
}

bool ehAritmetico(char x)
{
  switch (x) {
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
    return true;
  default:
    return false;
  }
}

bool ehRelacional(char x)
{
  switch(x) {
  case '>':
  case '<':
  case '=':
    return true;
  default:
    return false;
  }
}

bool ehSeparador(char x)
{
  switch (x) {
    case ' ':
    case '.':
    case ',':
    case ';':
    case ':':
    case '_':
      return true;
    default:
      return false;
  }
}

void metodo3()
{
  numExercicio(3);
  char palavra[50];


  printf ("Digite uma palavra: ");
  fgets (palavra, 50, stdin);


  for (int i = 0; i < strlen(palavra)-1; i++)
  {
      if (ehOperadorlogico(palavra[i]))
      {
        printf ("\nO caractere %c e um operador logico", palavra[i]);
      }
      if (ehAritmetico(palavra[i]))
      {
        printf ("\nO caractere %c e um operador aritmetico", palavra[i]);
      }
      if (ehRelacional(palavra[i]))
      {
        printf ("\nO caractere %c e um operador relacional", palavra[i]);
      }
      if (ehSeparador(palavra[i]))
      {
        printf ("\nO caractere %c e um separador", palavra[i]);
      }
    if (ehSeparador(palavra[i]) == false && ehOperadorlogico(palavra[i]) == false && ehAritmetico(palavra[i]) == false && ehRelacional(palavra[i]) == false)
    {
      printf ("\nO caractere %c e um simbolo qualquer", palavra[i]);
    }
  }
  printf ("\n");
}

void metodo4()
{
  numExercicio(4);

  char palavra[50];
  int contagem[7] = {0, 0, 0, 0, 0, 0, 0};
  printf ("Digite uma palavra: ");
  fgets (palavra, 50, stdin);

  for (int i = 0; i < strlen(palavra)-1; i++)
    {
      if (ehMaiusculo(palavra[i]))
      {
        contagem[0]++;
      }
      if (ehMinusculo(palavra[i]))
      {
        contagem[1]++;
      }
      if (ehDigito(palavra[i]))
      {
        contagem[2]++;
      }
      if (ehOperadorlogico(palavra[i]))
      {
        contagem[3]++;
      }
      if (ehAritmetico(palavra[i]))
      {
        contagem[4]++;
      }
      if (ehRelacional(palavra[i]))
      {
        contagem[5]++;
      }
      if (ehSeparador(palavra[i]))
      {
        contagem[6]++;
      }

    }

  printf ("\nA palavra tem %d letras maiusculas", contagem[0]);
  printf ("\nA palavra tem %d letras minusculas", contagem[1]);
  printf ("\nA palavra tem %d digitos", contagem[2]);
  printf ("\nA palavra tem %d operadores logicos", contagem[3]);
  printf ("\nA palavra tem %d operadores aritmeticos", contagem[4]);
  printf ("\nA palavra tem %d operadores relacionais", contagem[5]);
  printf ("\nA palavra tem %d separadores\n", contagem[6]);

}

bool no_intervalo(float min, float max, float x)
{
  if (x >= min && x <= max)
  {
    return true;
  }
  return false;
}

void metodo5()
{
  numExercicio(5);

  int n = IO_readint("Digite um valor inteiro para quantidade: ");
  float x[n], maior = 0, media1 = 0, media2 = 0, media3 = 0;
  float resultado1 = 0, resultado2 = 0, resultado3 = 0;
  float cont1 = 0, cont2 = 0, cont3 = 0;

  for (int i = 0; i < n; i++)
    {
      x[i] = IO_readfloat("Digite um valor real: ");
    }

  for (int i = 0; i < n; i++)
    {
      if (no_intervalo (-17.25, 93.75, x[i]))
      {
        media1 = media1 + x[i];
        cont1++;
      }
      if (x[i] < -17.25)
      {
        media2 = media2 + x[i];
        cont2++;
      }
      if (x[i] > 93.75)
      {
        media3 = media3 + x[i];
        cont3++;
      }
    }

  if (media1 !=0)
  {
    resultado1 = media1 / cont1;
  }
  if (media2 != 0)
  {
    resultado2 = media2 / cont2;
  }
  if (media3 != 0)
  {
    resultado3 = media3 / cont3;
  }
  printf ("\nA media dos valores no intervalo [-17.25, 93.75] e igual a %f", resultado1);
  printf ("\nA media dos valores abaixo de [-17.25] e igual a %f", resultado2);
  printf ("\nA media dos valores acima de [93.75] e igual a %f\n", resultado3);

  if (resultado1 > resultado2 && resultado1 > resultado3)
  {
    maior = resultado1;
  }
  if (resultado2 > resultado1 && resultado2 > resultado3)
  {
    maior = resultado2;
  }
  if (resultado3 > resultado1 && resultado3 > resultado2)
  {
    maior = resultado3;
  }

  printf ("A maior media entre os 3 e %f", maior);
}

float soma_cubos(int a, int b)
{
  int x = 0;
  float resultado = 0, inverso = 0;

  do {
    x = IO_readint("Digite um valor inteiro: ");
    if (x > a && x < b && x % 2 != 0)
    {
      x = pow (x, 3);
      inverso = 1.0 / x;
      resultado = resultado + inverso;
    }
  } while (x != -1);


  return resultado;
}

void metodo6()
{
  numExercicio(6);

  int a = IO_readint("Digite um valor inteiro para quantidade a: ");
  int b = IO_readint("Digite um valor inteiro para quantidade b: ");
  float resultado = 0;

    resultado = soma_cubos ( a , b );

  printf ("O resultado da soma dos cubos dos inversos e: %f\n", resultado);
}

bool no_intervalo2(float min, float max, float x)
{
  if (x > min && x < max)
  {
    return true;
  }
  return false;
}

void metodo7()
{
  numExercicio(7);

  float dentro = 0, fora = 0, abaixo = 0, acima = 0;
  float a = IO_readfloat("Digite um valor inteiro para quantidade a: ");
  float b = IO_readfloat("Digite um valor inteiro para quantidade b: ");
  float x = 0;

  do {
    x = IO_readfloat("Digite um valor real: ");
    if ( x != 0)
    {
      if (no_intervalo2(a, b, x))
      {
        dentro++;
      }
      else
      {
        fora++;
      }
      if (x <= a)
      {
        abaixo++;
      }
      if (x >= b)
      {
        acima++;
      }
    }
  } while (x != 0);

  float porAbaixo = (abaixo * 100) / fora;
  float porAcima = (acima * 100) / fora;

  printf ("\nA quantidade de numeros dentro do intervalo e: %0.f", dentro);
  printf ("\nA quantidade de numeros fora do intervalo e: %0.f", fora);
  printf ("\nA porcentagem de numeros acima do intervalo e: %.2f", porAcima);
  printf ("\nA porcentagem de numeros abaixo do intervalo e: %.2f\n", porAbaixo);

}

bool crescente(float x, float y, float z)
{
  if (x < y && y < z)
  {
    return true;
  }
  return false;
}

bool descresente(float x, float y, float z)
{
  if (x > y && y > z)
  {
    return true;
  }
  return false;
}

float maior(float x, float y, float z)
{
  if (x > y && x > z) {return x;}
  if (y > x && y > z) {return y;}
  if (z > x && z > y) {return z;}
  return 0;
}

float menor(float x, float y, float z)
{
  if (x < y && x < z) {return x;}
  if (y < x && y < z) {return y;}
  if (z < x && z < y) {return z;}
  return 0;
}

void metodo8()
{
  numExercicio(8);

  float x = IO_readfloat("Digite um valor real para x: ");
  float y = IO_readfloat("Digite um valor real para y: ");
  float z = IO_readfloat("Digite um valor real para z: ");
  if (crescente(x, y, z))
  {
    printf ("\nOs valores estao em ordem crescente");
  }
  if (descresente(x, y, z))
  {
    printf ("\nOs valores estao em ordem descrescente");
  }

  if (crescente(x, y, z) == false && descresente(x, y, z) == false)
  {
    printf ("\nOs valores nao estao em ordem crescente nem descrescente");
  }

  if (maior(x, y, z) == 0 && menor(x, y, z) == 0)
  {
    printf ("\nOs valores sao iguais");
  }
  else
  {
  printf ("\nO maior valor e: %.2f", maior(x, y, z));
  printf ( "\nO menor valor e: %.2f\n", menor(x, y, z));
  }
}

bool crescenteChar(char x, char y, char z)
{
  if (x < y && y < z)
  {
    return true;
  }
  return false;
}

bool descrecenteChar(char x, char y, char z)
{
  if (x > y && y > z)
  {
    return true;
  }
  return false;
}

bool sucessorChar(char x, char y)
{
  if (y - 1 == x)
  {
    return true;
  }
  return false;
}

void metodo9()
{
  numExercicio(9);

  char x = IO_readchar("Digite um valor para x: ");
  char y = IO_readchar("Digite um valor para y: ");
  char z = IO_readchar("Digite um valor para z: ");

  if (crescenteChar(x, y, z))
  {
    printf ("\nOs valores estao em ordem crescente");
  }
  if (descrecenteChar(x, y, z))
  {
    printf ("\nOs valores estao em ordem descrescente");
  }
  if (crescenteChar(x, y, z) == false && descrecenteChar(x, y, z) == false)
  {
    printf ("\nOs valores nao estao em ordem crescente nem descrescente");
  }

  if (sucessorChar(x, y))
  {
    printf ("\nO sucessor de y e o antecessor de x\n");
  }
  else
  {
    printf ("\nO sucessor de y NAO e o antecessor de x\n");
  }
}

bool descrecenteCadeiachar(char x[])
{
  for (int i = 0; i < strlen(x); i++)
    {
      if (x[i] < x[i+1])
      {
        return false;
      }
    }
  return true;
}


void metodo10()
{
  numExercicio(10);

  char x[10];
  char y[10];
  char z[10];

  printf ("Digite uma palavra: ");
  fgets(x, 10, stdin);
  printf ("Digite uma palavra: ");
  fgets(y, 10, stdin);
  printf ("Digite uma palavra: ");
  fgets(z, 10, stdin);

  if (descrecenteCadeiachar(x))
  {
    printf ("\nA cadeia de caracteres X e descrescente");
  }
  else
  {
    printf ("\nA cadeia de caracteres X NAO e descrescente");
  }
  if (descrecenteCadeiachar(y))
  {
    printf ("\nA cadeia de caracteres Y e descrescente");
  }
  else
  {
    printf ("\nA cadeia de caracteres Y NAO e descrescente");
  }
  if (descrecenteCadeiachar(z))
  {
    printf ("\nA cadeia de caracteres Z e descrescente");
  }
  else
  {
    printf ("\nA cadeia de caracteres Z NAO e descrescente");
  }

  if (strcmp(x, y) == 0 && strcmp(y, z) == 0)
  {
    printf ("\nAs cadeias de caracteres sao iguais");
  }

  if (strcmp(x , y) > 0 && strcmp(x, z) > 0)
  {
    printf ("\nA cadeia de caracteres X e Maior que as outras");
  }
  else if (strcmp (y , x) > 0 && strcmp(y, z) > 0)
  {
    printf ("\nA cadeia de caracteres Y e Maior que as outras");
  } else if (strcmp(z, y) > 0 && strcmp(z, x) > 0)
  {
    printf ("\nA cadeia de caracteres Z e Maior que as outras");
  }

  if (strcmp(x , y) < 0 && strcmp(x, z) < 0)
  {
    printf ("\nA cadeia de caracteres X e Menor que as outras");
  }
  if (strcmp(y , x) < 0 && strcmp(y, z) < 0)
  {
    printf ("\nA cadeia de caracteres Y e Menor que as outras");
  }
  if (strcmp(z, y) < 0 && strcmp(z, x) < 0)
  {
    printf ("\nA cadeia de caracteres Z e Menor que as outras");
  }

}


int main ( )
{

  int x = 0;

  do
  {

    IO_id ( "\nExercicios de Recuperacao 01" );

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
      case 9: metodo9 ( ); break;
      case 10: metodo10 ( ); break;
      default:
        printf ("Valor diferente das opcoes [0,1,2,3,4,5,6,7,8,9,10]");
    }
  }
  while ( x != 0 );

  IO_pause ( "Apertar ENTER para terminar" );
  return ( 0 );
}


/* Resultados dos testes Realizados:

///////////////////////////////////////////

Exercicio 1
Digite um valor inteiro para quantidade: 5
Digite um valor inteiro: 22
Digite um valor inteiro: 121
Digite um valor inteiro: 440
Digite um valor inteiro: 581
Digite um valor inteiro: 814

A soma dos divisores impares do valor 22 e igual a 12
A soma dos divisores impares do valor 121 e igual a 12
A soma dos divisores impares do valor 440 e igual a 72
A soma dos divisores impares do valor 581 e igual a 91
A soma dos divisores impares do valor 814 e igual a 456

///////////////////////////////////////////

Exercicio 2
Digite um valor inteiro para quantidade: 5
Digite um valor inteiro: -293
Digite um valor inteiro: -107
Digite um valor inteiro: 153
Digite um valor inteiro: 199
Digite um valor inteiro: 811

O numero -293 NAO e primo
O numero -107 NAO e primo
O numero 153 NAO e primo
O numero 199 e primo
O numero 811 e primo

///////////////////////////////////////////

Exercicio 3
Digite uma palavra: for(X=0;X<y&&y>=0;X=X+1)

O caractere f e um simbolo qualquer
O caractere o e um simbolo qualquer
O caractere r e um simbolo qualquer
O caractere ( e um simbolo qualquer
O caractere X e um simbolo qualquer
O caractere = e um operador relacional
O caractere 0 e um simbolo qualquer
O caractere ; e um separador
O caractere X e um simbolo qualquer
O caractere < e um operador relacional
O caractere y e um simbolo qualquer
O caractere & e um operador logico
O caractere & e um operador logico
O caractere y e um simbolo qualquer
O caractere > e um operador relacional
O caractere = e um operador relacional
O caractere 0 e um simbolo qualquer
O caractere ; e um separador
O caractere X e um simbolo qualquer
O caractere = e um operador relacional
O caractere X e um simbolo qualquer
O caractere + e um operador aritmetico
O caractere 1 e um simbolo qualquer
O caractere ) e um simbolo qualquer

///////////////////////////////////////////

Exercicio 4
Digite uma palavra: for(X=0;X<y&&y>=0;X=X+1)

A palavra tem 4 letras maiusculas
A palavra tem 5 letras minusculas
A palavra tem 3 digitos
A palavra tem 2 operadores logicos
A palavra tem 1 operadores aritmeticos
A palavra tem 5 operadores relacionais
A palavra tem 2 separadores

///////////////////////////////////////////

Exercicio 5
Digite um valor inteiro para quantidade: 10
Digite um valor real: -15.25
Digite um valor real: -12.50
Digite um valor real: 0.0
Digite um valor real: 6.75
Digite um valor real: 20.50
Digite um valor real: 50.0
Digite um valor real: 70.25
Digite um valor real: 85.25
Digite um valor real: 92.50
Digite um valor real: 98.75

A media dos valores no intervalo [-17.25, 93.75] e igual a 33.055557
A media dos valores abaixo de [-17.25] e igual a 0.000000
A media dos valores acima de [93.75] e igual a 98.750000
A maior media entre os 3 e 98.750000

///////////////////////////////////////////

Exercicio 6
Digite um valor inteiro para quantidade a: 20
Digite um valor inteiro para quantidade b: 60
Digite um valor inteiro: -20
Digite um valor inteiro: -11
Digite um valor inteiro: 0
Digite um valor inteiro: 1
Digite um valor inteiro: 10
Digite um valor inteiro: 21
Digite um valor inteiro: 36
Digite um valor inteiro: 51
Digite um valor inteiro: 70
Digite um valor inteiro: 80
Digite um valor inteiro: -1
O resultado da soma dos cubos dos inversos e: 0.000116

///////////////////////////////////////////

Exercicio 7
Digite um valor inteiro para quantidade a: 20
Digite um valor inteiro para quantidade b: 60
Digite um valor real: -20
Digite um valor real: -10
Digite um valor real: 1
Digite um valor real: 10
Digite um valor real: 20
Digite um valor real: 30
Digite um valor real: 60
Digite um valor real: 70
Digite um valor real: 80
Digite um valor real: 0

A quantidade de numeros dentro do intervalo e: 1
A quantidade de numeros fora do intervalo e: 8
A porcentagem de numeros acima do intervalo e: 37.50
A porcentagem de numeros abaixo do intervalo e: 62.50

///////////////////////////////////////////

Exercicio 8 exemplo1
Digite um valor real para x: 10
Digite um valor real para y: 20
Digite um valor real para z: 30

Os valores estao em ordem crescente
O maior valor e: 30.00
O menor valor e: 10.00

Exercicio 8 exemplo2
Digite um valor real para x: 30
Digite um valor real para y: 20
Digite um valor real para z: 10

Os valores estao em ordem descrescente
O maior valor e: 30.00
O menor valor e: 10.00

Exercicio 8 exemplo3
Digite um valor real para x: 10
Digite um valor real para y: 10
Digite um valor real para z: 10

Os valores nao estao em ordem crescente nem descrescente
Os valores sao iguais

///////////////////////////////////////////

Exercicio 9   exemplo1
Digite um valor para x: 1
Digite um valor para y: 2
Digite um valor para z: 3

Os valores estao em ordem crescente
O sucessor de y e o antecessor de x

Exercicio 9    exemplo2
Digite um valor para x: 3
Digite um valor para y: 2
Digite um valor para z: 1

Os valores estao em ordem descrescente
O sucessor de y NAO e o antecessor de x

Exercicio 9    exemplo3
Digite um valor para x: 1
Digite um valor para y: 1
Digite um valor para z: 1

Os valores nao estao em ordem crescente nem descrescente
O sucessor de y NAO e o antecessor de x

///////////////////////////////////////////

Exercicio 10
Digite uma palavra: abc
Digite uma palavra: ABC
Digite uma palavra: cba

A cadeia de caracteres X NAO e descrescente
A cadeia de caracteres Y NAO e descrescente
A cadeia de caracteres Z e descrescente
A cadeia de caracteres Z e Maior que as outras
A cadeia de caracteres Y e Menor que as outras

///////////////////////////////////////////

*/
