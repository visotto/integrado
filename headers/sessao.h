#ifndef SESSAO_H
#define SESSAO_H

#include <iostream>
#include "../headers/consts.h"
#include "../headers/sala.h"
#include "../headers/horario.h"
#include "../headers/filme.h"
#include "../headers/ingresso.h"

using std::string;

class Sessao
{
  private:
    Horario horario;
    bool encerrada;
    int numVendido;
    Filme *filme; // uma sessao conhece um filme
    Sala *sala; // uma sessao conhece uma sala 
	Ingresso **ingressos; // uma sessao possui ingressos relativos a ela
	int qtdIngressos;

  public:
    Sessao(Sala *_sala, Horario _horario, Filme *_filme);
	~Sessao();

    void setStatus(bool encerrada);
    bool getStatus();

    void setHorario(Horario _horario);
    Horario getHorario();

	Ingresso* getIngresso(char idFileira, int idAssento);

    void incNumVendido(char opcao);
    int getDisponivel();
	int getNumVendido();

};

#endif // SESSAO_H
