#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Passagem {
  int id;
  char origem[4];
  char destino[4];
  char cidadeOrigem[30];
  char cidadeDestino[30];
  char data[11];
  char horaPartida[10];
  char horaChegada[10];
  float valor;
}passagem;


FILE *arquivo;

//Funções
void menuPassagens();
void listarPassagens();
void pesquisarPassagem();
     void pesquisaID();
     void pesquisaCodigoorigem();
     void pesquisaCodigodestino();
     void pesquisaCidadeorigem();
     void pesquisaCidadedestino();
void cadastrarPassagem();
void editarPassagem();
     void Editar(passagem*, int, int);
     void EditarPorID(passagem*, int, int);
void excluirPassagem(int);
void arrayPassagem(passagem*);


//Validações
void upperCase(char*);
int validaArquivo();
int validarCodigo(char*);
int validarCidade(char*);
int validarData(char*);
int validarHora(char*);
int validarValor(float, int);
int validarOpcao(int);


//Declaradas para todas as funções
int quantID;
int ultimoID;
int leitura;

int main () {
// Faz a atualização dos dados sempre quando volta ao menu
arquivo = fopen ("passagens.txt", "r");
fscanf (arquivo,"%d", &quantID);
fscanf (arquivo,"%d", &ultimoID);
fclose (arquivo);

 //Chama o menu de passagens
 menuPassagens();

}

////////////////////////////////////////////////////////////////////////////////
                             //Funções//
////////////////////////////////////////////////////////////////////////////////
void menuPassagens() {
  int valida;
  int opcao=0;
  int ENCERRA=1;

  while (ENCERRA==1) {
  //Menu.
  printf ("/////////////////////////////////////////////\n");
  printf ("\t1 - Listar todas as passagens\n\t2 - Pesquisar uma passagem\n\t3 - Cadastrar uma passagem\n\t4 - Editar uma passagem\n\t5 - Excluir uma passagem\n\t6 - Sair do programa\n");
  printf ("/////////////////////////////////////////////\n");

  do {
  printf ("\nDigite a opcao desejada: ");
  leitura = scanf ("%d", &opcao);
  while (getchar()!='\n');
  } while (!validarOpcao(leitura));

  switch (opcao) {     //Um switch case para escolher uma das opções do menu.
    case 1:
     valida = validaArquivo();
     if (valida==1) {
      listarPassagens();  //Lista todas passagens e exibe no console.
     }
    break;
    case 2:
     valida = validaArquivo();
     if (valida==1) {
       pesquisarPassagem();  //Abre um outro pequeno menu com as opções de pesquisa.
     }
    break;
    case 3:
      //A validação de arquivo ocorre dentro da função.
      cadastrarPassagem(); //Cadastra uma nova passagem e escreve no arquivo.
    break;
    case 4:
      valida = validaArquivo();
     if (valida==1) {
       editarPassagem();  //Pergunta qual id de passagem deseja editar.
     }
    break;
    case 5:
      valida = validaArquivo();
     if (valida==1) {
       excluirPassagem(quantID);  //Pergunta qual id de passagem deseja excluir.
     }
    break;
    case 6:     //Finaliza o programa com a mensagem abaixo.
       printf ("\n\n\tMuito obrigado por utilizar o meu programa!\n\n");
       ENCERRA=-1;
    break;
    default:
    printf ("\nOpcao invalida!\n\n");
   }
  }
 }

////////////////////////////////////////////////////////////////////////////////
void listarPassagens() {
passagem lista[quantID];
printf ("\n\tAqui esta todas as passagens cadastradas\n\n");

    arrayPassagem(lista);  //Função onde se faz um array de passagens para serem manipuladas

for (int i=0;i<quantID;i++) { //Visualização das passagens
    printf ("Id: %d\n\n", lista[i].id);
    printf ("Codigo Origem: %s\n", lista[i].origem);
    printf ("Codigo Destino: %s\n", lista[i].destino);
    printf ("Cidade Origem: %s\n", lista[i].cidadeOrigem);
    printf ("Cidade Destino: %s\n", lista[i].cidadeDestino);
    printf ("Data: %s\n", lista[i].data);
    printf ("Hora de partida: %s\n", lista[i].horaPartida);
    printf ("Hora de chegada: %s\n", lista[i].horaChegada);
    printf ("Valor: R$%.2f\n\n", lista[i].valor);
    }
}

