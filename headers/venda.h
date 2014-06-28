#ifndef VENDA_H
#define VENDA_H

#include <iostream>
#include "../headers/consts.h"

enum FormaPagto{dinheiro, cartao};

class Venda{
  private: 
    Date dtVenda;
    double valorTotal;
    FormaPagto formaPagto;
    Ingresso **ingressos; // vetor de ponteiros para ingressos
	int qtdIngressos;
    Sessao *sessao; // atualiza disponibilidade
  
  public:
    Venda(Date _dtVenda, double _valorTotal, FormaPagto _formaPagto);
    Venda(const Venda &v);
    double calcularValorTotal();
    void emitirIngresso(Arrays ingresso);
    void addIngresso(Ingresso ingresso);
    void removeIngresso(Ingresso ingresso);
    
};

#endif // VENDA_H
