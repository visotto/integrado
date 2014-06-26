#include "../headers/Fileira.h"

Fileira::Fileira(int _idFileira)
{
  idFileira = _idFileira;
}

Fileira::Fileira(const Fileira &f)
{
  idFileira = f.idFileira;
}

bool Fileira::verificaDisponibilidade()
{
  Assento* i = assentos; // i aponta para vetor de assentos, posicao 0

  while (i != NULL) // percorra todos assentos e veja se existe ao menos um livre
  {
    if (i->verificaDisponibilidade() == true)
      return true;

    i++;
  }

  return false;
}