////////////////////////////////////////////////////////////////////////////////
void pesquisarPassagem() {
int opcao;

printf ("\n///////////////////////////////////////////\n");
printf ("\t1 - ID\n\t2 - Codigo Origem\n\t3 - Codigo Destino\n\t4 - Cidade Origem\n\t5 - Cidade Destino\n\t6 - Voltar ao Menu\n");
printf ("///////////////////////////////////////////\n");

do {
 printf ("\nQual a forma de pesquisa que deseja? ");
 leitura = scanf ("%d", &opcao);
 while (getchar()!='\n');
 } while (!validarOpcao(leitura));

switch (opcao) {
   case 1:
     pesquisaID();   // pesquisa por id
   break;
   case 2:
     pesquisaCodigoorigem();    // pesquisa por codigo de origem
   break;
   case 3:
     pesquisaCodigodestino();   // pesquisa por codigo de destino
   break;
   case 4:
     pesquisaCidadeorigem();    // pesquisa por cidade de origem
   break;
   case 5:
     pesquisaCidadedestino();   // pesquisa por cidade de destino
   break;
   case 6:
       printf ("\n");
     main(); //volta para main
   break;
   default:
      printf ("\nOpcao invalida!\n");
      pesquisarPassagem();  // qualquer numero invalido vai cair nesse menu novamente
   }
}

