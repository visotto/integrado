#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>

#include "../headers/gerenciavenda.h"

using namespace std;


GerenciaVenda::GerenciaVenda(GerenciaSala *g1, GerenciaSessao *g2) : gerencSala(g1), gerencSessao(g2)
{      
  int i, j;

  for (i = 0; i < MAX_SESSOES; i++)
    vendas[i] = NULL;
  qtdVendas = 0;

  // variavel para leitura do arquivo
  ifstream leitura; 
  
  // carrega o arquivo
  leitura.open("resources/vendas.data");  

  // caso o arquivo nao seja aberto corretamente
  if(!leitura.is_open( )) 
  {
    leitura.clear( ); // reseta o objeto leitura, para limpar memoria do sistema
    cout << "Nao foi possivel abrir arquivo vendas.data!\n";
    return;  
  }

  // variavel para leitura de cada linha do arquivo
  string leituraLinha;

  // variaveis que sera passada para o construtor de cada sessao
  int _id, _idSessao;
  Sessao *_sessao;
  FormaPagto _formaPagto;
  Ingresso **ingressos;
  string _tituloFilme;

  // le do arquivo a quantidade de vendas armazenadas
  getline(leitura, leituraLinha);
  
  // verifica se o arquivo esta vazio
  if(leituraLinha != "")
  {
    // temos agora uma string stream para processar a string leituraLinha;
    stringstream convertQtdVendas(leituraLinha);
    
    // extrai o inteiro da string stream para a variavel "qtdVendas"             
    convertQtdVendas >> qtdVendas;

    int k = 0;
    // enquanto tiver vendas armazenadas no arquivo
    while(k < qtdVendas){
      
      // le do arquivo o id da venda
      getline(leitura, leituraLinha);
      stringstream convertIdVenda(leituraLinha);           
           convertIdVenda >> _id;

      // le do arquivo o numero da sessao
      getline(leitura, leituraLinha);
      stringstream convertIdSessao(leituraLinha);
      convertIdSessao >> _idSessao;
      Sessao *_sessao = gerencSessao->buscarSessao(_idSessao);

      // le do arquivo a forma de pagamento
      getline(leitura, leituraLinha);

      // converte a string lida para tipo FormaPagto
      if(leituraLinha == "dinheiro")
        _formaPagto = dinheiro;
        
      if(leituraLinha == "cartao")
        _formaPagto = cartao;

      // le do arquivo o titulo do filme
      getline(leitura, leituraLinha);
      _tituloFilme = leituraLinha;

      // aloca a sessao k armazenada no arquivo
      vendas[k] = new Venda(_sessao, _id , _formaPagto);

      // le os ingressos vendidos por uma instancia de venda
      for(j = 0; 1; j++)
      {
        int aux = 0;
        getline(leitura, leituraLinha);

        if(leituraLinha[0] < 'A' || leituraLinha[0] > 'Z')
          break; // nao eh ingresso a ser lido

        char idF = leituraLinha[0];

        if(leituraLinha[2] >= '0' && leituraLinha[2] <= '9')
          aux = ((leituraLinha[1] - '0') * 10) + (leituraLinha[2] - '0');
        else          
          aux = leituraLinha[1] - '0';

        // criar dinamicamente um vetor de ingressos - Representa a relacao de ingressos 'conhecidos'(vendidos) por essa venda
        // fazer um ponteiro de vendas apontar para esse vetor

        getline(leitura, leituraLinha);
        stringstream convertValor(leituraLinha);
        double valor;
        convertValor >> valor;

        getline(leitura, leituraLinha);
        Tipo tipo;
        
        if (leituraLinha == "inteiro")
          tipo = inteiro;
        if (leituraLinha == "meia")
          tipo = meia;

        vendas[k]->addIngresso(vendas[k]->getSessao()->getIngresso(idF, aux), valor, tipo);
      }
      k++;
    }
  }
  // fecha o arquivo
  leitura.close();  
}


void GerenciaVenda::criaVenda()
{
  int id, idSessao, fp;
  Sessao *sessao;
  int i;

  if (qtdVendas < MAX_VENDAS)
  {
    cout << "Digite o id da venda: ";
    cin >> id;

    for (i = 0; i < qtdVendas; i++)
      if (id == vendas[i]->getQueryID())
        throw "\nJa existe uma venda com este numero\n";

    cout << "Digite o id da sessao relacionada a esta venda: ";
    cin >> idSessao;
    if (gerencSessao->buscarSessao(idSessao))
      sessao = gerencSessao->buscarSessao(idSessao);
    else
      throw "\nEsta sessao nao existe!\n";

    cout << "Digite a forma de pagamento (dinheiro = 0, cartao = 1): ";
    cin >> fp;

    if (fp < 0 || fp > 1)
      throw "\nForma de pagamento invalida!\n";

    FormaPagto fpt = static_cast <FormaPagto> (fp);
    vendas[qtdVendas] = new Venda(sessao, id, fpt);

    cout << "\nVenda criada com sucesso!\n" << endl;
    qtdVendas++;

    // chama funcao para escrever nova sala no arquivo
    escreverVenda();
    gerencSala->escreverSala();
    gerencSessao->escreverSessao();
  }

  else
    throw "Nao ha espaco para criar novas vendas!\n";
}

