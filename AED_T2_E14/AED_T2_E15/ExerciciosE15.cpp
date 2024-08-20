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

char* str_push_back (char *s, char c)
{
  int len = strlen(s);
  
  char *string = new char[len + 2];

  strcpy(string, s);
  
  string[len] = c;
  
  string[len + 1] = '\0';
  
  return string;
}

void exercicio1()
{
  char* frase = new char[30];
  char letra;

  cout << "Digite uma frase: ";
  cin >> frase;

  cout << "Digite uma letra: ";
  cin >> letra;

  frase = str_push_back(frase, letra);


  cout << "Frase digitada: " << frase << endl;

  delete[] frase;
}

char* str_pop_back ( char *s )
{
  int len = strlen(s);

  char *string = new char[len - 1];
  strcpy(string, s);
  string[len - 1] = '\0';
  
  return string;
}

void exercicio2()
{
  char* frase = new char[30];

  cout << "Digite uma frase: ";
  cin >> frase;

  cout << "Frase digitada: " << frase << endl;

  frase = str_pop_back(frase);

  cout << "Frase digitada apos alteracao: " << frase << endl;

  delete[] frase;
}

char* str_push_front ( char *s, char c )
{
  int len = strlen(s);

  char *string = new char[len + 2];
  string[0] = c;
  strcpy(string + 1, s);
  string[len + 1] = '\0';

  return string;
}

void exercicio3()
{
  char* frase = new char[30];
  char letra;

  cout << "Digite uma frase: ";
  cin >> frase;

  cout << "Digite uma letra: ";
  cin >> letra;
  
  cout << "Frase digitada: " << frase << endl;

  frase = str_push_front(frase, letra);

  cout << "Frase digitada apos alteracao: " << frase << endl;

  delete[] frase;
}

char* str_pop_front ( char *s )
{
  int len = strlen(s);

  char *string = new char[len - 1];

  strcpy(string, s + 1);

  string[len - 1] = '\0';

  return string;
}

void exercicio4()
{
  char* frase = new char[30];

  cout << "Digite uma frase: ";
  cin >> frase;

  cout << "Frase digitada: " << frase << endl;

  frase = str_pop_front(frase);

  cout << "Frase digitada apos alteracao: " << frase << endl;

  delete[] frase;
}

char* str_push_mid ( char *s, char c )
{
  int len = strlen(s);
  int x;

  char *string = new char[len + 2];

    x = len / 2;
    for (int i = 0; i < x; i++)
    {
      string[i] = s[i];
    }
  
    string[x] = c;
  
    for (int i = x + 1; i < len + 1; i++)
      {
        string[i] = s[i - 1];
      }

  string[len + 1] = '\0';
  return string;
}

void exercicio5()
{
  char* frase = new char[30];
  char letra;

  cout << "Digite uma frase: ";
  cin >> frase;

  cout << "Digite uma letra: ";
  cin >> letra;

  cout << "Frase digitada: " << frase << endl;

  frase = str_push_mid(frase, letra);

  cout << "Frase digitada apos alteracao: " << frase << endl;

  delete[] frase;
}

char* str_pop_mid ( char *s ) 
{
  int len = strlen(s);
  int x;
  
  char *string = new char[len - 1];

  x = len / 2;

  for (int i = 0; i < x; i++)
    {
      string[i] = s[i];
    }
  for (int i = x; i < len - 1; i++)
    {
      string[i] = s[i + 1];
    }
  
  string[len - 1] = '\0';
  return string;
}

void exercicio6()
{
  char* frase = new char[30];

  cout << "Digite uma frase: ";
  cin >> frase;

  cout << "Frase digitada: " << frase << endl;

  frase = str_pop_mid(frase);

  cout << "Frase digitada apos alteracao: " << frase << endl;

  delete[] frase;
}

char* str_insert ( char *s, char c, int index ) 
{
  int len = strlen(s);

  char *string = new char[len + 2];

  for (int i = 0; i < index; i++)
    {
      string[i] = s[i];
    }
  
  string[index] = c;

  for (int i = index + 1; i < len + 1; i++)
    {
      string[i] = s[i - 1];
    }

  string[len + 1] = '\0';
  return string;
}

void exercicio7()
{
  char* frase = new char[30];
  char letra;

  int index;
  
  cout << "Digite uma frase: ";
  cin >> frase;

  cout << "Digite uma letra: ";
  cin >> letra;
  
  int len = strlen(frase);
  
  do
  {
    cout << "Digite um indice para adicionar: ";
    cin >> index;
    if ( index < 0 || index > len )
    {
      cout << "Indice invalido!" << endl;
    }
  } while (index < 0 || index > len);
  

  cout << "Frase digitada: " << frase << endl;

  frase = str_insert(frase, letra, index);

  cout << "Frase digitada apos alteracao: " << frase << endl;

  delete[] frase;
}

