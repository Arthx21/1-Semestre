#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANO 365
#define MES 30

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Datas {
    int dias[3];
    struct Data data[3];
};

int q_01(int m, int n, int a[])
{
    int x = 0;
    if (0<m && m < n-1 && a[m-1] - a[m] > 0 && a[m] - a[m+1] < 0 )
    {
        x = 1;
    }
    if (0 < m && m < n)
    if (x >= 0)
    {
      x = x + q_01(m - 1, n , a);
    }
    else
    {
      x = -m;
    }
    return (x);
}

void q_02 (char *p, char *q)
{
    char *r = calloc(strlen(p)*strlen(q)+1, sizeof(char));
    int k = 0;
    for (int x = 0; x < strlen(p) ; x++)
    {
        for (int y = 0; y < strlen(q) ; y++)
        {
            if (x == strlen(p)/2)
            {
                r[k] = p[x];
                r[k+1] = q[y];
                k = k + 2;
                if (k > 6)
                {
                    y = strlen(q);
                    x = strlen(p);
                }
            }
        }
        printf ("[%s]\n" , r);
    }
}

void q_03(int a, int b, int c, char m [][3][7])
{
  for (int x = 0; x < a; x++)
    {
      for (int y = 0; y < b; y++)
          if ('A' < m[x][0][0] && m[x][0][0] < 'Z')
          {
            printf ("%8s" , m[x][2]);
            y = b;
          }
          printf ("\n");
    }

}

void q_04(char *p)
{
    int x = 0;
    for (int y = 0; y < strlen(p); y = y + 1)
    {
        if (y < strlen(p) - 1 && (p[y] == 'a' || p[y] == 'o'))
        {
            for (int z = y; z < strlen(p); z++)
            {
                p[z] = p[z + 1];
            }
        }
        printf(" [%s]\n", p);
    }
}


char* q_05(int x, int y, char *p)
{
  char c = '_';
  if ( 0 <= x && x < strlen(p) && 0 <= y && y < strlen(p))
  { c = p[x]; p[x] = p[y]; p[y] = c; }
  return ( p );
}

int q_06(char *p)
{
  char matriz[3][9] = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' } , {'J', 'K' , 'L', 'M', 'N' , 'O', 'P', 'Q', 'R'} , { 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' } };
  int soma = 0;
  int resultado = 0;
  int aux = 0;

  for (int i = 0; i < strlen(p); i++)
    {
      for (int j = 0; j < 3 ; j++)
        {
          for (int k = 0; k < 9; k++)
            {
              if (p[i] == matriz [j][k])
              {
                soma = soma + k + 1;
              }
            }
        }
    }

  if (soma != 11 && soma != 22)
  {
    aux = soma % 10;
    soma = soma / 10;
    resultado = aux + soma;
    return (resultado);
  }
  else
  {
    return (soma);
  }
}

void calcularData(int dias_vividos, struct Data *data) {
  data->ano = dias_vividos / ANO;
  int dias_restantes = dias_vividos % ANO;
  data->mes = dias_restantes / MES;
  data->dia = dias_restantes % MES;
}

int converterparadia(struct Data data) {
  return data.mes * MES + data.dia;
}

int encontrarAniversario(struct Datas *datas) {
  int dias_atual = converterparadia((struct Data){0, 0, 0});
  int menor_diferenca = ANO;
  int indice = -1;

  for (int i = 0; i < 3; i++) {
      int dia_do_ano = converterparadia(datas->data[i]);
      int diferenca = (dia_do_ano - dias_atual + ANO) % ANO;
      if (diferenca < menor_diferenca) {
          menor_diferenca = diferenca;
          indice = i;
      }
  }

  return indice;
}

void q_08() {
    int num = 0;
    FILE *x1;
    FILE *x2;
    FILE *x3;

    x1 = fopen("DADOS.txt", "r");
    x2 = fopen("PARES.txt", "w+");
    x3 = fopen("RESULTADOS.txt", "w");

    if (x1 == NULL || x2 == NULL || x3 == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    while (fscanf(x1, "%d", &num) != EOF) {
        if (num % 2 != 0) {
            fprintf(x3, "%d\n", num);
        } else {
            fprintf(x2, "%d\n", num);
        }
    }

    rewind(x2); // Volta ao início do arquivo PARES.txt para leitura

    while (fscanf(x2, "%d", &num) != EOF) {
        fprintf(x3, "%d\n", num);
    }

    fclose(x1);
    fclose(x2);
    fclose(x3);
}


int main(void) {

  int array[6] = {7 , 9 , 6 , 8 , 3 , 5};
  int n = 6;

  printf ("\nQuestao 1 = %d\n", q_01(n - 1, n , array) );

  printf ("\nQuestao 2 \n");
  q_02 ("goiabada" , "queijo");
  printf ("\n");

  printf ("\nQuestao 3\n");
  char m[][3][7] = {{{"Azul" }, {"Blue" }, {"Blau" }},
                    {{"Branco" }, {"White" }, {"Weiss" }},
                    {{"Verde" }, {"Green" }, {"Grun" }}};
  q_03(3,3,7,m);

  printf ("\nQuestao 4 \n");
  char b[14] = "acastanholada";
  q_04(b);
  printf ("\n");

  printf ("\nQuestao 5\n");
  char p[6] = "perda";
  char *exemplo  = q_05 (1 , 4 , q_05 (2 , 3 , p));
  printf ("[%s]\n", exemplo);
  exemplo = q_05 (2 , 3 , q_05 (1 , 4 , p));
  printf ("[%s]\n", exemplo);

  printf ("\nQuestao 6 \n");
  printf ("%d", q_06("ZIRALDO"));
  printf ("\n");

  printf ("\nQuestao 7 \n");
  struct Datas datas = {
      .dias = {9876, 8967, 6789}
  };
  for (int i = 0; i < 3; i++) {
      calcularData(datas.dias[i], &datas.data[i]);
  }
  int indice = encontrarAniversario(&datas);
  printf("O professor %d fara aniversario primeiro.\n", indice + 1);
  printf ("\n");

  printf ("\nQuestao 8 \n");
  q_08();
  printf ("\n");

}

/*
    RESULTADOS DOS TESTES

///////////////////////////////////

Questao 1 = 2

///////////////////////////////////

Questao 2
[]
[]
[]
[]
[bqbubebi]

///////////////////////////////////

Questao 3

   Weiss
    Grun

///////////////////////////////////

Questao 4
 [castanholada]
 [cstanholada]
 [cstanholada]
 [cstnholada]
 [cstnholada]
 [cstnhlada]
 [cstnhlda]
 [cstnhlda]

///////////////////////////////////

Questao 5
[padre]
[perda]

///////////////////////////////////

Questao 6
4

///////////////////////////////////

Questao 7
O professor 1 fara aniversario primeiro.

///////////////////////////////////

Questao 8 //Está no arquivo

///////////////////////////////////

*/

