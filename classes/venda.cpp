#include "../headers/venda.h"

Venda(Date _dtVenda, double _valorTotal, FormaPagto _formaPagto)
{
  dtVenda = _dtVenda;
  valorTotal = _valorTotal;
  formaPagto = _formaPagto;

	ingressos = new Ingresso*[MAX_INGRESSOS];

	for (int i = 0; i < MAX_INGRESSOS; i++)
		ingressos[i] = NULL;

	qtdIngressos = 0;
}

Venda(const Venda &v)
{
  dtVenda = v.dtVenda;
  valorTotal = v.valorTotal;
  formaPagto = v.formaPagto;
}

double Venda::calcularValorTotal()
{
	double total = 0;

	for (int i = 0; i < MAX_INGRESSOS; i++)
		if (ingressos[i] != NULL)
			total += ingressos[i]->getValor();

	return total;
}

void Venda::emitirIngresso( ingresso)
{

}

void Venda::addIngresso(Ingresso ingresso)
{
	if (qtdIngressos < MAX_INGRESSOS)
	{
		for (int i = 0; i < MAX_INGRESSOS; i++)
		{
			if (ingressos[i] == NULL)
			{
				Ingresso *novo = new Ingresso;
				*novo = ingresso;
				ingressos[i] = novo;
				qtdIngressos++;
				
			}
		}
	}
	else
		cout << "Maximo de ingressos atingido!" << endl;
}

void Venda::removeIngresso(Ingresso ingresso)
{
	if (qtdIngressos)
	{
		 
	}
	else
		cout << "Nao existem ingressos!" << endl;
}
