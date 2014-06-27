#include <iostream>
#include <fstream>


#include "../headers/gerenciasala.h"

using namespace std;

GerenciaSala::GerenciaSala()
{	
	
	int i, j;
	for (i = 0; i < MAX_SALAS; i++)
		salas[i] = NULL;

	// Variavel para leitura do arquivo
	ifstream leitura; 

	// Carrega o arquivo
	leitura.open("resources/salas.data");	

	// Caso ocorra
	if(!leitura.is_open( )) 
	{
		leitura.clear( ); //reseta o objeto leitura, para limpar memória do sistema
		cout << "Não foi possível abrir arquivo!\n";
		return;
		
	}
	// Variavel para leitura de cada linha do arquivo
	char leituraLinha[100];

	// Variaveis que sera passada para o construtor de cada arquivo
	int k, _capacidade, _qtdAssentos, _numSala;
	string _situacao;
	Situacao s;	

	// Le do arquivo a quantidade de salas armazenadas
	leitura.getline(leituraLinha,100);
	qtdSalas = leituraLinha[0];

	k = 0;
	// Enquanto tiver salas armazenadas no arquivo
	while(k < qtdSalas){
		// Le do arquivo o numero da sala
		leitura.getline(leituraLinha,100);
		_numSala = leituraLinha[0];

		// Le do arquivo a capacidade da sala
		leitura.getline(leituraLinha,100);
		_capacidade = leituraLinha[0];

		// Le do arquivo a quantidade de assentos
		leitura.getline(leituraLinha,100);
		_qtdAssentos = leituraLinha[0];

		// Le do arquivo a situacao da sala
		leitura.getline(leituraLinha,100);
		_situacao = leituraLinha;

		// Converte a string lida para tipo situacao
		if(_situacao == "disponivel")
			s = disponivel;
			
		if(_situacao == "manuEquipamento")
			s = manuEquipamento;
		
		if(_situacao == "reforma")
			s = reforma;
		
		if(_situacao == "manuGeral")
			s = manuGeral;
	

		// Aloca a classe armazenada no arquivo
		salas[k] = new Sala(_numSala, _capacidade, s, _qtdAssentos);

		// Le os status dos assentos
		for(i = 0; i < _capacidade; i++){
			leitura.getline(leituraLinha,100);
			
			for(j = 0; j < _qtdAssentos; j++){
				if(leituraLinha[j] == 'S')
					salas[k]->getFileira(i)->getAssento(j)->setDisponibilidade(true);
				else
					salas[k]->getFileira(i)->getAssento(j)->setDisponibilidade(false);
			}
		}

		k++;
	}
	
	
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
			escreverSala();
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
			escreverSala();
			return;
		}

	throw "\nNao existe uma sala com este id!\n"; // so entra aqui se nao encontrou a sala
}

void GerenciaSala::escreverSala(){

	ofstream escreve; // Variavel para escrever no arquivo salas.data
	int i;

	escreve.open("resources/salas.data"); // Comeca a escrever no inicio do arquivo
	
	char aux; // Variavel para gravar o valor de qtdSalas no arquivo para leituras futuras
	
	escreve << (char)qtdSalas << "\n";
	for(i = 0; i < qtdSalas && salas[i] != NULL; i++){
		
		// Escreve no arquivo salas.data
		escreve << (char)salas[i]->getNumSala() << "\n";
		escreve << (char)salas[i]->getCapacidade() << "\n";
		escreve << (char)salas[i]->getQtdAssentos() << "\n";
		escreve << salas[i]->getSituacao() << "\n";
		
		for (int j = 0; j < salas[i]->getCapacidade(); j++){	
			for (int k = 0; k < salas[i]->getQtdAssentos(); k++)
				// assento disponivel? printe S, caso contrario printe N
				salas[i]->getFileira(j)->getAssento(k)->getDisponibilidade() ? escreve << "S" : escreve << "N";
		escreve << "\n";
		}


	}
	escreve.close();	
}