#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>

#include "../headers/gerenciasala.h"

using namespace std;

GerenciaSala::GerenciaSala()
{	
		
	int i, j;
	for (i = 0; i < MAX_SALAS; i++)
		salas[i] = NULL;
	qtdSalas = 0;

	// Variavel para leitura do arquivo
	ifstream leitura; 
	
	// Carrega o arquivo
	leitura.open("resources/salas.data");	

	// Caso o arquivo nao seja aberto corretamente
	if(!leitura.is_open( )) 
	{
		leitura.clear( ); //reseta o objeto leitura, para limpar memória do sistema
		cout << "Nao foi possível abrir arquivo sala.data!\n";
		return;	
	}

	// Variavel para leitura de cada linha do arquivo
	string leituraLinha;

	// Variaveis que sera passada para o construtor de cada sala
	int _capacidade, _qtdAssentos, _numSala;
	string _situacao;
	Situacao s;	

	// Le do arquivo a quantidade de salas armazenadas
	getline(leitura, leituraLinha);

  
	// Veririca se arquivo esta vazio
	if(leituraLinha != "")
	{
		//Temos agora uma string stream para processar a string leituraLinha;
		stringstream convertQtdSalas(leituraLinha);
		
		//Extrai o inteiro da string stream para a variável "qtdSalas"	  	 	    
		convertQtdSalas >> qtdSalas;

		int k = 0;
		// Enquanto tiver salas armazenadas no arquivo
		while(k < qtdSalas){
			
			// Le do arquivo o numero da sala
			getline(leitura, leituraLinha);
			stringstream convertNumSala(leituraLinha);  	 	    
  	 	    convertNumSala >> _numSala;

			// Le do arquivo a capacidade da sala
			getline(leitura, leituraLinha);
			stringstream convertCapacidade(leituraLinha);
			convertCapacidade >> _capacidade;

			// Le do arquivo a quantidade de assentos
			getline(leitura, leituraLinha);
			stringstream convertQtdAssentos(leituraLinha);
			convertQtdAssentos >> _qtdAssentos;
			
			// Le do arquivo a situacao da sala
			getline(leitura, leituraLinha);
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
			
		    if(_situacao == "alocada")
		 	  s = alocada;
		

			// Aloca a sala k armazenada no arquivo
			salas[k] = new Sala(_numSala, _capacidade, s, _qtdAssentos);

			// Le os status dos assentos
			for(i = 0; i < _capacidade; i++){
				getline(leitura, leituraLinha);
				
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
	// Fecha o arquivo
	leitura.close();	

	
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
				throw "\nJa existe uma sala com este numero!\n";

		cout << "Digite a capacidade da sala (quantidade de fileiras na sala - max 26): ";
		cin >> capacidade;
		if (capacidade < 0 || capacidade > 26)
			throw "\nCapacidade invalida!\n";
		cout << "Digite a quantidade de assentos em cada fileira: ";
		cin >> qtdAssentos;
		cout << "Digite a situacao da sala (disponivel = 0, manuEquipamento = 1, reforma = 2, manuGeral = 3, alocada = 4): ";
		cin >> situacao;

		if (situacao < 0 || situacao > 4)
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

Sala* GerenciaSala::buscarSala(int _id)
{
	if (!qtdSalas)
		throw "\nNao existem salas cadastradas!\n";

	int i;
	
	for (i = 0; i < qtdSalas; i++)
		if (salas[i]->getNumSala() == _id)
		{
			return salas[i];
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
			cout << "Digite a nova situacao da sala (disponivel = 0, manuEquipamento = 1, reforma = 2, manuGeral = 3, alocada = 4): ";
			cin >> _situacao;

			if (_situacao < 0 || _situacao > 4)
				throw "\nSituacao da sala invalida!\n";
			
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
	
	escreve << qtdSalas << "\n";
	for(i = 0; i < qtdSalas && salas[i] != NULL; i++){
		
		// Escreve no arquivo salas.data
		escreve << salas[i]->getNumSala() << "\n";
		escreve << salas[i]->getCapacidade() << "\n";
		escreve << salas[i]->getQtdAssentos() << "\n";
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
