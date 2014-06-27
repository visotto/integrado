#include "../headers/sala.h"
//using namespace std;
Sala::Sala(int _numSala, int _capacidade, Situacao _situacao, int _qtdAssentos)
{
  numSala = _numSala;
  capacidade = _capacidade;
  situacao = _situacao;
  qtdAssentos = _qtdAssentos;

	fileiras = new Fileira*[capacidade];
	for (int i = 0; i < capacidade; i++)
		fileiras[i] = new Fileira('A'+i, qtdAssentos);
}

Sala::Sala(const Sala &s)
{
  numSala = s.numSala;
  capacidade = s.capacidade;
  situacao = s.situacao;
}

Sala::~Sala()
{
	for (int i = 0; i < capacidade; i++)
		if (fileiras[i] != NULL)
			delete fileiras[i];

  delete [] fileiras;
}

int Sala::getNumSala()
{
  return numSala;
}

void Sala::setNumSala(int numSala)
{
  Sala::numSala = numSala;
}

int Sala::getQtdAssentos()
{
	return qtdAssentos;
}

std::string Sala::getSituacao()
{
	switch (situacao)
	{
		case disponivel:
			return "disponivel";

		case manuEquipamento:
			return "manuEquipamento";

		case reforma:
			return "reforma";

		case manuGeral:
			return "manuGeral";
	}
}

void Sala::setCapacidade(int capacidade)
{
  Sala::capacidade = capacidade;
}

int Sala::getCapacidade()
{
  return capacidade;
}

void Sala::setSituacao(Situacao _situacao){
	situacao = _situacao;
}

Fileira* Sala::getFileira(int idFileira)
{
	if (idFileira >= 0 && idFileira < capacidade) // transformar em tratamento de erro FUTURO
	{
		return fileiras[idFileira];
	}
}

