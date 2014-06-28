#include "../headers/horario.h"

ostream &operator<<(ostream &o, const Horario &h)
{
	o << h.hora << ":" << h.minuto;

	return o;
}
