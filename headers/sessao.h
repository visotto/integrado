#ifndef SESSAO_H
#define SESSAO_H

#include <iostream>
  using std::string;
  using std::array;

class Sessao
{
  private:
    array horario;
    bool encerrada;
    int numVendido;
    string filme;
    Sala *sala; 

  public:
    Sessao(array _horario, bool _encerrada, int _numVendido, string _filme);
    Sessao(const Sessao &s);

    void setStatus(bool encerrada);
    int getStatus();

    void setHorario(array horario);
    array getHorario();

    void setNumVendido(int numVendido);
    int getDisponivel();

    void setFilme(string nomeFilme);
    string getFilme();
};

#endif // SESSAO_H
