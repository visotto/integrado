#include "../headers/Sala.h"

Sala(int _numSala, int _capacidade, Situacao _situacao)
{
  numSala = _numSala;
  capacidade = _capacidade;
  situacao = _situacao;
}

Sala(const Sala &s)
{
  numSala = s.numSala;
  capacidade = s.capacidade;
  situacao = s.situacao;
}

int Sala::getNumSala()
{
  return numSala;
}

void Sala::setNumSala(int numSala)
{
  Sala::numSala = numSala;
}

void Sala::setCapacidade(int capacidade)
{
  Sala::capacidade = capacidade;
}

int Sala::getCapacidade()
{
  return capacidade;
}
