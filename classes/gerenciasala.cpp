#include <iostream>
#include <fstream>
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
	int numSala, capacidade, qtdAssentos, situacao;
	int i;

	if (qtdSalas < MAX_SALAS)
	{
		cout << "Digite o numero da sala: ";
		cin >> numSala;

		for (i = 0; i < qtdSalas; i++)
			if (numSala == salas[i]->getNumSala())
				throw "\nJa existe uma sala com este numero\n";

		cout << "Digite a capacidade da sala (quantidade de fileiras na sala): ";
		cin >> capacidade;
		cout << "Digite a quantidade de assentos em cada fileira: ";
		cin >> qtdAssentos;
		cout << "Digite a situacao da sala (disponivel = 0, manuEquipamento = 1, reforma = 2, manuGeral = 3): ";
		cin >> situacao;

		if (situacao < 0 || situacao > 3)
			throw "\nSituacao da sala invalida!\n";

		Situacao s = static_cast <Situacao> (situacao);
		salas[qtdSalas] = new Sala(numSala, capacidade, s, qtdAssentos);

		cout << "\nSala criada com sucesso!\n" << endl;
		qtdSalas++;

		// Chama funcao para escrever nova sala no arquivo salas.data
		escreverSala();
	}

	else
		throw "Nao ha espaco para criar novas salas!\n";
}

void GerenciaSala::removerSala()
{
	if (!qtdSalas)
		throw "\nNao existem salas cadastradas!\n";

	int id, i;
	cout << "Digite o id da sala que deseja remover: ";
	cin >> id;

	for (i = 0; i < qtdSalas; i++)
		if (salas[i]->getNumSala() == id)
		{
			qtdSalas--;
			*salas[i] = *salas[qtdSalas]; // movemos a ultima sala para o lugar da sala que foi removida
			salas[qtdSalas] = NULL; // e fazemos a ultima posicao apontar para null para evitar duplicacao
			cout << "\nSala removida com sucesso!\n" << endl;
			
			// Chama funcao para reescrever as salas atuais no arquivo salas.data
			reescreverSala();
			return;
		}

	throw "\nNao existe uma sala com este id!\n"; // so entra aqui se nao entrou no if e nao fez a remocao
}

void GerenciaSala::buscarSala()
{
	if (!qtdSalas)
		throw "\nNao existem salas cadastradas!\n";

	int id, i;
	cout << "Digite o id da sala que deseja buscar: ";
	cin >> id;

	for (i = 0; i < qtdSalas; i++)
		if (salas[i]->getNumSala() == id)
		{
			cout << "Sala " << id << ": " << endl;
			cout << "Capacidade da sala (quantidade de fileiras na sala): " << salas[i]->getCapacidade() << endl;
			cout << "Quantidade de assentos em cada fileira: " << salas[i]->getQtdAssentos() << endl;
			cout << "Situacao da sala: " << salas[i]->getSituacao() << endl;

			cout << "Relacao de assentos livres e ocupados:" << endl;
			cout << "     ";

			for (int j = 0; j < salas[i]->getQtdAssentos(); j++)
			{
				cout << j+1;

				// se j for 10 ou mais, alinhamos o texto com 1 espaco a menos
				j >= 9 ? cout << "  " : cout << "   ";
			}

			cout << endl << endl;

			for (int j = 0; j < salas[i]->getCapacidade(); j++)
			{
				cout << salas[i]->getFileira(j)->getIdFileira() << "    ";

				for (int k = 0; k < salas[i]->getQtdAssentos(); k++)
				{
					// assento disponivel? printe S, caso contrario printe N
					salas[i]->getFileira(j)->getAssento(k)->getDisponibilidade() ? cout << "S   " : cout << "N   ";
				}

				cout << endl;
			}
			cout << endl;
			return;
		}

	throw "\nNao existe uma sala com este id!\n"; // so entra aqui se nao encontrou a sala
}

void GerenciaSala::editarSala()
{
	if (!qtdSalas)
		throw "\nNao existem salas cadastradas!\n";

	int id, _situacao, i;
		
	cout << "Digite o id da sala que deseja atualizar: ";
	cin >> id;

	for (i = 0; i < qtdSalas; i++)
		if (salas[i]->getNumSala() == id)
		{
			cout << "Digite a nova situacao da sala (disponivel = 0, manuEquipamento = 1, reforma = 2, manuGeral = 3): ";
			cin >> _situacao;

			Situacao s = static_cast <Situacao> (_situacao);
			salas[i]->setSituacao(s);

			cout << "Situacao atualizada com sucesso" << endl;
		
			// Chama funcao para reescrever as salas atuais no arquivo salas.data
			reescreverSala();
			return;
		}

	throw "\nNao existe uma sala com este id!\n"; // so entra aqui se nao encontrou a sala
}

void GerenciaSala::escreverSala(){

	ofstream escreve; // Variavel para escrever no arquivo salas.data

	escreve.open("resources/salas.data", ios_base::app); // Comeca a escrever no final do arquivo
	
	// Escreve no arquivo salas.data
		escreve << "Numero da sala: " << salas[qtdSalas-1]->getNumSala() << "\n";
		escreve << "Capacidade da Sala: " << salas[qtdSalas-1]->getCapacidade() << "\n";
		escreve << "Quantidade de assentos em cada fileira: " << salas[qtdSalas-1]->getQtdAssentos() << "\n";
		escreve << "Situacao da sala: " << salas[qtdSalas-1]->getSituacao() << "\n";
		escreve << "------------------------------------------------------------------------------------ \n";

	escreve.close();	
}

void GerenciaSala::reescreverSala(){

	ofstream escreve; // Variavel para escrever no arquivo salas.data
	int i;

	escreve.open("resources/salas.data"); // Comeca a escrever no final do arquivo
	
	for(i = 0; i < qtdSalas; i++){
		
		// Escreve no arquivo salas.data
		escreve << "Numero da sala: " << salas[i]->getNumSala() << "\n";
		escreve << "Capacidade da Sala: " << salas[i]->getCapacidade() << "\n";
		escreve << "Quantidade de assentos em cada fileira: " << salas[i]->getQtdAssentos() << "\n";
		escreve << "Situacao da sala: " << salas[i]->getSituacao() << "\n";
		escreve << "------------------------------------------------------------------------------------ \n";

	}
	escreve.close();	
}