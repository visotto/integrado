#include "../headers/venda.h"

using std::cout;
using std::endl;

Venda::Venda(Sessao *_sessao, int _id ,FormaPagto _formaPagto)
{
	id = _id;
	sessao = _sessao;
	formaPagto = _formaPagto;

	cout << "Contruindo uma venda" << endl;

	ingressos = new Ingresso*[MAX_INGRESSOS];

	for (int i = 0; i < MAX_INGRESSOS; i++)
		ingressos[i] = NULL;

	qtdIngressos = 0;
}

Venda::~Venda()
{
	delete [] ingressos;
}

double Venda::calcularValorTotal()
{
	double total = 0;

	for (int i = 0; i < MAX_INGRESSOS; i++)
		if (ingressos[i] != NULL)
			total += ingressos[i]->getValor();

	// set
	valorTotal = total;

	// get
	return total;
}

void Venda::emitirIngresso(Ingresso *ingresso)
{
	cout << "Emitindo ingresso..." << endl;
	cout << "======================" << endl;
	cout << "| Horario:\t" << ingresso->getHorario() << endl;
    cout << "| Valor:\t" << ingresso->getValor() << endl;
    cout << "| Tipo:\t" << ingresso->getTipo() << endl;
	cout << "| Poltrona:\t" << ingresso->getAssento()->getIdFileira() << ingresso->getAssento()->getIdAssento() << endl;
	cout << "======================" << endl;
			 					
}

void Venda::addIngresso(Ingresso *ingresso)
{
	if (qtdIngressos < MAX_INGRESSOS)
	{
//VENDE UM INGRESSO
		for (int i = 0; i < MAX_INGRESSOS; i++)
		{
			if (ingressos[i] == NULL)
			{
				ingressos[i] = ingresso; // Associa um ingresso a esta venda
				ingressos[i]->venda(); // altera a disponibilidade do assento para indisponivel e o status do ingresso para vendido
				qtdIngressos++;	// incrementa o numero de ingressos vendidos nesta venda
				sessao->incNumVendido('+'); // incrementa o numero de ingressos vendido na sessao relativa a esta venda
				cout << "ingresso vendido na poltrona " << ingressos[i]->getAssento()->getIdFileira() << ingressos[i]->getAssento()->getIdAssento() << endl;
				return;
			}
		}
	}
	else
		cout << "Maximo de ingressos atingido!" << endl;
}

void Venda::removeIngresso(Ingresso *ingresso)
{
	for (int i = 0; i < qtdIngressos; i++)
		if (ingressos[i] == ingresso && ingressos[i]->isVendido()) // se o ingresso buscado foi vendido
		{
			ingressos[i]->cancela();
			ingressos[i] = NULL;
			qtdIngressos--;
			sessao->incNumVendido('-');
			return;
		}

	// so chegamos neste cout se nao encontrarmos o ingresso, ou se ele nao foi vendido
	cout << "Este ingresso ainda nao foi vendido!" << endl;
}

int getQueryID(){
	return id;
}
