/*
AUTOR: Arthur Souza Carvalho
data: 05/06/2024
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
#include <cctype>


class Contato
{
private:
    string nome;
    string fone;
    string segundofone;
    int quant;

    bool numeroValido(const string& fone)
    {
        for (char c : fone)
        {
            if (!isdigit(c) && c != '-')
            {
                return false;
            }
        }
        return true;
    }

public:

    Contato()
    {
        nome = "";
        fone = "";
        segundofone = "";
        quant = 0;
    }

    Contato(string nome, string fone)
    {
        this->nome = nome;
        this->fone = fone;
        quant = 1;
    }

    Contato(string nome, string fone, string segundofone)
    {
        this->nome = nome;
        this->fone = fone;
        this->segundofone = segundofone;
        quant = 2;
    }

    void setFone(string fone)
    {
        if (numeroValido(fone))
        {
            this->fone = fone;
        }
        else
        {
            cout << "Telefone invalido inserido" << endl;
        }
    }
    string getFone() { return fone; }

    void setNome(string nome)
    {
        this->nome = nome;
    }
    string getNome() { return nome; }

    void setFone2 (string fone)
    {
        if (numeroValido(fone))
        {
            this->segundofone = fone;
        }
        else
        {
            cout << "Telefone invalido inserido" << endl;
        }
    }

    bool existeFone()
    {
        if ( fone == "" && segundofone == "")
        {
            return false;
        }
        return true;
    }

    void setFone2b (string fone)
    {
        if (this->fone != "")
        {
            if (numeroValido(fone))
            {
                this->segundofone = fone;
            }
            else
            {
                cout << "Telefone invalido inserido" << endl;
            }
        }
        else
        {
            cout << "O primeiro Telefone nao existe" << endl;
        }
    }

    bool perguntarFone2()
    {
        int x = 0;
        if (segundofone == "")
        {
            cout << "Deseja adicionar um segundo telefone? se sim digite (1) se nao digite (0): ";
            cin >> x;
            cout << endl;
        }
        if (x)
        {
            return true;
        }
        return false;
    }

    void excluirFone2(string fone)
    {
        if (quant != 0)
        {
            segundofone = fone;
        }
        else
        {
            cout << endl << "Erro existe apenas um telefone para esse contato" << endl;
        }
    }

    void contarFones()
    {
        if (fone != "")
        {
            quant++;
        }

        if (segundofone != "")
        {
            quant++;
        }
    }

    int fones() { return quant; }

    void imprimirContato()
    {
        cout << "Nome: " << nome << endl;
        cout << "Fone: " << fone << endl;
        cout << "Segundo Fone: " << segundofone << endl;
    }

    bool validarFone()
    {
        return numeroValido(fone);
    }

    void lerDoArquivo (string nomearquivo)
    {
        ifstream arquivo;

        arquivo.open(nomearquivo);

        getline (arquivo, nome);
        getline (arquivo, fone);

        arquivo.close();
    }

    void gravarNoArquivo (string nomearquivo)
    {
        ofstream arquivo;

        arquivo.open(nomearquivo);

        int x = nome.size();
        int y = fone.size();

        arquivo << x << endl;
        arquivo << y << endl;

        arquivo << nome << endl;
        arquivo << fone << endl;

        arquivo.close();
    }

};

void exercicio1()
{
    cout << "\nExercicio - 1" << endl;

    Contato contato1;

    contato1.setNome("Arthur Souza Carvalho");

    contato1.imprimirContato();

}

void exercicio2()
{
    cout << "\nExercicio - 2" << endl;

    Contato contato1;

    contato1.setNome("Arthur Souza Carvalho");
    contato1.setFone("99471-2541");

    contato1.imprimirContato();
}

void exercicio3()
{
    cout << "\nExercicio - 3" << endl;

    Contato contato1;

    contato1.setNome("Arthur Souza Carvalho");
    contato1.setFone("99471-2541");

    contato1.imprimirContato();

    cout << endl << "Telefone valido: " << (contato1.validarFone() ? "Sim" : "Nao" ) << endl;

}

void exercicio4()
{
    cout << "\nExercicio - 4" << endl;

    Contato contato1;

    contato1.lerDoArquivo("Pessoa1.txt");

    contato1.imprimirContato();
}

void exercicio5()
{
    cout << "\nExercicio - 5" << endl;

    Contato contato1("Gabriel Chaves Mendes", "99530-6209");

    contato1.gravarNoArquivo("Pessoa.txt");

    contato1.imprimirContato();
}

void exercicio6()
{
    cout << "\nExercicio - 6" << endl;

    Contato contato1;

    contato1.lerDoArquivo("Pessoa1.txt");

    contato1.imprimirContato();

    cout << endl << "Adicionando mais um telefone" << endl;

    contato1 = Contato ("Arthur Souza", "99530-6209", "99303-8741");

    contato1.imprimirContato();

}

void exercicio7()
{
    cout << "\nExercicio - 7" << endl;

    Contato contato1;

    contato1.lerDoArquivo("Pessoa1.txt");

    contato1.contarFones();
    int n = contato1.fones();

    contato1.imprimirContato();

    cout << "Esse Contato tem " << n << " Telefones" << endl;
}

void exercicio8()
{
    cout << "\nExercicio - 8" << endl;
    string fone;

    Contato contato1;

    contato1.lerDoArquivo("Pessoa1.txt");

    contato1.imprimirContato();
    cout << endl;



    if (contato1.perguntarFone2())
    {
        cout << "Digite um telefone: ";
        cin >> fone;
        contato1.setFone2(fone);
    }

    contato1.imprimirContato();

}

void exercicio9()
{
    cout << "\nExercicio - 9" << endl;
    string fone;

    Contato contato1;

    contato1.lerDoArquivo("Pessoa1.txt");
    contato1.imprimirContato();
    cout << endl;

    contato1 = Contato ("Arthur Souza Carvalho", "99530-6209", "99303-8741");

    contato1.imprimirContato();
    cout << endl;

    cout << "Digite um telefone: ";
    cin >> fone;
    contato1.setFone2b(fone);

    contato1.imprimirContato();

}

void exercicio10()
{
    cout << "\nExercicio - 10" << endl;

    Contato contato1;

    contato1.lerDoArquivo("Pessoa1.txt");
    contato1.imprimirContato();
    cout << endl;

    contato1.excluirFone2("");

    contato1 = Contato ("Arthur Souza Carvalho", "99530-6209", "99303-8741");
    contato1.imprimirContato();
    cout << endl;

    contato1.excluirFone2("");

    contato1.imprimirContato();
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

///////////////////////////////////////////////

Exercicio - 1
Nome: Arthur Souza Carvalho
Fone:

///////////////////////////////////////////////

Exercicio - 2
Nome: Arthur Souza Carvalho
Fone: 31 99471-2541

///////////////////////////////////////////////

Exercicio - 3
Nome: Arthur Souza Carvalho
Fone: 99471-2541

Telefone valido: Sim

///////////////////////////////////////////////

Exercicio - 4
Nome: Arthur Souza Carvalho
Fone: 99471-2541

///////////////////////////////////////////////

Exercicio - 5
Nome: Gabriel Chaves Mendes
Fone: 99530-6209

///////////////////////////////////////////////

Exercicio - 6
Nome: Arthur Souza Carvalho
Fone: 99471-2541
Segundo Fone:

Adicionando mais um telefone   //Alterei o nome de prosito
Nome: Arthur Souza
Fone: 99530-6209
Segundo Fone: 99303-8741

///////////////////////////////////////////////

Exercicio - 7
Nome: Arthur Souza Carvalho
Fone: 99471-2541
Segundo Fone:
Esse Contato tem 1 Telefones

///////////////////////////////////////////////

Exercicio - 8
Nome: Arthur Souza Carvalho
Fone: 99471-2541
Segundo Fone:

Deseja adicionar um segundo telefone? se sim digite (1) se nao digite (0): 1

Digite um telefone: 99740-6209
Nome: Arthur Souza Carvalho
Fone: 99471-2541
Segundo Fone: 99740-6209

///////////////////////////////////////////////

Exercicio - 9
Nome: Arthur Souza Carvalho
Fone: 99471-2541
Segundo Fone:

Nome: Arthur Souza Carvalho
Fone: 99530-6209
Segundo Fone: 99303-8741

Digite um telefone: 99471-2541

Nome: Arthur Souza Carvalho
Fone: 99530-6209
Segundo Fone: 99471-2541

///////////////////////////////////////////////

Digite um exercicio: 10

Exercicio - 10
Nome: Arthur Souza Carvalho
Fone: 99471-2541
Segundo Fone:


Erro existe apenas um telefone para esse contato
Nome: Arthur Souza Carvalho
Fone: 99530-6209
Segundo Fone: 99303-8741

Nome: Arthur Souza Carvalho
Fone: 99530-6209
Segundo Fone:

///////////////////////////////////////////////

*/
