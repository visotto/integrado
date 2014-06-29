#ifndef HORARIO_H
#define HORARIO_H

#include <iostream>
#include <sstream>

using std::ostream;
using std::istream;
using std::stringstream;

class Horario
{
	friend ostream &operator<<(ostream &o, const Horario &h);
	friend istream &operator>>(istream &i, Horario &h);
	friend stringstream &operator>>(stringstream &s, Horario &h);

	private:
		int hora;
		int minuto;

	public:
		int getHora();
		int getMinuto();
		Horario() : hora(0), minuto(0) {} ;
		Horario(int h, int m) : hora(h), minuto(m) {} ;
		Horario(const Horario &h)
		{
			hora = h.hora;
			minuto = h.minuto;
		}
};

#endif // HORARIO_H
