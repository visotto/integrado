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

Tipo Ingresso::getTipo()
{
	return tipo;
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
