#ifndef GERENCIAVENDA_H
#define GERENCIAVENDA_H

#include <iostream>
#include "../headers/consts.h"
#include "../headers/ingresso.h"
#include "../headers/sessao.h"
#include "../headers/venda.h"
<<<<<<< HEAD
#include "../headers/gerenciasala.h"
#include "../headers/gerenciasessao.h"
=======
>>>>>>> FETCH_HEAD

class GerenciaVenda
{
	private:
<<<<<<< HEAD
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
=======
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

>>>>>>> FETCH_HEAD
};

#endif // GERENCIAVENDA_H
