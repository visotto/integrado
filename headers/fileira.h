#ifndef FILEIRA_H
#define FILEIRA_H

#include <iostream>

class Fileira
{
  private:
    char idFileira;
    Assento *assentos; // vetor de assentos

  public:
    Fileira(char _idFileira);
    Fileira(const Fileira &f);
    bool verificaDisponibilidade();

};

#endif // FILEIRA_H
