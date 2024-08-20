/*
AUTOR: Arthur Souza Carvalho
data: 24/05/2024
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

class Matriz
{
private:
    int linha;
    int coluna;
    int** valores;
public:

    Matriz()
    {
        this->linha = 0;
        this->coluna = 0;
        valores = nullptr;
    }

    Matriz ( int linha, int coluna)
    {
        this->linha = linha;
        this->coluna = coluna;

        valores = new int* [linha];

        for (int i =0; i < linha; i++)
        {
            valores[i] = new int [coluna];
        }
    }

    ~Matriz ()
    {
        if (valores != nullptr)
        {
            for (int i = 0; i < linha; i++)
            {
                delete (valores [i]);
            }
            delete (valores);
            valores = nullptr;
        }
    }


    void gerarValoresAleatorios(int min , int max)
    {
        if (valores == nullptr)
        {
            cout << "\nA Matriz nao existe" << endl;
        }
        else
        {
            for (int i = 0; i < linha; i++)
            {
                for (int j = 0; j < coluna; j++)
                {
                    valores[i][j] = rand () % (max - min) + min;
                }
            }
        }
    }

    void imprimirMatriz()
    {
        cout << endl;
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                cout << valores[i][j] << "  ";
            }
            cout << endl;
        }
    }

    Matriz scalar (int escala)
    {
        Matriz matrix (this->linha, this->coluna);

        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                matrix.valores[i][j] = valores[i][j] * escala;
            }
        }

        return matrix;
    }

    bool identidade()
    {
        if (linha == coluna)
        {
            for (int i = 0; i < linha; i++)
            {
                for (int j = 0; j < coluna; j++)
                {
                    if (valores[i][i] != 1)
                    {
                        return false;
                    }
                    if (i != j)
                    {
                        if (valores [i][j] != 0)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }

    bool operator==(const Matriz& outro) const
    {
        if (this->linha != outro.linha || this->coluna != outro.coluna)
        {
            return false;
        }
        for (int i = 0; i < this->linha; i++)
        {
            for (int j = 0; j < this->coluna; j++)
            {
                if (valores[i][j] != outro.valores[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    int add(Matriz matrix2)
    {
        int soma = 0;

        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                soma = soma + valores[i][j] + matrix2.valores[i][j];
            }
        }

        return soma;
    }

    void addLinhas (int PrimeiraL, int SegundaL, int escala)
    {
        for (int i = 0; i < coluna; i++)
        {
            valores[PrimeiraL][i] = (valores[PrimeiraL][i] + valores[SegundaL][i]) * escala;
        }
    }

    void subtraiLinhas (int PrimeiraL, int SegundaL, int escala)
    {
        for (int i = 0; i < coluna; i++)
        {
            valores[PrimeiraL][i] = (valores[PrimeiraL][i] - valores[SegundaL][i]) * escala;
        }
    }

    bool procurarLinha(int procurado)
    {
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                if (procurado == valores[i][j])
                {
                    cout << "\nO valor se encontra na linha [" << i << "]" << endl;
                    return true;
                }
            }
        }
        return false;
    }

    bool procurarColuna(int procurado)
    {
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                if (procurado == valores[i][j])
                {
                    cout << "\nO valor se encontra na coluna [" << j << "]" << endl;
                    return true;
                }
            }
        }
        return false;
    }

    void transpor() {
        // Criação de uma nova matriz transposta com dimensões trocadas
        int** valorestransposto = new int*[this->coluna];
        for (int i = 0; i < this->coluna; i++) {
            valorestransposto[i] = new int[this->linha];
            for (int j = 0; j < this->linha; j++) {
                valorestransposto[i][j] = this->valores[j][i];
            }
        }

        // Liberação da memória da matriz original
        for (int i = 0; i < this->linha; ++i) {
            delete[] this->valores[i];
        }
        delete[] this->valores;

        // Atualização da matriz original para ser a transposta
        this->valores = valorestransposto;

        // Troca do número de linhas e colunas
        std::swap(this->linha, this->coluna);

    }

    Matriz lerMatrizArquivo( string nome )
    {
        int n;
        ifstream arquivo;

        arquivo.open ( nome );

        arquivo >> n;
        arquivo >> this->linha;
        arquivo >> this->coluna;

        Matriz matrix (linha,coluna);

        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                arquivo >> valores[i][j];
            }
        }

        arquivo.close();

        return matrix;
    }

    void gravarMatrizArquivo( string nome )
    {
        ofstream arquivo;

        arquivo.open( nome );

        arquivo << linha*coluna << endl;

        arquivo << linha << endl;
        arquivo << coluna << endl;

        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                arquivo << valores[i][j] << endl;
            }
        }

        arquivo.close();
    }



};

void exercicio1()
{
    cout << "\nExercicio - 1" << endl;
    int n = 0, m = 0;

    cout << "\nDigite o valor de linhas da matriz: ";
    cin >> n;
    cout << "\nDigite o valor de colunas da matriz: ";
    cin >> m;

    Matriz matrix (n , m);

    matrix.gerarValoresAleatorios(1 , 100);

    matrix.gravarMatrizArquivo("DADOS1.txt");

    matrix.imprimirMatriz();

}

void exercicio2()
{
    cout << "\nExercicio - 2" << endl;
    int escala = 0;

    cout << "\nDigite a constante para escalar a matriz: ";
    cin >> escala;

    Matriz matrix = matrix.lerMatrizArquivo("DADOS1.txt");

    cout << "\nMatriz Padrao: ";

    matrix.imprimirMatriz();

    Matriz matrix2 = matrix.scalar(escala);

    cout << "\nMatriz Escalada: ";

    matrix2.imprimirMatriz();

}

void exercicio3()
{
    cout << "\nExercicio - 3" << endl;

    Matriz matrix = matrix.lerMatrizArquivo("DADOS1.txt");

    matrix.imprimirMatriz();

    if (matrix.identidade())
    {
        cout << "\nEssa Matriz E a identidade" << endl;
    }
    else
    {
        cout << "\nEssa Matriz NAO e a identidade" << endl;
    }
}

void exercicio4()
{
    cout << "\nExercicio - 4" << endl;

    Matriz matrix1 = matrix1.lerMatrizArquivo("DADOS1.txt");

    cout << "\nMatriz 1: ";
    matrix1.imprimirMatriz();

    Matriz matrix2 = matrix2.lerMatrizArquivo("DADOS2.txt");

    cout << "\nMatriz 2: ";
    matrix2.imprimirMatriz();

    bool teste = (matrix1 == matrix2);

    if (teste)
    {
        cout << "\nAs matrizes sao iguais" << endl;
    }
    else
    {
        cout << "\nAs matrizes sao diferentes" << endl;
    }
}

void exercicio5()
{
    cout << "\nExercicio - 5" << endl;

    Matriz matrix1 = matrix1.lerMatrizArquivo("DADOS1.txt");

    cout << "\nMatriz 1: ";
    matrix1.imprimirMatriz();

    Matriz matrix2 = matrix2.lerMatrizArquivo("DADOS2.txt");

    cout << "\nMatriz 2: ";
    matrix2.imprimirMatriz();

    int soma = matrix1.add(matrix2);

    cout << "\nEsse e o valor da soma das matrizes [" << soma << "]\n";

}

void exercicio6()
{
    cout << "\nExercicio - 6" << endl;

    Matriz matrix = matrix.lerMatrizArquivo("DADOS1.txt");

    cout << "\nMatriz Padrao:";
    matrix.imprimirMatriz();

    matrix.addLinhas(0 , 1 , (-1));

    cout << "\nMatriz Alterada:";
    matrix.imprimirMatriz();

}

void exercicio7()
{
    cout << "\nExercicio - 7" << endl;

    Matriz matrix = matrix.lerMatrizArquivo("DADOS1.txt");

    cout << "\nMatriz Padrao:";
    matrix.imprimirMatriz();

    matrix.subtraiLinhas(0 , 1 , (2));

    cout << "\nMatriz Alterada:";
    matrix.imprimirMatriz();
}

void exercicio8()
{
    cout << "\nExercicio - 8" << endl;
    int x = 0;

    Matriz matrix = matrix.lerMatrizArquivo("DADOS1.txt");
    matrix.imprimirMatriz();

    cout << "\nQual valor voce procura: ";
    cin >> x;

    if (matrix.procurarLinha(x))
    {
        cout << "\nO valor EXISTE" << endl;
    }
    else
    {
        cout << "\nO valor NAO existe" << endl;
    }

}

void exercicio9()
{
    cout << "\nExercicio - 9" << endl;

    int x = 0;

    Matriz matrix = matrix.lerMatrizArquivo("DADOS1.txt");
    matrix.imprimirMatriz();

    cout << "\nQual valor voce procura: ";
    cin >> x;

    if (matrix.procurarColuna(x))
    {
        cout << "\nO valor EXISTE" << endl;
    }
    else
    {
        cout << "\nO valor NAO existe" << endl;
    }
}

void exercicio10()
{
    cout << "\nExercicio - 10" << endl;

    Matriz matrix = matrix.lerMatrizArquivo("DADOS1.txt");
    matrix.imprimirMatriz();

    matrix.transpor();

    cout << "\nMatriz alterada:";
     matrix.imprimirMatriz();

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

Exercicio - 1

Digite o valor de linhas da matriz: 3

Digite o valor de colunas da matriz: 3

42  54  98
68  63  83
94  55  35

/////////////////////////////////////////////

Exercicio - 2

Digite a constante para escalar a matriz: 3

Matriz Padrao:
42  54  98
68  63  83
94  55  35

Matriz Escalada:
126  162  294
204  189  249
282  165  105

/////////////////////////////////////////////

Exercicio - 3

42  54  98
68  63  83
94  55  35

Essa Matriz NAO e a identidade

/////////////////////////////////////////////

Exercicio - 4

Matriz 1:
42  54  98
68  63  83
94  55  35

Matriz 2:
42  54  98
68  63  83
94  55  35

As matrizes sao iguais

/////////////////////////////////////////////

Exercicio - 5

Matriz 1:
42  54  98
68  63  83
94  55  35

Matriz 2:
42  54  98
68  63  83
94  55  35

Esse e o valor da soma das matrizes [1184]

/////////////////////////////////////////////

Exercicio - 6

Matriz Padrao:
42  54  98
68  63  83
94  55  35

Matriz Alterada:
-110  -117  -181
68  63  83
94  55  35

/////////////////////////////////////////////

Exercicio - 7

Matriz Padrao:
42  54  98
68  63  83
94  55  35

Matriz Alterada:
-52  -18  30
68  63  83
94  55  35

/////////////////////////////////////////////

Exercicio - 8

42  54  98
68  63  83
94  55  35

Qual valor voce procura: 83

O valor se encontra na linha [1]

O valor EXISTE

/////////////////////////////////////////////

Exercicio - 9

42  54  98
68  63  83
94  55  35

Qual valor voce procura: 35

O valor se encontra na coluna [2]

O valor EXISTE

/////////////////////////////////////////////

Exercicio - 10

42  54  98
68  63  83
94  55  35

Matriz alterada:
42  68  94
54  63  55
98  83  35

Digite um exercicio:

/////////////////////////////////////////////

*/