////////////////////////////////////////////////////////////////////////////////
void pesquisaID() {
int idpesquisa;
passagem passID[quantID];

do {
    printf("\nDigite um ID para efetuar a pesquisa na qual deseja editar: ");
    int leitura = scanf("%d", &idpesquisa);
    while (getchar()!='\n');
    int indice=0;     //reinicia a variavel (processo de validação para nn "quebrar")
    if (leitura!=1) {
        printf("\nID invalido, digite novamente!\n");
        indice=1;
    }
    if (indice!=1) {
        if (idpesquisa<=0 || idpesquisa>quantID) {
            printf ("\nPassagem nao encontrada!\n\n");
            main(); // volta para o menu
        }
    }
} while (idpesquisa<=0 || idpesquisa>quantID);

arrayPassagem(passID); //Função onde se faz um array de passagens para serem manipuladas

for (int i=0;i<quantID;i++) { //Visualização da passagem
    if (idpesquisa==passID[i].id) { //comparação para encontrar a passagem
        printf ("\nId: %d\n\n", passID[i].id);
        printf ("Codigo Origem: %s\n", passID[i].origem);
        printf ("Codigo Destino: %s\n", passID[i].destino);
        printf ("Cidade Origem: %s\n", passID[i].cidadeOrigem);
        printf ("Cidade Destino: %s\n", passID[i].cidadeDestino);
        printf ("Data: %s\n", passID[i].data);
        printf ("Hora de partida: %s\n", passID[i].horaPartida);
        printf ("Hora de chegada: %s\n", passID[i].horaChegada);
        printf ("Valor: R$%.2f\n\n", passID[i].valor);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
void pesquisaCodigoorigem() {
int resultado;
int auxresultado=0;
char origempesquisa[4];
passagem passCod[quantID];

arrayPassagem(passCod);  //Função onde se faz um array de passagens para serem manipuladas

do {
    printf ("\nDigite o codigo de origem do aeroporto: ");
    scanf (" %[^\n]", origempesquisa);
} while (!validarCodigo(origempesquisa));

upperCase(origempesquisa);  //Função que transforma em MAISCULO para comparação de string

for (int i=0;i<quantID;i++) { //Visualização da passagem
    resultado = strcmp(origempesquisa,passCod[i].origem); // comparação para encontrar a passagem
    if (resultado==0) {
        printf ("\nId: %d\n\n", passCod[i].id);
        printf ("Codigo Origem: %s\n", passCod[i].origem);
        printf ("Codigo Destino: %s\n", passCod[i].destino);
        printf ("Cidade Origem: %s\n", passCod[i].cidadeOrigem);
        printf ("Cidade Destino: %s\n", passCod[i].cidadeDestino);
        printf ("Data: %s\n", passCod[i].data);
        printf ("Hora de partida: %s\n", passCod[i].horaPartida);
        printf ("Hora de chegada: %s\n", passCod[i].horaChegada);
        printf ("Valor: R$%.2f\n\n", passCod[i].valor);
        auxresultado=1;
    }
}
  if (auxresultado!=1) {
    printf ("\nCodigo nao encontrado!\n");
    pesquisarPassagem();  //volta ao menu de pesquisa
    }
}

////////////////////////////////////////////////////////////////////////////////
void pesquisaCodigodestino() {
int resultado;
int auxresultado=0;
char destinopesquisa[4];
passagem passCod[quantID];

arrayPassagem(passCod);  //Função onde se faz um array de passagens para serem manipuladas

do {
    printf ("\nDigite o codigo de destino do aeroporto: ");
    scanf (" %[^\n]", destinopesquisa);
} while (!validarCodigo(destinopesquisa));

upperCase(destinopesquisa);  //Função que transforma em MAISCULO para comparação de string

for (int i=0;i<quantID;i++) { //Visualização da passagem
    resultado = strcmp(destinopesquisa,passCod[i].destino); //comparação para encontrar a passagem
    if (resultado==0) {
        printf ("\nId: %d\n\n", passCod[i].id);
        printf ("Codigo Origem: %s\n", passCod[i].origem);
        printf ("Codigo Destino: %s\n", passCod[i].destino);
        printf ("Cidade Origem: %s\n", passCod[i].cidadeOrigem);
        printf ("Cidade Destino: %s\n", passCod[i].cidadeDestino);
        printf ("Data: %s\n", passCod[i].data);
        printf ("Hora de partida: %s\n", passCod[i].horaPartida);
        printf ("Hora de chegada: %s\n", passCod[i].horaChegada);
        printf ("Valor: R$%.2f\n\n", passCod[i].valor);
        auxresultado=1;
    }
}
  if (auxresultado!=1) {
    printf ("\nCodigo nao encontrado!\n");
    pesquisarPassagem();  //volta ao menu de pesquisa
    }
}

////////////////////////////////////////////////////////////////////////////////
void pesquisaCidadeorigem() {
int resultado;
int auxresultado=0;
char cidadepesquisa[30];
passagem passCidade[quantID];

arrayPassagem(passCidade);  //Função onde se faz um array de passagens para serem manipuladas

do {
    printf ("\nDigite a cidade de origem: ");
    scanf (" %[^\n]", cidadepesquisa);
} while (!validarCidade(cidadepesquisa));

upperCase(cidadepesquisa); //Função que transforma em MAISCULO para comparação de string

for (int i=0;i<quantID;i++) { //Visualização da passagem
    resultado = strcmp(cidadepesquisa,passCidade[i].cidadeOrigem); //comparação para encontrar a passagem
    if (resultado==0) {
        printf ("\nId: %d\n\n", passCidade[i].id);
        printf ("Codigo Origem: %s\n", passCidade[i].origem);
        printf ("Codigo Destino: %s\n", passCidade[i].destino);
        printf ("Cidade Origem: %s\n", passCidade[i].cidadeOrigem);
        printf ("Cidade Destino: %s\n", passCidade[i].cidadeDestino);
        printf ("Data: %s\n", passCidade[i].data);
        printf ("Hora de partida: %s\n", passCidade[i].horaPartida);
        printf ("Hora de chegada: %s\n", passCidade[i].horaChegada);
        printf ("Valor: R$%.2f\n\n", passCidade[i].valor);
        auxresultado=1;
    }
}
  if (auxresultado!=1) {
    printf ("\nCidade nao encontrada!\n");
    pesquisarPassagem();  //volta ao menu de pesquisa
    }
}

////////////////////////////////////////////////////////////////////////////////
void pesquisaCidadedestino() {
int resultado;
int auxresultado=0;
char cidadepesquisa[30];
passagem passCidade[quantID];

arrayPassagem(passCidade);  //Função onde se faz um array de passagens para serem manipuladas

do {
    printf ("\nDigite a cidade de destino: ");
    scanf (" %[^\n]", cidadepesquisa);
} while (!validarCidade(cidadepesquisa));

upperCase(cidadepesquisa); //Função que transforma em MAISCULO para comparação de string

for (int i=0;i<quantID;i++) { //Visualização da passagem
    resultado = strcmp(cidadepesquisa,passCidade[i].cidadeDestino); //comparação para encontrar a passagem
    if (resultado==0) {
        printf ("\nId: %d\n\n", passCidade[i].id);
        printf ("Codigo Origem: %s\n", passCidade[i].origem);
        printf ("Codigo Destino: %s\n", passCidade[i].destino);
        printf ("Cidade Origem: %s\n", passCidade[i].cidadeOrigem);
        printf ("Cidade Destino: %s\n", passCidade[i].cidadeDestino);
        printf ("Data: %s\n", passCidade[i].data);
        printf ("Hora de partida: %s\n", passCidade[i].horaPartida);
        printf ("Hora de chegada: %s\n", passCidade[i].horaChegada);
        printf ("Valor: R$%.2f\n\n", passCidade[i].valor);
        auxresultado=1;
    }
}
  if (auxresultado!=1) {
    printf ("\nCidade nao encontrada!\n");
    pesquisarPassagem();  //volta ao menu de pesquisa
    }
}

////////////////////////////////////////////////////////////////////////////////
void cadastrarPassagem() {
  passagem p;

  do {
  printf ("\nDigite o codigo de origem do aeroporto: ");
  scanf ("%s", p.origem);
  } while (!validarCodigo(p.origem));  //função que Valida o codigo

  do {
  printf ("\nDigite o codigo de destino do aeroporto: ");
  scanf ("%s", p.destino);
  } while (!validarCodigo(p.destino));  //função que Valida o codigo
  do {
  printf ("\nDigite a cidade de origem: ");
  scanf (" %[^\n]", p.cidadeOrigem);
  } while (!validarCidade(p.cidadeOrigem)); //função que valida a cidade

  do {
  printf ("\nDigite a cidade de destino: ");
  scanf (" %[^\n]", p.cidadeDestino);
  } while (!validarCidade(p.cidadeDestino)); //função que valida a cidade

  do {
  printf ("\nDigite a data da viagem: ");
  scanf ("%s", p.data);
  } while (!validarData(p.data)); //função que valida a data               //Entrada de todos os dados da struct

  do {
  printf ("\nDigite a hora de partida da viagem: ");
  scanf ("%s", p.horaPartida);
  } while (!validarHora(p.horaPartida));  //função que valida a hora

  do {
  printf ("\nDigite a hora de chegada da viagem: ");
  scanf ("%s", p.horaChegada);
  } while (!validarHora(p.horaChegada)); //função que valida a hora

  do {
  printf ("\nDigite o valor da passagem: ");
  leitura = scanf ("%f", &p.valor);
  while (getchar()!='\n');
  } while (!validarValor(p.valor, leitura)); //função que valida o valor



  if (quantID==0) {    //identifica se tem algum arquivo, caso sim o programa cria
  arquivo = fopen("passagens.txt","w");
  quantID=0;
  fprintf (arquivo,"%d\n", quantID);
  fclose (arquivo);
  }

  arquivo =fopen ("passagens.txt", "r+");  //faz o incremento do cadastro mais o ultimo id do cadastro
   fscanf (arquivo,"%d", &quantID);
  quantID++;
  fseek(arquivo, 0, SEEK_SET);
    fprintf (arquivo,"%d\n", quantID);
    ultimoID++;
    p.id = ultimoID;
    fprintf (arquivo,"%d\n", ultimoID);
  fclose (arquivo);

  arquivo = fopen ("passagens.txt", "a");   //acrecenta os dados na ultima linha do arquivo
  fprintf (arquivo, "%d;%s;%s;%s;%s;%s;%s;%s;%.2f\n",
  p.id, p.origem,
  p.destino, p.cidadeOrigem,
  p.cidadeDestino, p.data,
  p.horaPartida, p.horaChegada, p.valor);
  fclose (arquivo);

  printf ("\nPassagem cadastrada com sucesso!\n\n");
  main(); //volta main
}

////////////////////////////////////////////////////////////////////////////////
void editarPassagem() {
int i, indice;
int idpesquisa;
passagem passID[quantID];
do {
    printf("\nDigite um ID para efetuar a pesquisa na qual deseja editar: ");
    int leitura = scanf("%d", &idpesquisa);
    while (getchar()!='\n');
    int indice=0;     //reinicia a variavel (processo de validação para nn "quebrar")
    if (leitura!=1) {
        printf("\nID invalido, digite novamente!\n");
        indice=1;
    }
    if (indice!=1) {
        if (idpesquisa<=0 || idpesquisa>quantID) {
            printf ("\nPassagem nao encontrada!\n\n");
            main(); // volta a main
        }
    }
} while (idpesquisa<=0 || idpesquisa>quantID);

arrayPassagem(passID);

for (i=0;i<quantID;i++) {  //Visualização da passagem
    if (idpesquisa==passID[i].id) { //comparação para encontrar a passagem
        printf ("\nId: %d\n\n", passID[i].id);
        printf ("Origem: %s\n", passID[i].origem);
        printf ("Destino: %s\n", passID[i].destino);
        printf ("Cidade Origem: %s\n", passID[i].cidadeOrigem);
        printf ("Cidade Destino: %s\n", passID[i].cidadeDestino);
        printf ("Data: %s\n", passID[i].data);
        printf ("Hora de partida: %s\n", passID[i].horaPartida);
        printf ("Hora de chegada: %s\n", passID[i].horaChegada);
        printf ("Valor: R$%.2f\n\n", passID[i].valor);
        indice=i;    // a variavel passa a ter outra funcionalidade
    }
}

Editar(passID, indice, idpesquisa); //Função que faz leitura do editado

}

////////////////////////////////////////////////////////////////////////////////
void Editar(passagem *passID, int indice, int idpesquisa) {

printf ("Edite a passagem de ID: %d\n\n", passID[indice].id);

do {
  printf ("\nDigite o codigo de origem do aeroporto: ");
  scanf ("%s", passID[indice].origem);
  } while (!validarCodigo(passID[indice].origem)); //função que Valida o codigo

  do {
  printf ("\nDigite o codigo de destino do aeroporto: ");
  scanf ("%s", passID[indice].destino);
  } while (!validarCodigo(passID[indice].destino)); //função que Valida o codigo

  do {
  printf ("\nDigite a cidade de origem: ");
  scanf (" %[^\n]", passID[indice].cidadeOrigem);
  } while (!validarCidade(passID[indice].cidadeOrigem)); //função que valida a cidade

  do {
  printf ("\nDigite a cidade de destino: ");
  scanf (" %[^\n]", passID[indice].cidadeDestino);
  } while (!validarCidade(passID[indice].cidadeDestino)); //função que valida a cidade

  do {
  printf ("\nDigite a data da viagem: ");
  scanf ("%s", passID[indice].data);
  } while (!validarData(passID[indice].data)); //função que valida a data  //Entrada de todos os dados do array

  do {
  printf ("\nDigite a hora de partida da viagem: ");
  scanf ("%s", passID[indice].horaPartida);
  } while (!validarHora(passID[indice].horaPartida)); //função que valida a hora

  do {
  printf ("\nDigite a hora de chegada da viagem: ");
  scanf ("%s", passID[indice].horaChegada);
  } while (!validarHora(passID[indice].horaChegada)); //função que valida a hora

  do {
  printf ("\nDigite o valor da passagem: ");
  leitura = scanf ("%f", &passID[indice].valor);
  while (getchar()!='\n');
  } while (!validarValor(passID[indice].valor, leitura)); //função que valida o valorw


EditarPorID(passID, quantID, idpesquisa); //Chama a função que vai alterar o arquivo

    printf ("\n\nPassagem editada!\n");
    printf ("Liste as passagens para visualizar\n\n");

}

////////////////////////////////////////////////////////////////////////////////
void EditarPorID(passagem *passID, int quantidade, int idPesquisa) { //Abre o arquivo para fazer a edição
    int i;
    arquivo = fopen("passagens.txt", "w"); //apaga e começo o arquivo do zero
    quantID=0;
    ultimoID=0;
    fprintf (arquivo,"%d\n%d", quantID, ultimoID);
    fclose (arquivo);

    for (i=0;i<quantidade;i++) { //repetidor da quantidade de quantID via a variavel "quantidade"
    arquivo =fopen ("passagens.txt", "r+"); //Monta o arquivo de acordo com a quantidade que tem na variavel "quantidade"
   fscanf (arquivo,"%d", &quantID);
  quantID++;
  fseek(arquivo, 0, SEEK_SET);
    fprintf (arquivo,"%d\n", quantID);
    ultimoID++;
    passID[i].id=ultimoID;
    fprintf (arquivo,"%d\n", ultimoID);
  fclose (arquivo);

  arquivo = fopen ("passagens.txt", "a");  //A implementação no fundo do arquivo com todas as passagens passadas com o array alterado
  fprintf (arquivo, "%d;%s;%s;%s;%s;%s;%s;%s;%.2f\n",
  passID[i].id, passID[i].origem,
  passID[i].destino, passID[i].cidadeOrigem,
  passID[i].cidadeDestino, passID[i].data,
  passID[i].horaPartida, passID[i].horaChegada, passID[i].valor);
   fclose (arquivo);
   }

}

void excluirPassagem(int x){
int i;
int confirmacao;
int idpesquisa;
passagem passID[quantID];

arrayPassagem(passID); //Função onde se faz um array de passagens para serem manipuladas

  do {
    printf("\nDigite um ID para efetuar a pesquisa da passagem na qual deseja excluir: ");
    int leitura = scanf("%d", &idpesquisa);
    while (getchar()!='\n');
    int indice=0;     //reinicia a variavel (processo de validação para nn "quebrar")
    if (leitura!=1) {
        printf("\nID invalido, digite novamente!\n");
        indice=1;
    }
    if (indice!=1) {
        if (idpesquisa<=0 || idpesquisa>quantID) {
            printf ("\nPassagem nao encontrada!\n\n");
            main(); // volta a main
        }
    }
} while (idpesquisa<=0 || idpesquisa>quantID);

  do {                                                                   //
    printf("\nVoce tem certeza que deseja excluir? (1-sim) (2-nao):  "); //
    leitura = scanf ("%d", &confirmacao);                                //
    while (getchar()!='\n');                                             //
    if (confirmacao<=0 || confirmacao>2) {                               //
        leitura=0;                                                       //
        printf ("\nApenas 1 ou 2");                                      //Sistema de confirmação
    }                                                                    //
  } while (!validarOpcao(leitura));                                      //
                                                                         //
  if (confirmacao==2) {                                                  //
     printf ("\n");                                                      //
     main(); //volta a main                                              //
  }

  arquivo = fopen("passagens.txt", "w"); //apaga e começo o arquivo do zero
  quantID=0;
  ultimoID=0;
  fprintf (arquivo,"%d\n%d", quantID, ultimoID);
  fclose (arquivo);

 for (i=0;i<x;i++) {  //repetidor da quantidade de quantID via a variavel "quantidade"
  if (idpesquisa-1!=i) {  //comparador para encontrar o id que quer excluir
  arquivo =fopen ("passagens.txt", "r+");
  fscanf (arquivo,"%d", &quantID);
  quantID++;
  fseek(arquivo, 0, SEEK_SET);
  fprintf (arquivo,"%d\n", quantID);
  ultimoID++;
  passID[i].id=ultimoID;
  fprintf (arquivo,"%d\n", ultimoID);
  fclose (arquivo);

  arquivo = fopen ("passagens.txt", "a"); //A implementação no fundo do arquivo com todas as passagens passadas com o array alterado
  fprintf (arquivo, "%d;%s;%s;%s;%s;%s;%s;%s;%.2f\n",
  passID[i].id, passID[i].origem,
  passID[i].destino, passID[i].cidadeOrigem,
  passID[i].cidadeDestino, passID[i].data,
  passID[i].horaPartida, passID[i].horaChegada, passID[i].valor);
  fclose (arquivo);

  }
 }
 printf ("\nA passagem foi excluida!\n\n");
}

////////////////////////////////////////////////////////////////////////////////
void arrayPassagem(passagem *pass) { //A Função que se faz um array de passagens para serem manipuladas
  arquivo = fopen ("passagens.txt", "r");
  fscanf (arquivo,"%d\n%d", &quantID, &ultimoID);
for (int i=0;i<quantID;i++) {

    fscanf (arquivo,"%d;", &pass[i].id);
    fscanf (arquivo,"%[^;];", pass[i].origem);
    fscanf (arquivo,"%[^;];", pass[i].destino);
    fscanf (arquivo,"%[^;];", pass[i].cidadeOrigem);
    fscanf (arquivo,"%[^;];", pass[i].cidadeDestino);
    fscanf (arquivo,"%[^;];", pass[i].data);
    fscanf (arquivo,"%[^;];", pass[i].horaPartida);
    fscanf (arquivo,"%[^;];", pass[i].horaChegada);
    fscanf (arquivo,"%f\n", &pass[i].valor);
    upperCase(pass[i].origem);
    upperCase(pass[i].destino);       //Transforma em maisculo para a comparação e visualização
    upperCase(pass[i].cidadeOrigem);
    upperCase(pass[i].cidadeDestino);
 }
   fclose (arquivo);
}

////////////////////////////////////////////////////////////////////////////////
                             //VALIDAÇÕES//
////////////////////////////////////////////////////////////////////////////////
void upperCase(char *str) {
    //Transforma todas as strings nessa função em maísculo
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

////////////////////////////////////////////////////////////////////////////////
int validarCodigo(char *codigo) {
    // verifica o tamanho da string codigo fazendo que ela obrigatoriamente tenha 3 letras
    if (strlen(codigo) != 3) {
        printf("\nCodigo deve ter exatamente tres letras!\n");
        return 0;
    }
    for (int i=0;i<3;i++) {
    //quando codigo[i] não for uma letra ele retornara negativo
        if (!isalpha(codigo[i])) {
            printf("\nCodigo deve conter apenas letras!\n");
            return 0;
        }
    }
    return 1;
}

////////////////////////////////////////////////////////////////////////////////
int validarCidade(char *cidade) {
    //controla o tamanho da string
    int comprimento = strlen(cidade);
    if (strlen(cidade) > 30) {
        printf("\nFoi excedido o valor maximo da string!\n");
        return 0;
    }


    // Verifica se cada caractere é uma letra ou um espaço
    for (int i = 0; i < comprimento; i++) {
        if (!iswalpha((wint_t)cidade[i]) && !isspace(cidade[i])) {
            printf("\nA Cidade deve conter apenas letras e espacos!\n");
            return 0;
        }
    }
    return 1;
}

////////////////////////////////////////////////////////////////////////////////
int validarData(char *data) {
int dia, mes, ano;
int resultado;

resultado = sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano);

char formatoEsperado[11];
            sprintf(formatoEsperado, "%02d/%02d/%04d", dia, mes, ano);
            if (strcmp(data, formatoEsperado) != 0) {
                printf("\nUse zeros a esquerda no formato da data! (ex: 05/08/2023)\n");
                return 0;
            }

if (resultado==3) {
 if (dia >=1 && dia<=31 && mes >=1 && mes <=12 && ano >=2000 ){
       //Se ano bissexto em fevereiro
  if (mes==2 && dia <= 29) {
      if (ano%4==0) {
        return 1;
      }
      printf ("\nData invalida, Tente novamente!\n");
      return 0;
   }
  //separação dos meses q tem 30 e 31 dias
  if(dia>30){
   if(mes%2==0 && mes<8) {
     printf ("\nData invalida, Tente novamente!\n");
     return 0;
   }
   else if (mes%2==1 && mes>= 8) {
     printf ("\nData invalida, Tente novamente!\n");
     return 0;
   }
  }

 return 1;

} else {
  printf ("\nData invalida, Tente novamente!\n");
  return 0;
  }
 }
}

////////////////////////////////////////////////////////////////////////////////
int validarHora(char *hora) {
int min, horas;
int resultado;

resultado = sscanf(hora, "%02d:%2d", &horas, &min);

if (resultado==2) {
    if (min >=0 && min <=59 && horas >=0 && horas <=23) {
           char formatoEsperado[6];
            sprintf(formatoEsperado, "%02d:%02d", horas, min);
            //valida o formato esperando os zeros
            if (strcmp(hora, formatoEsperado) != 0) {
                printf("\nUse zeros a esquerda no formato do horario! (ex: 08:05)\n");
                return 0;
            }
       return 1;
     }
}
printf ("\nHora Invalida!\n");
return 0;
}

////////////////////////////////////////////////////////////////////////////////
int validarValor(float valor, int leitura) {
   //verifica o scanf
   if (leitura!=1) {
        valor=-1;
        printf ("\nValor invalido!\n");
         return 0;
   }
   if (valor==',') {
    printf ("\nValor invalido!\n");
    return 0;
   }
   if (valor<0) {
        printf ("\nValor invalido!\n");
    return 0;
   }
   return 1;
}

////////////////////////////////////////////////////////////////////////////////
 int validarOpcao(int leitura) {
  //verifica o scanf
  if (leitura!=1){
    printf ("\nOpcao invalida!\n");
    return 0;
  }
  return 1;
  }

////////////////////////////////////////////////////////////////////////////////
int validaArquivo() {
    //Abre o arquivo para verificar se existe
    arquivo = fopen ("passagens.txt", "r");
    fscanf (arquivo,"%d", &quantID);
if (quantID>0) {
    return 1;
}
if (quantID==0) {
    printf ("\nO Arquivo esta vazio, cadastre uma passagem para acessar!\n\n");
    return 0;
}
fclose (arquivo);
  return 1;
}