void GerenciaVenda::addIngressoVenda(int idVenda)
{
  for (int i = 0; i < qtdVendas; i++)
  {
    if (vendas[i]->getQueryID() == idVenda)
    {
      char idF;
      int idA;

      cout << "Digite o id da fileira (caractere): ";
      cin >> idF;
      cout << "Digite o id do assento (numero): ";
      cin >> idA;

      if (vendas[i]->getSessao()->getIngresso(idF,idA)->isVendido())
        throw "Ingresso indisponivel!\n";

      double valor;
      int tipo;

      cout << "Digite o valor do ingresso: ";
      cin >> valor;
      cout << "Digite o tipo do ingresso (inteiro = 0, meia = 1): ";
      cin >> tipo;

      if (tipo < 0 || tipo > 1)
        throw "\nForma de pagamento invalida!\n";


      Tipo t = static_cast <Tipo> (tipo);

      if (t == inteiro)
      {      
        vendas[i]->addIngresso(vendas[i]->getSessao()->getIngresso(idF,idA), valor, t);
      }
      else
      {
        vendas[i]->addIngresso(vendas[i]->getSessao()->getIngresso(idF,idA), (double)valor/2, t);
      }

      cout << "Ingresso adicionado com sucesso!" << endl;

      // chama funcao para escrever nova sala no arquivo
      escreverVenda();
      gerencSala->escreverSala();
      gerencSessao->escreverSessao();

      return;
    }
  }

  throw "Venda com este ID nao existe!\n";
}

void GerenciaVenda::removeIngressoVenda(int idVenda)
{
  for (int i = 0; i < qtdVendas; i++)
  {
    if (vendas[i]->getQueryID() == idVenda)
    {
      char idF;
      int idA;

      cout << "Digite o id da fileira (caractere): ";
      cin >> idF;
      cout << "Digite o id do assento (numero): ";
      cin >> idA;

      if (!vendas[i]->getSessao()->getIngresso(idF,idA)->isVendido())
        throw "Ingresso ainda nao foi vendido!\n";

      vendas[i]->removeIngresso(vendas[i]->getSessao()->getIngresso(idF,idA));
      cout << "Ingresso removido com sucesso!" << endl;

      // chama funcao para escrever nova sala no arquivo
      escreverVenda();
      gerencSala->escreverSala();
      gerencSessao->escreverSessao();

      return;
    }
  }

  throw "Venda com este ID nao existe!\n";
}

void GerenciaVenda::exibirVenda(int idVenda)
{
  for (int i = 0; i < qtdVendas; i++)
  {
    if (vendas[i]->getQueryID() == idVenda)
    {
      cout << "Venda " << idVenda << ":" << endl;
      for (int j = 0; j < vendas[i]->getQtdIngressos(); j++)
        if (vendas[i]->getIngresso(j) != NULL)
          vendas[i]->emitirIngresso(vendas[i]->getIngresso(j));

      if (vendas[i]->getFormaPagto() == "cartao")
        cout << "Valor total: R$ " << vendas[i]->calcularValorTotal()*0.9 << " (10 porcento de desconto no cartao)"; 
      else
        cout << "Valor total: R$ " << vendas[i]->calcularValorTotal();

      cout << endl << endl;
      return;
    }
  }

  throw "Venda com este ID nao existe!\n";

}

void GerenciaVenda::escreverVenda(){

  ofstream escreve; // variavel para escrever no arquivo sessoes.data
  int i;

  escreve.open("resources/vendas.data"); // comeca a escrever no inicio do arquivo
  
  char aux; // variavel para gravar o valor de qtdSessoes no arquivo para leituras futuras
  
  escreve << qtdVendas << "\n";
  for(i = 0; i < qtdVendas && vendas[i] != NULL; i++){
    // escreve no arquivo vendas.data
    escreve << vendas[i]->getQueryID() << "\n";
    escreve << vendas[i]->getSessao()->getQueryID() << "\n";
    escreve << vendas[i]->getFormaPagto() << "\n";
    escreve << vendas[i]->getSessao()->getFilme()->getTituloFilme() << "\n";
    
    for (int j = 0; j < vendas[i]->getQtdIngressos(); j++)
    {
      escreve << vendas[i]->getIngresso(j)->getAssento()->getIdFileira() << vendas[i]->getIngresso(j)->getAssento()->getIdAssento() << "\n";
      escreve << vendas[i]->getIngresso(j)->getValor() << "\n";
      escreve << vendas[i]->getIngresso(j)->getTipo() << "\n";
    }
  }
  escreve.close();  
}

void GerenciaVenda::listarVendas()
{
  
  if (!qtdVendas)
    throw "\nNao existem vendas cadastradas!\n";

  cout << "Lista de vendas cadastradas:" << endl;
  for (int i = 0; i < qtdVendas; i++)
  {
    
      cout << "Venda " << vendas[i]->getQueryID() << ":" << endl;
      for (int j = 0; j < vendas[i]->getQtdIngressos(); j++)
        if (vendas[i]->getIngresso(j) != NULL)
          vendas[i]->emitirIngresso(vendas[i]->getIngresso(j));

      if (vendas[i]->getFormaPagto() == "cartao")
        cout << "Valor total: R$ " << vendas[i]->calcularValorTotal()*0.9 << " (10 porcento de desconto no cartao)"; 
      else
        cout << "Valor total: R$ " << vendas[i]->calcularValorTotal();

      cout << endl << endl;
      return;
    
  }

  throw "Venda com este ID nao existe!\n";

}