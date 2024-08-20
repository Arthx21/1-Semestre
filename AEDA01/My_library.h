#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void numExercicio(int x)   //funcao extra para identificar qual atividade esta sendo apresentada
{
  printf ("\nExercicio %d\n", x);
}

int readInt(char* texto)
{
    int x = 0;
        printf ("%s", texto);
    scanf ("%d", &x);
    getchar();
    return x;
}

void println (char* texto)
{
    printf ("%s\n", texto);
}
