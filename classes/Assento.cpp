#include "../headers/Assento.h"

Assento::Assento(int _idAssento, bool _disponibilidade, char _idFileira)
{
  idAssento = _idAssento;
  disponibilidade = _disponibilidade;
  idFileira = _idFileira;
}

Assento::Assento(const Assento &a)
{
  idAssento = a.idAssento;
  disponibilidade = a.disponibilidade;
  idFileira = a.idFileira;
}

bool Assento::verificaDisponibilidade()
{
  return (disponibilidade ? true : false);
}
