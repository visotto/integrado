#include "../headers/ingresso.h"

Ingresso::Ingresso(Horario _horaIngresso, Assento *_assento)
{
  horaIngresso = _horaIngresso;
  assento = _assento;
}

bool Ingresso::isVendido()
{
  return vendido;
}

double Ingresso::getValor()
{
  return valor;
}

Horario Ingresso::getHorario()
{
  return horaIngresso;
}

string Ingresso::getTipo()
{
  if (tipo == inteiro)
    return "inteiro";
  else
    return "meia";
}

void Ingresso::setTipo(Tipo t)
{
  tipo = t;
}

Assento* Ingresso::getAssento()
{
  return assento;
}

void Ingresso::setValor(double valor)
{
  Ingresso::valor = valor;
}

void Ingresso::venda()
{
  vendido = true;
  assento->setDisponibilidade(false);
}

void Ingresso::cancela()
{
  vendido = false;
  assento->setDisponibilidade(true);
}
