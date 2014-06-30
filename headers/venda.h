#ifndef VENDA_H
#define VENDA_H

#include <iostream>
#include <iomanip>
#include "../headers/consts.h"
#include "../headers/ingresso.h"
#include "../headers/sessao.h"

using std::string;
using std::setprecision;
using std::fixed;

enum FormaPagto{dinheiro, cartao};

class Venda{
  
  private:
  int id;
    double valorTotal;
    FormaPagto formaPagto;
    Ingresso **ingressos; // vetor de ponteiros para ingressos
    int qtdIngressos;
    Sessao *sessao; // atualiza disponibilidade
  
  public:
    Venda(Sessao *_sessao, int _id ,FormaPagto _formaPagto);
    ~Venda();
    double calcularValorTotal();
    void emitirIngresso(Ingresso *ingresso);
    void addIngresso(Ingresso *ingresso, double valor, Tipo tipo);
    void removeIngresso(Ingresso *ingresso);
    string getFormaPagto();

    int getQueryID();
    int getQtdIngressos();
    Sessao *getSessao();
    Ingresso *getIngresso(int id);
};

#endif // VENDA_H
