#ifndef GERENCIAVENDA_H
#define GERENCIAVENDA_H

#include <iostream>
#include "../headers/consts.h"
#include "../headers/ingresso.h"
#include "../headers/sessao.h"
#include "../headers/venda.h"
#include "../headers/gerenciasala.h"
#include "../headers/gerenciasessao.h"

class GerenciaVenda
{
	private:
	Venda *vendas[MAX_VENDAS];
	int qtdVendas; //por sessao e por horario
	GerenciaSala *gerencSala;
	GerenciaSessao *gerencSessao;
	void escreverVenda();

	public:
	GerenciaVenda(GerenciaSala *gerencSala, GerenciaSessao *gerencSessao);
	void criaVenda();
	void addIngressoVenda(int idVenda);
	void removeIngressoVenda(int idVenda); 
	void exibirVenda(int idVenda);
};

#endif // GERENCIAVENDA_H
