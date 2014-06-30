#include "../headers/fileira.h"

Fileira::Fileira(char _idFileira, int _qtdAssentos)
{
  idFileira = _idFileira;
	qtdAssentos = _qtdAssentos;

  assentos = new Assento*[qtdAssentos]; // alocacao dinamica para um vetor de ponteiros para assentos
																			  // o user define qnts assentos tem naquela fileira

  // aloca cada assento da fileira
  for (int i = 0; i < qtdAssentos; i++)
		assentos[i] = new Assento(i+1, true, _idFileira);
}

Fileira::~Fileira()
{
	for (int i = 0; i < qtdAssentos; i++)
			delete assentos[i];

  delete [] assentos;
}

bool Fileira::verificaDisponibilidade()
{
  Assento** i = assentos; // i aponta para vetor de assentos, posicao 0

  while (*i != NULL) // percorra todos assentos e veja se existe ao menos um livre
  {
    if ((*i)->getDisponibilidade() == true)
      return true;

    (*i)++;
  }

  return false;
}

char Fileira::getIdFileira()
{
	return idFileira;
}

Assento* Fileira::getAssento(int idAssento)
{
	if (idAssento >= 0 && idAssento < qtdAssentos)
	{
		return assentos[idAssento];
	}
  else
    return NULL;
}

void Fileira::setIdFileira(int _idFileira)
{
	idFileira = _idFileira;
}
