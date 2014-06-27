#include "../headers/Sala.h"

Sala(int _numSala, int _capacidade, Situacao _situacao, int qtdFileiras, int qtdAssentos)
{
  numSala = _numSala;
  capacidade = _capacidade;
  situacao = _situacao;

  fileiras = new Fileira[qtdFileiras];

  // inicializa todas as fileiras e as suas cadeiras
  // inicializa cada fileira
  for (int i = 0; i < qtdFileiras; i++)
  {
     fileiras[i]->setIdFileira(i+1); // de 1 ateh a qtd de fileira

     fileiras[i]->assentos = new Assento[qtdAssentos]; // alocacao dinamica para um vetor de assentos
    // o user que define qnts assentos tem naquela fileira

    // inicializa cada assento da fileira i
    for (int j = 0; i < qtdAssentos; i++)
    {
      fileiras[i]->assentos[j]->setIdAssento(i+1); // de 1 ateh a qtd de assentos
      fileiras[i]->assentos[j]->setIdFileira(idFileira); // inicializa todos os assentos de uma fileira com o id da fileira
    }
  }
}

Sala(const Sala &s)
{
  numSala = s.numSala;
  capacidade = s.capacidade;
  situacao = s.situacao;
}

int Sala::getNumSala()
{
  return numSala;
}

void Sala::setNumSala(int numSala)
{
  Sala::numSala = numSala;
}

void Sala::setCapacidade(int capacidade)
{
  Sala::capacidade = capacidade;
}

int Sala::getCapacidade()
{
  return capacidade;
}
