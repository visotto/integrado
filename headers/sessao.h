#ifndef SESSAO_H
#define SESSAO_H

#include "../headers/consts.h"
#include "../headers/sala.h"
#include "../headers/horario.h"
#include "../headers/filme.h"
#include "../headers/ingresso.h"

class Sessao
{
  private:
  int id;
    Horario horario;
    bool encerrada;
    int numVendido;
    Filme *filme; // uma sessao conhece um filme
    Sala *sala; // uma sessao conhece uma sala 
    Ingresso **ingressos; // uma sessao possui ingressos relativos a ela
    int qtdIngressos;

  public:
    Sessao(Sala *_sala, int _id, Horario _horario, Filme *_filme);
    ~Sessao();

    bool getStatus();
    void setStatus(bool encerrada);

    Horario getHorario();
    void setHorario(Horario _horario);

    int getDisponivel();
    Ingresso* getIngresso(char idFileira, int idAssento);

    int getNumVendido();
    void incNumVendido(char opcao); // incrementa o numVendido em +1 ou -1 dependendo da opcao

    int getQueryID(); // retorna o id da sessao

    Sala* getSala();
    Filme* getFilme();
};

#endif // SESSAO_H
