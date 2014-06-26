#ifndef ASSENTO_H
#define ASSENTO_H

#include <iostream>

class Assento
{
  private:
    int idAssento;
    bool disponibilidade;
    char idFileira;	

  public:
    Assento(int _idAssento, bool _disponibilidade, char _idFileira);
    Assento(const Assento &a);
    bool verificaDisponibilidade();
};

#endif // ASSENTO_H
