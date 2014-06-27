#include "../headers/Sessao.h"

Sessao::maxHorarios = 48;

Sessao(bool _encerrada, int _numVendido, string _filme)
{
  horarios = new Horario[maxHorarios];
  encerrada = _encerrada;
  numVendido = _numVendido;
  filme = _filme;
}

Sessao(const Sessao &s)
{
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

// posicionador usado para inserir um horario na primeira posicao
void Sessao::setHorario(array horario)
{
  if (qtdHorarios < maxHorarios)
  {
    Sessao::horarios[qtdHorarios] = horario;
    qtdHorarios++;
  }
}

Horario* Sessao::getHorarios()
{
  Horario *retorno = new Horario[maxHorarios];

  // copia todos os horarios desta sessao
  for (int i = 0; i < qtdHorarios; i++)
      retorno[i] = horarios[i];
  // o retorno de um veotr auxiliar eh utilizado para nao quebrar o encapsulamento
  return retorno;
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


