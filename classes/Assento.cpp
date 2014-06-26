#include "../headers/Assento.h"

Assento::Assento(int _idAssento, bool _disponibilidade, char _idFileira)
{
  idAssento = _idAssento;
  disponibilidade = _disponibilidade;
  idFileira = _idFileira;
}

Assento::Assento(const Assento &a) // construtor de copia FUTURO
{
  idAssento = a.idAssento;
  disponibilidade = a.disponibilidade;
  idFileira = a.idFileira;
}

bool Assento::verificaDisponibilidade()
{
  return disponibilidade;
  // return (disponibilidade ? true : false);
  // pois antes era int
}

void Assento::setIdAssento(int _idAssento)
{
  idAssento = _idAssento;
}

void Assento::setIdFileira(char _idFileira);
{
  idFileira = _idFileira;
}

int Assento::getIdAssento();
{
  return idAssento;
}

char Assento::getIdFileira();
{
  return idFileira;
}
