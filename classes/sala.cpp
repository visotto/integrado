#include "../headers/sala.h"
//using namespace std;
Sala::Sala(int _numSala, int _capacidade, Situacao _situacao, int qtdAssentos)
{
  numSala = _numSala;
  capacidade = _capacidade;
  situacao = _situacao;

//	cout << "Construindo uma sala" << endl;

	fileiras = new Fileira*[capacidade];
	for (int i = 0; i < capacidade; i++)
	{
		fileiras[i] = new Fileira('A'+i, qtdAssentos);

/*		cout << "ID Da fileira " << i << " : " << fileiras[i]->getIdFileira() << endl;
		cout << "Assentos desta fileira:" << endl;
		for (int j = 0; j < qtdAssentos; j++)
			cout << fileiras[i]->getAssento(j)->getIdFileira() << fileiras[i]->getAssento(j)->getIdAssento() << endl;
*/	}
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

void Sala::setCapacidade(int capacidade)
{
  Sala::capacidade = capacidade;
}

int Sala::getCapacidade()
{
  return capacidade;
}

Fileira* Sala::getFileira(int idFileira)
{
	if (idFileira >= 0 && idFileira < capacidade) // transformar em tratamento de erro FUTURO
	{
		return fileiras[idFileira];
	}
}
