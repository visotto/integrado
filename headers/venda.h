#ifndef VENDA_H
#define VENDA_H

#include <iostream>
#include "../headers/consts.h"
#include "../headers/ingresso.h"
#include "../headers/sessao.h"

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
    void addIngresso(Ingresso *ingresso);
    void removeIngresso(Ingresso *ingresso);

	int getQueryID();

};

#endif // VENDA_H
