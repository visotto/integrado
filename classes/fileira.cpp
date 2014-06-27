#include "../headers/Fileira.h"

Fileira::Fileira(char _idFileira, int qtdAssentos)
{
  idFileira = _idFileira;
  assentos = new Assento[qtdAssentos]; // alocacao dinamica para um vetor de assentos
  // o user que define qnts assentos tem naquela fileira

  // inicializa cada assento da fileira
  for (int i = 0; i < qtdAssentos; i++)
  {
    assentos[i]->setIdAssento(i+1); // de 1 ateh a qtd de assentos
    assentos[i]->setIdFileira(_idFileira); // inicializa todos os assentos de uma fileira com o id da fileira
  }
}

Fileira::Fileira(const Fileira &f)
{
  idFileira = f.idFileira;
}

Fileira::~Fileira()
{
  delete [] assentos;
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
