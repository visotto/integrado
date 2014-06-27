#ifndef SESSAO_H
#define SESSAO_H

#include <iostream>
#include "../headers/consts.h"

using std::string;

typedef struct _horario
{
  int horas;
  int minutos;
} Horario;

class Sessao
{
  private:
    Horario *horarios;
    int qtdHorarios;
    bool encerrada;
    int numVendido;
    Filme f;
    Sala *sala; 

  public:
    Sessao(bool _encerrada, int _numVendido, string _filme);
    Sessao(const Sessao &s);

    void setStatus(bool encerrada); // modifica o status da sessao: 1 = encerrada, 0 caso contrario
    int getStatus();

    void setHorario(Horario* horario); // para adicionar todos os horarios
    bool setHorario(Horario* horario, Horario anterior, Horario atual); // para alterar um horario
    Horario* getHorarios(); // retorna o vetor de horarios

    void setNumVendido(int numVendido);
    int getDisponivel();

};

#endif // SESSAO_H
