#ifndef VENDA_H
#define VENDA_H

#include <iostream>
#include "../headers/consts.h"
#include "../headers/ingresso.h"
#include "../headers/sessao.h"

using std::string;

enum FormaPagto{dinheiro, cartao};

class Venda
{
  
  private:
  int id;
    double valorTotal;
    FormaPagto formaPagto;
    Ingresso **ingressos; // vetor de ponteiros para ingressos
    int qtdIngressos;
    Sessao *sessao; // atualiza disponibilidade
  
  public:
    Venda(Sessao *_sessao, int _id ,FormaPagto _formaPagto); // construtor
    ~Venda(); // destrutor
    double calcularValorTotal();
    void emitirIngresso(Ingresso *ingresso);
    void addIngresso(Ingresso *ingresso, double valor, Tipo tipo);
    void removeIngresso(Ingresso *ingresso);
    
    string getFormaPagto();
    int getQtdIngressos();
    Sessao *getSessao();
    Ingresso *getIngresso(int id);
    int getQueryID(); // retorna o id da venda
};

#endif // VENDA_H
