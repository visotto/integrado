#ifndef FILEIRA_H
#define FILEIRA_H

#include <iostream>
#include "../headers/Assento.h"

class Fileira
{
  private:
    char idFileira;
    Assento *assentos; // vetor de assentos

  public:
    Fileira(char _idFileira, int qtdAssentos);
    Fileira(const Fileira &f);
    bool verificaDisponibilidade();

};

#endif // FILEIRA_H
