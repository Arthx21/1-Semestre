/*
AUTOR: Arthur Souza Carvalho
data: 18/05/2024
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

#include <cstdlib>
#include <ctime>


template < typename tipo >

class arranjo
{
private:
    int tamanho;
    tipo *valores;
public:

    arranjo() : tamanho(0), valores(nullptr) {}

    arranjo(int tamanho) : tamanho(tamanho), valores(new tipo[tamanho]) {}

    ~arranjo() {
        delete[] valores;
    }

   void setTamanho( int tamanho ) { this->tamanho = tamanho; }
   int getTamanho () { return tamanho; }

   void arraynew()
   {
       int n = 0;
       cout << "Digite um tamanho para o seu array: ";
       cin >> n;
       if ( n <= 0 )
       {
           cout << "\nERROR: Tamanho invalido.\n" << endl;
       }
       else
       {
          delete[] valores;
          tamanho = n;
          valores = new tipo [n];
       }
   }

   void imprimirArray()
   {
       if ( tamanho <= 0)
       {
            cout << "\nNAO existe um array" << endl;
       }
       else
       {
            for (int i = 0; i < tamanho; i++)
            {
                cout << "[" << valores[i] << "] ";
            }
       }
   }

   void arrayValores()
   {
       if ( tamanho <= 0)
       {
           cout << "\nNAO existe um array" << endl;
       }
       else
       {
           cout << "Digite os valores do array de tamanho [%d]: " << tamanho;
           for ( int i = 0 ; i < tamanho ; i++)
           {
               cin >> valores[i];
           }
       }
   }

   void gerarValoresAleatorios(int min , int max)
   {
       valores = new tipo [tamanho];
       for (int i = 0 ; i < tamanho ; i++)
       {
           valores[i] = rand () % (max - min) + min;
       }
   }

   int maiorValorArray()
   {
       int maior = 0;
       maior = valores[0];
       for ( int i = 1 ; i < tamanho ; i++)
       {
           if (valores[i] > maior)
           {
               maior = valores[i];
           }
       }
       return maior;
   }

   int menorValorImparArray()
   {
       int menor = 0;
       menor = valores[0];
       for (int i = 0; i < tamanho; i++)
       {
           if (valores[i] % 2 != 0)
           {
               if (valores[i] < menor)
               {
                   menor = valores[i];
               }
           }
       }
       return menor;
   }

   int somarArray(int p1, int p2 )
   {
       int soma = 0;
       for (int i = p1; i < p2 + 1 ; i++)
       {
           soma = soma + valores[i];
       }
       return soma;
   }

    double mediaArray (int p1, int p2)
    {
        double aux = 0;
        double soma = 0;

        for (int i = p1; i < p2 + 1; i++)
        {
            soma = soma + valores[i];
            aux++;
        }

        return soma / aux;
    }

    bool negativos()
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (valores[i] != 0)
            {
                return true;
            }
        }
        return false;
    }

    bool eCrescente()
    {

        for (int i = 0; i < tamanho - 1; i++)
        {
            if (valores[i] > valores[i+1])
            {
                return false;
            }
        }
        return true;
    }

    bool eDescrecente()
    {
        for (int i = 0; i < tamanho - 1; i++)
        {
            if (valores[i] < valores[i+1])
            {
                return false;
            }
        }
        return true;
    }

    bool valorProcurado(int procurado, int p1, int p2)
    {
        for (int i = p1; i < p2 + 1; i++)
        {
            if (valores[i] == procurado)
            {
                return true;
            }
        }
        return false;
    }

    arranjo<tipo> escalar(tipo constante, int inicio, int fim) const {
        if (inicio < 0 || fim >= tamanho || inicio > fim) {
            cout << "\nERROR: Indices invalidos.\n" << endl;
            return *this;
        }

        int novotamanho = fim - inicio + 1;
        arranjo<tipo> novoArranjo(novotamanho);
        for (int i = inicio; i <= fim; i++) {
            novoArranjo.valores[i - inicio] = valores[i] * constante;
        }
        return novoArranjo;
    }

    void arrayDescrecente()
    {
        int aux = 0;
        while (!eDescrecente())
        {
            for (int i = 0; i < tamanho; i++)
            {
                if (valores[i] < valores[i + 1])
                {
                    aux = valores[i];
                    valores[i] = valores[i + 1];
                    valores[i + 1] = aux;
                }
            }
        }
    }

   void lerArrayArquivo ( string nomearquivo )
   {
       int x = 0;
       ifstream arquivo;
       arquivo.open (nomearquivo);
       arquivo >> x;
       if (x <= 0)
       {
           cout << "\nERROR: Tamanho invalido.\n" << endl;
       }
       else
       {
            tamanho = x;
            delete[] valores;
            valores = new tipo [tamanho];
            for ( int i = 0 ; i < tamanho; i++)
            {
                arquivo >> valores[i];
            }
       }
       arquivo.close();
   }

   void gravarArrayArquivo( string nomearquivo )
   {
       ofstream arquivo;
       arquivo.open (nomearquivo);
       arquivo << tamanho << endl;
       for ( int i = 0; i < tamanho; i++)
       {
           arquivo << valores[i] << endl;
       }
       arquivo.close();
   }

};

void exercicio1()
{
    cout << "\nExercicio [1]" << endl << endl;

    arranjo <int> array;

    array.arraynew();

    array.gerarValoresAleatorios( 0 , 100 );

    array.gravarArrayArquivo("DADOS1.txt");

    array.imprimirArray();

    cout << endl;
}

void exercicio2()
{
    cout << "\nExercicio [2]" << endl << endl;

    arranjo <int> array;

    array.lerArrayArquivo("DADOS1.txt");

    array.imprimirArray();

    int maior = array.maiorValorArray();

    cout << "\nO maior valor dentro do array e : [" << maior << "]" << endl;

}

void exercicio3()
{
    cout << "\nExercicio [3]" << endl << endl;

    arranjo <int> array;

    array.lerArrayArquivo("DADOS1.txt");

    array.imprimirArray();

    int menor = array.menorValorImparArray();

    cout << "\nO Menor valor impar dentro do array: [" << menor << "]" << endl;
}

void exercicio4()
{
    cout << "\nExercicio [4]" << endl << endl;
    int p1 = 0, p2 = 0;

    arranjo <int> array;

    array.lerArrayArquivo("DADOS1.txt");

    array.imprimirArray();

    int tamanho = array.getTamanho();

    cout << "\nDigite o indice de inicio: ";
    cin >> p1;
    cout << "\nDigite o indice de fim: ";
    cin >> p2;

    int soma = array.somarArray(p1 , p2);

    cout << "\nA Soma dos valores do array: [" << soma << "]" << endl;
}

void exercicio5()
{
    cout << "\nExercicio [5]" << endl << endl;
    int p1 = 0, p2 = 0;

    arranjo <int> array;

    array.lerArrayArquivo("DADOS1.txt");

    array.imprimirArray();

    int tamanho = array.getTamanho();

    cout << "\nDigite o indice de inicio: ";
    cin >> p1;
    cout << "\nDigite o indice de fim: ";
    cin >> p2;

    double media = array.mediaArray(p1, p2);

    cout << "\nA media dos valores do array: [" << media << "]" << endl;
}

void exercicio6()
{
    cout << "\nExercicio [6]" << endl << endl;

    arranjo <int> array;

    array.lerArrayArquivo("DADOS1.txt");

    array.imprimirArray();

    if (array.negativos())
    {
        cout << "\nNEM TODOS OS VALORES DO ARRAY SAO 0" << endl;
    }
    else
    {
        cout << "\nTODOS OS VALORES DO ARRAY SAO 0" << endl;
    }
}

void exercicio7()
{
    cout << "\nExercicio [7]" << endl << endl;

    arranjo <int> array;

    array.lerArrayArquivo("DADOS1.txt");

    array.imprimirArray();

    if(array.eCrescente())
    {
        cout << "\nO Array esta em ordem crescente!" << endl;
    }
    else
    {
        cout << "\nO Array nao esta em ordem crescente!" << endl;
    }
}

void exercicio8()
{
    cout << "\nExercicio [8]" << endl << endl;
    int p1 = 0, p2 = 0, procurado = 0;

    arranjo <int> array;

    array.lerArrayArquivo("DADOS1.txt");

    array.imprimirArray();

    int tamanho = array.getTamanho();

    cout << "\nDigite o indice de inicio: ";
    cin >> p1;
    cout << "\nDigite o indice de fim: ";
    cin >> p2;

    cout << "\nDigite o valor no qual procurado dentro do intervalo das posicoes " << p1 << " e " << p2 << " :";
    cin >> procurado;

    if (array.valorProcurado(procurado, p1 , p2))
    {
        cout << "\nO valor procurado [" << procurado << "]" << " existe!" << endl;
    }
    else
    {
        cout << "\nO valor procurado [" << procurado << "]" << " NAO existe!" << endl;
    }
}

void exercicio9()
{
    cout << "\nExercicio [9]" << endl << endl;
    int constante = 0, p1 = 0, p2 = 0;
    arranjo <int> array;

    array.lerArrayArquivo("DADOS1.txt");

    array.imprimirArray();

    cout << "\nDigite a constante para escalar: ";
    cin >> constante;

    cout << "\nDigite o indice de inicio: ";
    cin >> p1;
    cout << "\nDigite o indice de fim: ";
    cin >> p2;


    arranjo <int> Novoarray = array.escalar(constante, p1 , p2);

    cout << "\nUm novo array escalado:" << endl;
    Novoarray.imprimirArray();
    cout << endl;

}

void exercicio10()
{
    cout << "\nExercicio [10]" << endl << endl;

    arranjo <int> array;

    array.lerArrayArquivo("DADOS1.txt");

    array.imprimirArray();

    array.arrayDescrecente();

    cout << "\n\nO array organizado em forma descrecente: " << endl << endl;

    array.imprimirArray();

    cout << endl;

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

/* Resultados dos testes abaixo:


/////////////////////////////////////////////

Exercicio [1]

Digite um tamanho para o seu array: 20
[41] [67] [34] [0] [69] [24] [78] [58] [62] [64] [5] [45] [81] [27] [61] [91] [95] [42] [27] [36]

/////////////////////////////////////////////

Exercicio [2]

[41] [67] [34] [0] [69] [24] [78] [58] [62] [64] [5] [45] [81] [27] [61] [91] [95] [42] [27] [36]
O maior valor dentro do array e : [95]

/////////////////////////////////////////////

Exercicio [3]

[41] [67] [34] [0] [69] [24] [78] [58] [62] [64] [5] [45] [81] [27] [61] [91] [95] [42] [27] [36]
O Menor valor impar dentro do array: [5]

/////////////////////////////////////////////

Exercicio [4]

[41] [67] [34] [0] [69] [24] [78] [58] [62] [64] [5] [45] [81] [27] [61] [91] [95] [42] [27] [36]
Digite o indice de inicio: 2

Digite o indice de fim: 12

A Soma dos valores do array: [520]

/////////////////////////////////////////////

Exercicio [5]

[41] [67] [34] [0] [69] [24] [78] [58] [62] [64] [5] [45] [81] [27] [61] [91] [95] [42] [27] [36]
Digite o indice de inicio: 1

Digite o indice de fim: 12

A media dos valores do array: [48.9167]

/////////////////////////////////////////////

Exercicio [6]

[41] [67] [34] [0] [69] [24] [78] [58] [62] [64] [5] [45] [81] [27] [61] [91] [95] [42] [27] [36]
NEM TODOS OS VALORES DO ARRAY SAO 0

/////////////////////////////////////////////

Exercicio [7]

[41] [67] [34] [0] [69] [24] [78] [58] [62] [64] [5] [45] [81] [27] [61] [91] [95] [42] [27] [36]
O Array nao esta em ordem crescente!

/////////////////////////////////////////////

Exercicio [8]

[41] [67] [34] [0] [69] [24] [78] [58] [62] [64] [5] [45] [81] [27] [61] [91] [95] [42] [27] [36]
Digite o indice de inicio: 1

Digite o indice de fim: 12

Digite o valor no qual procurado dentro do intervalo das posicoes 1 e 12 :62

O valor procurado [62] existe!

/////////////////////////////////////////////

Exercicio [9]

[41] [67] [34] [0] [69] [24] [78] [58] [62] [64] [5] [45] [81] [27] [61] [91] [95] [42] [27] [36]
Digite a constante para escalar: 2

Digite o indice de inicio: 1

Digite o indice de fim: 9

Um novo array escalado:
[134] [68] [0] [138] [48] [156] [116] [124] [128]

/////////////////////////////////////////////

Exercicio [10]

[41] [67] [34] [0] [69] [24] [78] [58] [62] [64] [5] [45] [81] [27] [61] [91] [95] [42] [27] [36]

O array organizado em forma descrecente:

[95] [91] [81] [78] [69] [67] [64] [62] [61] [58] [45] [42] [41] [36] [34] [27] [27] [24] [5] [0]

/////////////////////////////////////////////

*/
