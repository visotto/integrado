#include "../headers/Ingresso.h"

Ingresso(Date _dtIngresso, double _valor, Tipo _tipo)
{
  dtIngresso = _dtIngresso;
  valor = _valor;
  tipo = _tipo;
}

Ingresso(const Ingresso &i)
{
  dtIngresso = i.dtIngresso;
  valor = i.valor;
  tipo = i.tipo;
}

Date getDtingresso();
{
  return dtIngresso;
}

void setDtingresso(Date dtIngresso)
{
  Ingresso::dtIngresso = dtIngresso;
}

double getValor()
{
  return valor;
}

void setValor()
{
  Ingresso::valor = valor;
}
