/*
AUTOR: Arthur Souza Carvalho


Do exercicio 7 ao 10 tive muito auxilio do ChatGPT.
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

#include <sstream>
using std::stringstream;

#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>

  int getInt(string &palavra) {
      if (palavra.empty()) {
          return -1;
      }

      int resultado = 0;
      int X = 1;
      int i = 0;

      if (palavra[0] == '-') {
          X = -1;
          i = 1;
      } else if (palavra[0] == '+') {
          i = 1;
      }

      for (; i < palavra.size(); ++i) {
          char c = palavra[i];
          if (c < '0' || c > '9') {
              return -1;
          }

          int digit = c - '0';

          if (X == 1 && (resultado > (INT_MAX - digit) / 10)) {
              return -1;
          }
          if (X == -1 && (resultado > (INT_MAX - digit) / 10 + 1)) {
              return -1;
          }

          resultado = resultado * 10 + digit;
      }

      return X * resultado;
  }

void exercicio1()
{
  string palavra;
  cout << "Digite uma string para realizar o teste de conversao: ";
  cin >> palavra;

  int resultado = getInt(palavra);

  if (resultado == -1)
  {
    cout << "A string nao pode ser convertida para um inteiro." << endl;
  }
  else
  {
    cout << "A string convertida para um inteiro eh: " << resultado << endl;
  }
}

double getDouble(string &palavra) {
    if (palavra.empty()) {
        return 0.0;
    }

    double resultado = 0.0;
    double parteFracionaria = 0.0;
    int X = 1;
    int i = 0;
    bool SeParteDecimal = false;
    double divisor = 10.0;


    if (palavra[0] == '-') {
        X = -1;
        i = 1;
    } else if (palavra[0] == '+') {
        i = 1;
    }

    for (; i < palavra.size(); ++i) {
        char c = palavra[i];
        if (c == '.') {
            if (SeParteDecimal) {
                return 0.0;
            }
            SeParteDecimal = true;
            continue;
        }

        if (c < '0' || c > '9') {
            return 0.0;
        }

        int digit = c - '0';

        if (!SeParteDecimal) {
            resultado = resultado * 10 + digit;
        } else {
            parteFracionaria += digit / divisor;
            divisor *= 10.0;
        }
    }

    return X * (resultado + parteFracionaria);
}

void exercicio2()
{
  string palavra;
  cout << "Digite uma string para realizar o teste de conversao: ";
  cin >> palavra;

  double resultado = getDouble(palavra);

  if (resultado == -1)
  {
    cout << "A string nao pode ser convertida para um double." << endl;
  }
  else
  {
    cout << "A string convertida para um double eh: " << resultado << endl;
  }
}

bool getBoolean(string &palavra) {
    if (palavra == "true" || palavra == "T" || palavra == "1") {
        return true;
    } else if (palavra == "false" || palavra == "F" || palavra == "0") {
        return false;
    } else {
        return false;
    }
}

void exercicio3()
{
  string palavra;
  cout << "Digite uma string para realizar o teste de conversao: ";
  cin >> palavra;

  bool resultado = getBoolean(palavra);

  if (resultado == false)
  {
    cout << "A string nao pode ser convertida para um Boolean." << endl;
  }
  else
  {
    cout << "A string convertida para um Boolean eh: " << resultado << endl;
  }
}

bool contains(string &conteudo, string &texto) {
    if (texto.empty()) {
        return true;
    }

    if (conteudo.empty()) {
        return false;
    }

    for (int i = 0; i <= conteudo.size() - texto.size(); ++i) {
        int j = 0;
        while (j < texto.size() && conteudo[i + j] == texto[j]) {
            ++j;
        }
        if (j == texto.size()) {
            return true;
        }
    }

    return false;
}

void exercicio4()
{
  string conteudo, texto;

  cout << "Digite o conteudo: ";
  cin >> conteudo;

  cout << "Digite o texto: ";
  cin >> texto;

  bool resultado = contains(conteudo, texto);

  if (resultado == false)
  {
    cout << "O texto nao esta contido no conteudo." << endl;
  }
  else
  {
    cout << "O texto esta contido no conteudo." << endl;
  }
}

string toUpperCase(string &texto) {
    string resultado = texto;

    for (int i = 0; i < resultado.size(); ++i) {
        if (resultado[i] >= 'a' && resultado[i] <= 'z') {
            resultado[i] = resultado[i] - ('a' - 'A');
        }
    }

    return resultado;
}

void exercicio5()
{
  string texto;

  cout << "Digite um texto: ";
  cin >> texto;

  string resultado = toUpperCase(texto);

  cout << "O texto convertido para maiusculo eh: " << resultado << endl;
}

string toLowerCase(string &texto) {
    string resultado = texto;

    for (int i = 0; i < resultado.size(); ++i) {
        if (resultado[i] >= 'A' && resultado[i] <= 'Z') {
            resultado[i] = resultado[i] + ('a' - 'A');
        }
    }

    return resultado;
}

void exercicio6()
{
  string texto;

  cout << "Digite um texto: ";
  cin >> texto;

  string resultado = toLowerCase(texto);

  cout << "O texto convertido para minusculo eh: " << resultado << endl;
}

string replace(string &texto, char original, char novo) {
    string resultado = texto;

    for (int i = 0; i < resultado.size(); ++i) {
        if (resultado[i] == original) {
            resultado[i] = novo;
        }
    }

    return resultado;
}

void exercicio7()
{
  string texto;
  char original;
  char novo;

  cout << "Digite um texto: ";
  cin >> texto;

  cout << "Digite o caractere original: ";
  cin >> original;

  cout << "Digite o caractere novo: ";
  cin >> novo;

  string resultado = replace(texto, original, novo);

  cout << "O texto convertido eh: " << resultado << endl;
}

string encrypt(string &texto, int chave) {
    string resultado = texto;

    for (int i = 0; i < resultado.size(); ++i) {
        char &caractere = resultado[i];

        if (caractere >= 'A' && caractere <= 'Z') {
            caractere = 'A' + (caractere - 'A' + chave) % 26;
        }

        else if (caractere >= 'a' && caractere <= 'z') {
            caractere = 'a' + (caractere - 'a' + chave) % 26;
        }
    }

    return resultado;
}

void exercicio8()
{
  string texto;
  int chave;

  cout << "Digite um texto: ";
  cin >> texto;

  cout << "Digite a chave de criptografia: ";
  cin >> chave;

  string resultado = encrypt(texto, chave);

  cout << "O texto criptografado eh: " << resultado << endl;
}

string decrypt(string &input, int chave) {
  return encrypt(input, -chave);
}

void exercicio9()
{
  string texto;
  int chave;

  cout << "Digite um texto: ";
  cin >> texto;

  cout << "Digite a chave de criptografia: ";
  cin >> chave;

  string resultado = decrypt(texto, chave);

  cout << "O texto descriptografado eh: " << resultado << endl;
}

int split(string sequencia[]) {
    string texto;
    getline(cin, texto);

    stringstream ss(texto);
    string caracteres;
    int indice = 0;

    while (ss >> caracteres) {
        sequencia[indice++] = caracteres;
    }

    return indice;
}

void exercicio10()
{
  string sequencia[100];

  cout << "Digite uma frase para separar em sequencias: ";

  int quantidade = split(sequencia);

  if (quantidade > 0) {
      cout << "Sequencias identificadas:" << endl;
      for (int i = 0; i < quantidade; ++i) {
          cout << sequencia[i] << endl;
      }
  } else {
      cout << "Nenhuma sequencia identificada." << endl;
  }
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
Digite uma string para realizar o teste de conversao: 123
A string convertida para um inteiro eh: 123

////////////////////////////////////////////////

Digite um exercicio: 2
Digite uma string para realizar o teste de conversao: 1.745
A string convertida para um double eh: 1.745

////////////////////////////////////////////////

Digite um exercicio: 3
Digite uma string para realizar o teste de conversao: T
A string convertida para um Boolean eh: 1

////////////////////////////////////////////////

Digite um exercicio: 4
Digite o conteudo: ola
Digite o texto: la
O texto esta contido no conteudo.

////////////////////////////////////////////////

Digite um exercicio: 5
Digite um texto: tudobem
O texto convertido para maiusculo eh: TUDOBEM

////////////////////////////////////////////////

Digite um exercicio: 6
Digite um texto: COMOVOCEESTA
O texto convertido para minusculo eh: comovoceesta

////////////////////////////////////////////////

Digite um exercicio: 7
Digite um texto: dente
Digite o caractere original: d
Digite o caractere novo: p
O texto convertido eh: pente

////////////////////////////////////////////////

Digite um exercicio: 8
Digite um texto: palavra
Digite a chave de criptografia: 5
O texto criptografado eh: ufqfawf

////////////////////////////////////////////////

Digite um exercicio: 9
Digite um texto: ufqfawf
Digite a chave de criptografia: 5
O texto descriptografado eh: palavra

////////////////////////////////////////////////

Digite um exercicio: 10
Digite uma frase para separar em sequencias: Nenhuma sequencia identificada.

////////////////////////////////////////////////
*/
