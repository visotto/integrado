#include "../headers/gerenciasala.h"

using namespace std;

GerenciaSala::GerenciaSala()
{
	qtdSalas = 0;
	salas[0] = NULL;
}

bool GerenciaSala::criarSala()
{
	int capacidade, qtdAssentos, situacao;

	// trocar o IF ELSE externo por tratamento de excecao
	if (qtdSalas >= 0 && qtdSalas < MAX_SALAS)
	{
		cout << "Digite a capacidade da sala (quantidade de fileiras na sala): ";
		cin >> capacidade;
		cout << "Digite a quantidade de assentos em cada fileira: ";
		cin >> qtdAssentos;
		cout << "Digite a situacao da sala (disponivel = 0, manuEquipamento = 1, reforma = 2, manuGeral = 3): ";
		cin >> situacao;

		Situacao s = static_cast <Situacao> (situacao);

		try
		{
			salas[qtdSalas] = new Sala(qtdSalas+1, capacidade, s, qtdAssentos);
			cout << "\nSala criada com sucesso!\n" << endl;
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

void GerenciaSala::buscarSala()
{

}

void GerenciaSala::editarSala()
{

}