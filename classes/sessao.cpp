#include "../headers/Sessao.h"

Sessao(array _horario, bool _encerrada, int _numVendido, string _filme)
{
  horario = _horario;
  encerrada = _encerrada;
  numVendido = _numVendido;
  filme = _filme;
}

Sessao(const Sessao &s)
{
  horario = s.horario;
  encerrada = s.encerrada;
  numVendido = s.numVendido;
  filme = s.filme;

}

void Sessao::setStatus(bool encerrada)
{
  Sessao::encerrada = encerrada;
}

int Sessao::getStatus()
{
  return encerrada;
}

void Sessao::setHorario(array horario)
{
  Sessao::horario = horario;
}

array Sessao::getHorario()
{
  return horario;
}

void Sessao::setNumVendido(int numVendido)
{
  Sessao::numVendido = numVendido;
}

int Sessao::getNumVendido()
{
  return numVendido;
}

void Sessao::setFilme(string nomeFilme)
{
  filme = nomeFilme;
}

string Sessao::getFilme()
{
  return filme;
}


