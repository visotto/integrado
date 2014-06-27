#include "../headers/gerenciasala.h"

using namespace std;

GerenciaSala::GerenciaSala()
{
	qtdSalas = 0;
	salas[0] = NULL;
}

bool GerenciaSala::criarSala()
{
	int capacidade, qtdAssentos;
	Situacao situacao;

	// trocar o IF ELSE externo por tratamento de excecao
	if (qtdSalas >= 0 && qtdSalas < MAX_SALAS)
	{
		cout << "Digite a capacidade da sala (quantidade de fileiras na sala): ";
		cin >> capacidade;
		cout << "Digite a quantidade de assentos em cada fileira: ";
		cin >> qtdAssentos;
		cout << "Digite a situacao da sala (disponivel, manuEquipamento, reforma, manuGeral): ";
		cin >> situacao;

		try
		{
			salas[qtdSalas] = new Sala(qtdSalas+1, capacidade, situacao, qtdAssentos);
			cout << "Sala criada com sucesso!" << endl;
			qtdSalas++;
		}

		catch (...)
		{
			cout << "Falha na alocacao!" << endl;
		}
	}

	else
	{
		cout << "Nao ha espaco para criar novas salas!" << endl;
	}
}

bool GerenciaSala::removerSala()
{

}

bool GerenciaSala::buscarSala()
{

}

bool GerenciaSala::editarSala()
{

}