char* str_remove ( char *s, int index ) 
{
  int len = strlen(s);

  char *string = new char[len - 1];

  for (int i = 0; i < index; i++)
    {
      string[i] = s[i];
    }
  
  for (int i = index; i < len - 1; i++)
    {
      string[i] = s[i + 1];
    }

  string[len - 1] = '\0';
  return string;
}

void exercicio8()
{
  char* frase = new char[30];
  int index;

  cout << "Digite uma frase: ";
  cin >> frase;

  int len = strlen(frase);

  do
  {
    cout << "Digite um indice para remover: ";
    cin >> index;
    if ( index < 0 || index > len )
    {
      cout << "Indice invalido!" << endl;
    }
  } while (index < 0 || index > len);


  cout << "Frase digitada: " << frase << endl;

  frase = str_remove(frase, index);

  cout << "Frase digitada apos alteracao: " << frase << endl;

  delete[] frase;
}

 char* str_chr ( char *s, char c ) 
{
  int len = strlen(s);

  for (int i = 0; i < len; i++)
    {
      if (s[i] == c)
      {
        return &s[i];
      }
    }

  cout << "Nao foi encontrado" << endl;
  return nullptr;
}

void exercicio9()
{
  char* frase = new char[30];
  char letra;

  cout << "Digite uma frase: ";
  cin >> frase;

  cout << "Digite uma letra: ";
  cin >> letra;

  cout << "Frase digitada: " << frase << endl;

  char* result = str_chr(frase, letra);

  if (result != nullptr)
  {
    cout << "Encontrado na posicao: " << result - frase << endl;
  }
  
  delete[] frase;
}

char* str_tok ( char *s, char delimiter )
{
  int len = strlen(s);

  char *string = new char[len + 1];
  
  for (int i = 0; i < len; i++)
    {
      if (s[i] == delimiter) //se nao achar o delimitador, a frase original não vai mudar
      {
        string[i] = '\0';
        return string;
      }
      else
      {
         string[i] = s[i];
      }
    }

  string[len + 1] = '\0';
  return string;
}

void exercicio10()
{
char* frase = new char[30];
char letra;

cout << "Digite uma frase: ";
cin >> frase;

cout << "Digite uma letra para limitar a string: ";
cin >> letra;

cout << "Frase digitada: " << frase << endl;

frase = str_tok(frase, letra);

cout << "Frase digitada apos alteracao: " << frase << endl;

delete[] frase;
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
Digite uma frase: ABC
Digite uma letra: 1
Frase digitada: ABC1

////////////////////////////////////////////////

Digite um exercicio: 2
Digite uma frase: ABCD
Frase digitada: ABCD
Frase digitada apos alteracao: ABC

////////////////////////////////////////////////

Digite um exercicio: 3
Digite uma frase: ABC
Digite uma letra: D
Frase digitada: ABC
Frase digitada apos alteracao: DABC

////////////////////////////////////////////////

Digite um exercicio: 4
Digite uma frase: DABC
Frase digitada: DABC
Frase digitada apos alteracao: ABC

////////////////////////////////////////////////

Digite um exercicio: 5
Digite uma frase: ABDEF
Digite uma letra: C
Frase digitada: ABDEF
Frase digitada apos alteracao: ABCDEF

////////////////////////////////////////////////

Digite um exercicio: 6
Digite uma frase: ABCDE 
Frase digitada: ABCDE
Frase digitada apos alteracao: ABDE

////////////////////////////////////////////////

Digite um exercicio: 7
Digite uma frase: ABCDE
Digite uma letra: F
Digite um indice para adicionar: 5
Frase digitada: ABCDE
Frase digitada apos alteracao: ABCDEF

////////////////////////////////////////////////

Digite um exercicio: 8
Digite uma frase: ABCCDE
Digite um indice para remover: 2
Frase digitada: ABCCDE
Frase digitada apos alteracao: ABCDE

////////////////////////////////////////////////

Digite um exercicio: 9
Digite uma frase: ABCDE
Digite uma letra: C
Frase digitada: ABCDE
Encontrado na posicao: 2

////////////////////////////////////////////////

Digite um exercicio: 10
Digite uma frase: ABCDEFGH
Digite uma letra para limitar a string: E
Frase digitada: ABCDEFGH
Frase digitada apos alteracao: ABCD

////////////////////////////////////////////////

*/