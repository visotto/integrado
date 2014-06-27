#ifndef SESSAO_H
#define SESSAO_H

#include <iostream>
#include <ctime.h>
  using std::string;

typedef struct _horario
{
  int horas;
  int minutos;
} Horario;

class Sessao
{
  private:
    static const int  maxHorarios;
    Horario *horarios;
    int qtdHorarios;
    bool encerrada;
    int numVendido;
    Filme *filme;
    Sala *sala; 

  public:
    Sessao(bool _encerrada, int _numVendido, string _filme);
    Sessao(const Sessao &s);

    void setStatus(bool encerrada);
    int getStatus();

    void setHorario(array horario);
    Horario* getHorarios(); // retorna o vetor de horarios

    void setNumVendido(int numVendido);
    int getDisponivel();

    void setFilme(string nomeFilme);
    string getFilme();
};

#endif // SESSAO_H
