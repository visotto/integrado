#include "../headers/assento.h"

Assento::Assento(int _idAssento, bool _disponibilidade, char _idFileira)
{
  idAssento = _idAssento;
  disponibilidade = _disponibilidade;
  idFileira = _idFileira;
}

void Assento::setDisponibilidade(bool _disponibilidade)
{
  disponibilidade = _disponibilidade;
}

void Assento::setIdAssento(int _idAssento)
{
  idAssento = _idAssento;
}

void Assento::setIdFileira(char _idFileira)
{
  idFileira = _idFileira;
}

bool Assento::getDisponibilidade()
{
  return disponibilidade;
}

int Assento::getIdAssento()
{
  return idAssento;
}

char Assento::getIdFileira()
{
  return idFileira;
}
