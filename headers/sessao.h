#ifndef SESSAO_H
#define SESSAO_H

#include <iostream>
#include "../headers/consts.h"
#include "../headers/sala.h"

using std::string;

typedef struct _horario
{
  int horas;
  int minutos;
} Horario;

class Sessao
{
  private:
    Horario *horarios; // uma sessao possui varios horarios
    int qtdHorarios;
    bool encerrada;
    int numVendido;
    Filme *filme; // uma sessao conhece um filme
    Sala *sala; // uma sessao conhece uma sala 

  public:
    Sessao(Sala *_sala, bool _encerrada, int _numVendido, Filme *_filme);
    Sessao(const Sessao &s);

    void setStatus(bool encerrada);
    int getStatus();

    void setHorario(Horario* horario); // para adicionar todos os horarios
    bool setHorario(Horario* horario, Horario anterior, Horario atual); // para alterar um horario
    Horario* getHorarios(); // retorna o vetor de horarios

    void incNumVendido(int numVendido);
    int getDisponivel();

};

#endif // SESSAO_H
