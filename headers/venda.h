#ifndef VENDA_H
#define VENDA_H

#include <iostream>

enum FormaPagto{dinheiro, cartao};

class Venda{
  private: 
    Date dtVenda;
    double valorTotal;
    FormaPagto formaPagto;
    Ingresso **ingressos;
    Sessao **sessao; // atualiza disponibilidade
  
  public:
    Venda(Date _dtVenda, double _valorTotal, FormaPagto _formaPagto);
    Venda(const Venda &v);
    double calcularValorTotal();
    void emitirIngresso(Arrays ingresso);
    void addIngresso(Ingresso ingresso);
    void removeIngresso(Ingresso ingresso);
    
};

#endif // VENDA_H
