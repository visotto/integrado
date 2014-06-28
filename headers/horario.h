#ifndef HORARIO_H
#define HORARIO_H

#include <iostream>

using std::ostream;

class Horario
{
	friend ostream &operator<<(ostream &o, const Horario &h);

	private:
		int hora;
		int minuto;

	public:
		Horario() : hora(0), minuto(0) {} ;
		Horario(int h, int m) : hora(h), minuto(m) {} ;
		Horario(const Horario &h)
		{
			hora = h.hora;
			minuto = h.minuto;
		}
};

#endif // HORARIO_H
