/*
AUTOR: Arthur Souza Carvalho
data: 20/06/2024
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstring>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::fstream;

#include <cstdlib>
#include <ctime>

typedef  struct s_intArray
{
int length;
int *data; 
} intArray; 

typedef intArray* ref_intArray;

void lerArray(int **array, int tamanho)
{
  cout << "Digite " << tamanho << " valores inteiros: " << endl;
  for (int i = 0; i < tamanho; i++)
    {
      cout << "Digite o " << i + 1 << "º número: ";
      cin >> (*array)[i];
    }
}

void imprimirArray(int *array, int tamanho)
{
  cout << "Os valores digitados foram: " << endl;
  for (int i = 0; i < tamanho; i++)
    {
      cout << "[" << array[i] << "] ";
    }
  cout << endl;
}

int* array_push_back ( int *array, int valor, int n )
{
    int *new_array = new int [ n + 1 ];
  
  for ( int i = 0; i < n; i++ )
      {
        new_array[i] = array[i];
      }
  new_array[n] = valor;
  
  return new_array;
}

void exercicio1()
{
  int n = 0;
  cout << "Digite o tamanho para o array: ";
  cin >> n;
  
  int *array = new int [ n ];

  lerArray(&array, n);
  imprimirArray(array, n);

  int valor;
  cout << "Digite o valor que deseja adicionar ao array: ";
  cin >> valor;

  array = array_push_back(array, valor, n);
  
  imprimirArray(array, n + 1);

  delete [] array;
}

int* array_pop_back ( int *array , int n ) 
{
  int *new_array = new int [ n - 1 ];

  for ( int i = 0; i < n - 1; i++ )
    {
      new_array[i] = array[i];
    }

  return new_array;
}

void exercicio2()
{
  int n = 0;
  cout << "Digite o tamanho para o array: ";
  cin >> n;

  int *array = new int [ n ];

  lerArray(&array, n);
  imprimirArray(array, n);

  array = array_pop_back(array, n);

  imprimirArray(array, n - 1);

  delete [] array;
}

int* array_push_front ( int value, int *array , int n)
{
  int *new_array = new int [ n + 1 ];

  new_array[0] = value;
  for ( int i = 0; i < n; i++ )
    {
      new_array[i + 1] = array[i];
    }
  
  return new_array;
}

void exercicio3()
{
  int n = 0;
  cout << "Digite o tamanho para o array: ";
  cin >> n;

  int *array = new int [ n ];
  
  lerArray(&array, n);
  imprimirArray(array, n);

  int valor;
  cout << "Digite o valor que deseja adicionar ao array: ";
  cin >> valor;

  array = array_push_front(valor, array, n);

  imprimirArray(array, n + 1);

  delete [] array;
}

int* array_pop_front ( int *array , int n )
{
  int *new_array = new int [ n - 1 ];
  
  for ( int i = 0; i < n - 1; i++ )
    {
      new_array[i] = array[i + 1];
    }
  return new_array;
}

void exercicio4()
{
  int n = 0;
  cout << "Digite o tamanho para o array: ";
  cin >> n;

  int *array = new int [ n ];

  lerArray(&array, n);
  imprimirArray(array, n);

  array = array_pop_front(array, n);

  imprimirArray(array, n - 1);

  delete [] array;
}

int* array_push_mid ( int *array, int value , int n) 
{
  int *new_array = new int [ n + 1 ];
  int x;
  
  x = n / 2;
  
  for ( int i = 0; i < n; i++ )
    {
      new_array[i] = array[i];
    }
  
  new_array[x] = value;

  for ( int i = x + 1; i < n + 1; i++ )
    {
      new_array[i] = array[i - 1];
    }

  return new_array;
}

void exercicio5()
{
  int n = 0;
  cout << "Digite o tamanho para o array: ";
  cin >> n;

  int *array = new int [ n ];

  lerArray(&array, n);
  imprimirArray(array, n);

  int valor;
  cout << "Digite o valor que deseja adicionar ao array: ";
  cin >> valor;

  array = array_push_mid(array, valor, n);

  imprimirArray(array, n + 1);

  delete [] array;
}

int* array_pop_mid ( int *array, int n ) 
{
  int *new_array = new int [ n - 1 ];

  for ( int i = 0; i < n / 2; i++ )
    {
      new_array[i] = array[i];
    }
  
  for ( int i = n / 2; i < n - 1; i++ )
    {
      new_array[i] = array[i + 1];
    }
  
  return new_array;
}


void exercicio6()
{
  int n = 0;
  cout << "Digite o tamanho para o array: ";
  cin >> n;

  int *array = new int [ n ];

  lerArray(&array, n);
  imprimirArray(array, n);

  array = array_pop_mid(array, n);

  imprimirArray(array, n - 1);

  delete [] array;
}

int intArray_cmp ( ref_intArray p, ref_intArray q ) 
{
  if ( p->length != q->length )
    return 0;

  for ( int i = 0; i < p->length; i++ )
    {
      if ( p->data[i] != q->data[i] )
        return 0;
    }

  return 1;
}

void exercicio7()
{
  intArray array1;
  intArray array2;

  cout << "Digite o tamanho do array 1: ";
  cin >> array1.length;

  array1.data = new int [ array1.length ];

  lerArray(&array1.data, array1.length);

  cout << "Digite o tamanho do array 2: ";
  cin >> array2.length;

  array2.data = new int [ array2.length ];

  lerArray(&array2.data, array2.length);

  if ( intArray_cmp(&array1, &array2) )
  {
    cout << "Os arrays são iguais." << endl;
  }
  else
  {
    cout << "Os arrays são diferentes." << endl;
  }

  delete [] array1.data;
  delete [] array2.data;
}

ref_intArray intArray_cat ( ref_intArray p, ref_intArray q ) 
{
  ref_intArray new_array = new intArray;

  new_array->length = p->length + q->length;

  new_array->data = new int [ new_array->length ];

  for ( int i = 0; i < p->length; i++ )
    {
      new_array->data[i] = p->data[i];
    }
  for ( int i = 0; i < q->length; i++ )
    {
      new_array->data[i + p->length] = q->data[i];
    }
  
  return new_array;
}

void exercicio8()
{
  intArray array1;
  intArray array2;
  intArray *array3;

  cout << "Digite o tamanho do array 1: ";
  cin >> array1.length;

  array1.data = new int [ array1.length ];

  lerArray(&array1.data, array1.length);

  cout << "Digite o tamanho do array 2: ";
  cin >> array2.length;

  array2.data = new int [ array2.length ];

  lerArray(&array2.data, array2.length);

  array3 = intArray_cat(&array1, &array2);
  
  cout << endl << "Os arrays concatenados são: " << endl;
  imprimirArray(array3->data, array3->length);

  delete [] array1.data;
  delete [] array2.data;
  delete [] array3->data;
}

int intArray_seek ( ref_intArray a, int x ) 
{
  for ( int i = 0; i < a->length; i++ )
    {
      if ( a->data[i] == x )
        return i;
    }
  
  return 0;
}

void exercicio9()
{
  intArray array1;
  
  cout << "Digite o tamanho do array 1: ";
  cin >> array1.length;

  array1.data = new int [ array1.length ];

  lerArray(&array1.data, array1.length);

  int x;
  cout << "Digite o valor que deseja buscar: ";
  cin >> x;

  int posicao = intArray_seek(&array1, x);

  if ( posicao == 0 )
  {
    cout << "O valor não foi encontrado no array." << endl;
  }
  else
  {
    cout << "O valor foi encontrado na posição " << posicao << "." << endl;
  }

  delete [] array1.data;
}

ref_intArray intArray_sub ( ref_intArray a, int start, int size ) 
{
  ref_intArray new_array = new intArray;

  new_array->length = size - start;

  new_array->data = new int [ new_array->length];

  for ( int i = 0; i < size; i++ )
    {
      new_array->data[i] = a->data[start + i];
    }
  
  return new_array;
}

void exercicio10()
{
  intArray array1;
  intArray *array2;

  cout << "Digite o tamanho do array 1: ";
  cin >> array1.length;

  array1.data = new int [ array1.length ];

  lerArray(&array1.data, array1.length);

  int x;
  cout << "Digite a posicao que deseja comecar: ";
  cin >> x;

  array2 = intArray_sub ( &array1,  x,  array1.length );

  cout << endl << "O array criado é: " << endl;
  imprimirArray(array2->data, array2->length);

  delete [] array1.data;
  delete [] array2->data;
}

int main ()
{
    int x = 1;

    cout << "\n0 - Finalizar o programa" << endl;
    cout << "1 - Exercicio (1)" << endl;
    cout << "2 - Exercicio (2)" << endl;
    cout << "3 - Exercicio (3)" << endl;
    cout << "4 - Exercicio (4)" << endl;
    cout << "5 - Exercicio (5)" << endl;
    cout << "6 - Exercicio (6)" << endl;
    cout << "7 - Exercicio (7)" << endl;
    cout << "8 - Exercicio (8)" << endl;
    cout << "9 - Exercicio (9)" << endl;
    cout << "10 - Exercicio (10)" << endl;

    while ( x != 0)
    {
        cout << "\nDigite um exercicio: ";
        cin >> x;
        switch (x)
        {
        case 1: exercicio1(); break;
        case 2: exercicio2(); break;
        case 3: exercicio3(); break;
        case 4: exercicio4(); break;
        case 5: exercicio5(); break;
        case 6: exercicio6(); break;
        case 7: exercicio7(); break;
        case 8: exercicio8(); break;
        case 9: exercicio9(); break;
        case 10: exercicio10(); break;
        case 0:
            cout << "\nOBRIGADO POR UTILIZAR O PROGRAMA!!!" << endl;
            break;
        default:
            cout << "\nO valor inserido nao e valido!\n" << endl;
        }
    }
}

/*
Resultados dos testes

////////////////////////////////////////////////

Digite um exercicio: 1
Digite o tamanho para o array: 4
Digite 4 valores inteiros: 
Digite o 1º número: 1
Digite o 2º número: 2
Digite o 3º número: 3
Digite o 4º número: 4
Os valores digitados foram: 
[1] [2] [3] [4] 
Digite o valor que deseja adicionar ao array: 5
Os valores digitados foram: 
[1] [2] [3] [4] [5] 

////////////////////////////////////////////////

Digite um exercicio: 2   
Digite o tamanho para o array: 5
Digite 5 valores inteiros: 
Digite o 1º número: 1
Digite o 2º número: 2
Digite o 3º número: 3
Digite o 4º número: 4
Digite o 5º número: 5
Os valores digitados foram: 
[1] [2] [3] [4] [5] 
Os valores digitados foram: 
[1] [2] [3] [4]

////////////////////////////////////////////////

Digite um exercicio: 3
Digite o tamanho para o array: 4
Digite 4 valores inteiros: 
Digite o 1º número: 2
Digite o 2º número: 3
Digite o 3º número: 4
Digite o 4º número: 5
Os valores digitados foram: 
[2] [3] [4] [5] 
Digite o valor que deseja adicionar ao array: 1
Os valores digitados foram: 
[1] [2] [3] [4] [5]

////////////////////////////////////////////////

Digite um exercicio: 4
Digite o tamanho para o array: 5
Digite 5 valores inteiros: 
Digite o 1º número: 1
Digite o 2º número: 2
Digite o 3º número: 3
Digite o 4º número: 4
Digite o 5º número: 5
Os valores digitados foram: 
[1] [2] [3] [4] [5] 
Os valores digitados foram: 
[2] [3] [4] [5]

////////////////////////////////////////////////

Digite um exercicio: 5
Digite o tamanho para o array: 4
Digite 4 valores inteiros: 
Digite o 1º número: 1
Digite o 2º número: 2
Digite o 3º número: 4
Digite o 4º número: 5
Os valores digitados foram: 
[1] [2] [4] [5] 
Digite o valor que deseja adicionar ao array: 3
Os valores digitados foram: 
[1] [2] [3] [4] [5]

////////////////////////////////////////////////

Digite um exercicio: 6
Digite o tamanho para o array: 5
Digite 5 valores inteiros: 
Digite o 1º número: 1
Digite o 2º número: 2
Digite o 3º número: 2
Digite o 4º número: 3
Digite o 5º número: 4
Os valores digitados foram: 
[1] [2] [2] [3] [4] 
Os valores digitados foram: 
[1] [2] [3] [4]

////////////////////////////////////////////////

Digite um exercicio: 7
Digite o tamanho do array 1: 5
Digite 5 valores inteiros: 
Digite o 1º número: 1
Digite o 2º número: 2
Digite o 3º número: 3
Digite o 4º número: 4
Digite o 5º número: 5
Digite o tamanho do array 2: 5
Digite 5 valores inteiros: 
Digite o 1º número: 1
Digite o 2º número: 2
Digite o 3º número: 3
Digite o 4º número: 4
Digite o 5º número: 5
Os arrays são iguais.

////////////////////////////////////////////////

Digite um exercicio: 8
Digite o tamanho do array 1: 3
Digite 3 valores inteiros: 
Digite o 1º número: 1
Digite o 2º número: 2
Digite o 3º número: 3
Digite o tamanho do array 2: 3
Digite 3 valores inteiros: 
Digite o 1º número: 4
Digite o 2º número: 5
Digite o 3º número: 6

Os arrays concatenados são: 
Os valores digitados foram: 
[1] [2] [3] [4] [5] [6] 

////////////////////////////////////////////////

Digite um exercicio: 9
Digite o tamanho do array 1: 5
Digite 5 valores inteiros: 
Digite o 1º número: 1
Digite o 2º número: 2
Digite o 3º número: 3
Digite o 4º número: 4
Digite o 5º número: 5
Digite o valor que deseja buscar: 3
O valor foi encontrado na posição 2.

////////////////////////////////////////////////

Digite um exercicio: 10
Digite o tamanho do array 1: 5
Digite 5 valores inteiros: 
Digite o 1º número: 1 
Digite o 2º número: 2
Digite o 3º número: 3
Digite o 4º número: 4
Digite o 5º número: 5
Digite a posicao que deseja comecar: 2

O array criado é: 
Os valores digitados foram: 
[3] [4] [5] 

////////////////////////////////////////////////

*/