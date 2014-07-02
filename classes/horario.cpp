#include "../headers/horario.h"

Horario::Horario(const Horario &h)
{
  hora = h.hora;
  minuto = h.minuto;
}

int Horario::getHora()
{
  return hora;
}

int Horario::getMinuto()
{
  return minuto;
}

ostream &operator<<(ostream &o, const Horario &h)
{
  o << h.hora << ":" << h.minuto;

  return o;
}

istream &operator>>(istream &i, Horario &h)
{
  i >> h.hora; 
  i.ignore(1); // ignora o ':'
  i >> h.minuto;

  return i;
}

stringstream &operator>>(stringstream &s, Horario &h)
{
  s >> h.hora; 
  s.ignore(1); // ignora o ':'
  s >> h.minuto;

  return s;
}
