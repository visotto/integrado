#ifndef GERENCIAVENDA_H
#define GERENCIAVENDA_H

#include <iostream>
#include "../headers/consts.h"
#include "../headers/ingresso.h"
#include "../headers/sessao.h"
#include "../headers/venda.h"

class GerenciaVenda
{
	private:
	Venda *venda[MAX_VENDAS];
	Sessao *sessao;
	Ingresso **ingressos;
	int id;
	int qtdVendas;
	
	public:
	GerenciaVenda();
	~GerenciaVenda();
	void criaVenda();
	void addIngressoVenda();
	void removeIngressoVenda();
	void exibirVenda(int _id);
	void exibirVenda(Sessao *_sessao);

};

#endif // GERENCIAVENDA_H
