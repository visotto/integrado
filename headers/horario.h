#ifndef HORARIO_H
#define HORARIO_H

#include <iostream>
#include <sstream> // stringstream

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
    Horario(int h = 0, int m = 0) : hora(h), minuto(m) {}; // construtor
    Horario(const Horario &h); // construtor de copia
    int getHora();
    int getMinuto();
};

#endif // HORARIO_H
