#ifndef SESSAO_H
#define SESSAO_H

#include <iostream>
  using std::string;
  using std::array;

class Sessao
{
  private:
    array horario;
    int encerrada;
    int numVendido;
    string filme;
    Sala *sala; 

  public:
    Sessao(array _horario, int _encerrada, int _numVendido, string _filme);
    Sessao(const Sessao &s);

    void setStatus(int encerrada);
    int getStatus();

    void setHorario(array horario);
    array getHorario();

    void setNumVendido(int numVendido);
    int getDisponivel();

    void setFilme(string nomeFilme);
    string getFilme();
};

#endif // SESSAO_H
