#include "../headers/gerenciasala.h"

using namespace std;

GerenciaSala::GerenciaSala()
{
	qtdSalas = 0;

	for (int i = 0; i < MAX_SALAS; i++)
		salas[i] = NULL;
}

void GerenciaSala::criarSala()
{
	int capacidade, qtdAssentos, situacao;

	if (qtdSalas < MAX_SALAS)
	{
		cout << "Digite a capacidade da sala (quantidade de fileiras na sala): ";
		cin >> capacidade;
		cout << "Digite a quantidade de assentos em cada fileira: ";
		cin >> qtdAssentos;
		cout << "Digite a situacao da sala (disponivel = 0, manuEquipamento = 1, reforma = 2, manuGeral = 3): ";
		cin >> situacao;

		if (situacao < 0 || situacao > 3)
			throw "\nSituacao da sala invalida!\n";

		Situacao s = static_cast <Situacao> (situacao);
		salas[qtdSalas] = new Sala(qtdSalas+1, capacidade, s, qtdAssentos);

		cout << "\nSala criada com sucesso!\n" << endl;
		qtdSalas++;
	}

	else
		throw "Nao ha espaco para criar novas salas!\n";
}

void GerenciaSala::removerSala()
{
	if (!qtdSalas)
		throw "\nNao existem salas cadastradas!\n";

	int id;
	cout << "Digite o id da sala que deseja remover: ";
	cin >> id;

	if (id > 0 && id <= MAX_SALAS && salas[id-1] != NULL)
	{
		qtdSalas--;
		*salas[id-1] = *salas[qtdSalas]; // movemos a ultima sala para o lugar da sala que foi removida
		salas[qtdSalas] = NULL; // e fazemos a ultima posicao apontar para null para evitar duplicacao
		cout << "\nSala removida com sucesso!\n" << endl;
	}

	else
		throw "\nNao existe uma sala com este id!\n";
}

void GerenciaSala::buscarSala()
{
	int id;
	cout << "Digite o id da sala que deseja buscar: ";
	cin >> id;

	if (id > 0 && id <= qtdSalas)
	{
		cout << "Sala " << id << ": " << endl;
		cout << "Capacidade da sala (quantidade de fileiras na sala): " << salas[id-1]->getCapacidade() << endl;
		cout << "Quantidade de assentos em cada fileira: " << salas[id-1]->getQtdAssentos() << endl;
		cout << "Situacao da sala: " << salas[id-1]->getSituacao() << endl;

		cout << "Relacao de assentos livres e ocupados:" << endl;
		cout << "     ";

		for (int i = 0; i < salas[id-1]->getQtdAssentos(); i++)
		{
			cout << i+1;

			// se i for 10 ou mais, alinhamos o texto com 1 espaco a menos
			i >= 9 ? cout << "  " : cout << "   ";
		}

		cout << endl << endl;

		for (int i = 0; i < salas[id-1]->getCapacidade(); i++)
		{
			cout << salas[id-1]->getFileira(i)->getIdFileira() << "    ";

			for (int j = 0; j < salas[id-1]->getQtdAssentos(); j++)
			{
				// assento disponivel? printe S, caso contrario printe N
				salas[id-1]->getFileira(i)->getAssento(j)->getDisponibilidade() ? cout << "S   " : cout << "N   ";
			}

			cout << endl;
		}
		cout << endl;
	}

	else
		throw "\nNao existe uma sala com este id!\n";
}

void GerenciaSala::editarSala()
{
	int id, _situacao;
		
	cout << "Digite o id da sala que deseja atualizar: ";
	cin >> id;

	if (id > 0 && id <= qtdSalas)
	{
		cout << "Digite a nova situacao da sala (disponivel = 0, manuEquipamento = 1, reforma = 2, manuGeral = 3): ";
		cin >> _situacao;

		Situacao s = static_cast <Situacao> (_situacao);
		salas[id-1]->setSituacao(s);

		cout << "Situacao atualizada com sucesso" << endl;
	}

	else
		throw "\nNao existe uma sala com este id!\n";
}
