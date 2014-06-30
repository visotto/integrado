#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>

#include "../headers/gerenciasessao.h"

using namespace std;

GerenciaSessao::GerenciaSessao(GerenciaSala *g, GerenciaFilme *f) : gerencSala(g), gerencFilme(f)
{	
		
	int i, j;
	for (i = 0; i < MAX_SESSOES; i++)
		sessoes[i] = NULL;
	qtdSessoes = 0;

	// Variavel para leitura do arquivo
	ifstream leitura; 
	
	// Carrega o arquivo
	leitura.open("resources/sessoes.data");	

	// Caso o arquivo nao seja aberto corretamente
	if(!leitura.is_open( )) 
	{
		leitura.clear( ); //reseta o objeto leitura, para limpar memória do sistema
		cout << "Nao foi possível abrir arquivo sessoes.data!\n";
		return;	
	}

	// Variavel para leitura de cada linha do arquivo
	string leituraLinha;

	// Variaveis que sera passada para o construtor de cada sessao
	int _idSala, _idSessao, _numSala;
	Horario _horario;
	string _tituloFilme;
	Sala *sala;
	Filme *filme;

	// Le do arquivo a quantidade de sessoes armazenadas
	getline(leitura, leituraLinha);
  
	// Veririfica se o arquivo esta vazio
	if(leituraLinha != "")
	{
		//Temos agora uma string stream para processar a string leituraLinha;
		stringstream convertQtdSessoes(leituraLinha);
		
		//Extrai o inteiro da string stream para a variável "qtdSessoes"	  	 	    
		convertQtdSessoes >> qtdSessoes;

		int k = 0;
		// Enquanto tiver sessoes armazenadas no arquivo
		while(k < qtdSessoes){
			
			// Le do arquivo o numero da sala
			getline(leitura, leituraLinha);
			stringstream convertIdSala(leituraLinha);  	 	    
  	 	    convertIdSala >> _idSala;

			// Le do arquivo o numero da sessao
			getline(leitura, leituraLinha);
			stringstream convertIdSessao(leituraLinha);
			convertIdSessao >> _idSessao;

			// Le do arquivo o horario da sessao
			getline(leitura, leituraLinha);
			stringstream convertHorario(leituraLinha);
			convertHorario >> _horario;				

			// Le do arquivo o titulo do filme da sessao
			getline(leitura, leituraLinha);
			_tituloFilme = leituraLinha;


			sala = gerencSala->buscarSala(_idSala);

			filme = gerencFilme->buscarFilme(_tituloFilme);

			// Aloca a sessao k armazenada no arquivo
			sessoes[k] = new Sessao(sala, _idSessao, _horario, filme);

			// Le os status dos assentos
			for(i = 0; i < sessoes[k]->getSala()->getCapacidade(); i++){
				getline(leitura, leituraLinha);
				
				for(j = 0; j < sessoes[k]->getSala()->getQtdAssentos(); j++){
					if(leituraLinha[j] == 'S')
						sessoes[k]->getSala()->getFileira(i)->getAssento(j)->setDisponibilidade(false);
					else
						sessoes[k]->getSala()->getFileira(i)->getAssento(j)->setDisponibilidade(true);
				}
			}
			k++;
		}
	}
	// Fecha o arquivo
	leitura.close();	
}

void GerenciaSessao::criarSessao()
{

	Sala *_sala;
	int _numSala;
	Filme *_filme;
	string _tituloFilme;
	int _id;
	Horario _horario;
	int i;

	if (qtdSessoes < MAX_SESSOES)
	{
		cout << "Digite o numero da sessao: ";
		cin >> _id;
		cout << "Digite o horario para essa sessao (HH:MM): ";
		cin >> _horario;

		if (_horario.getHora() < 0 || _horario.getHora() > 23 || _horario.getMinuto() < 0 || _horario.getMinuto() > 59)
			throw "\nHorario invalido!\n";

		cout << "Digite o numero da sala para essa sessao: ";
		cin >> _numSala;
		_sala = gerencSala->buscarSala(_numSala);
		_sala->setSituacao(alocada);

		cout << "Digite o titulo do filme a associar a essa sessao: ";
		cin.ignore();
		getline(cin, _tituloFilme);
		_filme = gerencFilme->buscarFilme(_tituloFilme);

		sessoes[qtdSessoes] = new Sessao(_sala, _id, _horario, _filme);

		cout << "\nSessao criada com sucesso!\n" << endl;
		qtdSessoes++;


		// Chama funcao para escrever nova sessao no arquivo sessoes.data
		escreverSessao();
	}

	else
		throw "Nao ha espaco para criar novas sessoes!\n";
}

void GerenciaSessao::removerSessao()
{
	if (!qtdSessoes)
		throw "\nNao existem sessoes cadastradas!\n";

	int id, i;
	cout << "Digite o id da sessao que deseja remover: ";
	cin >> id;

	for (i = 0; i < qtdSessoes; i++)
		if (sessoes[i]->getQueryID() == id)
		{
			qtdSessoes--;

			sessoes[i]->getSala()->setSituacao(disponivel);

			*sessoes[i] = *sessoes[qtdSessoes]; // movemos a ultima sessao para o lugar da sessao que foi removida
			sessoes[qtdSessoes] = NULL; // e fazemos a ultima posicao apontar para null para evitar duplicacao
			cout << "\nSessao removida com sucesso!\n" << endl;
			
			// Chama funcao para reescrever as sessoes atuais no arquivo sessoes.data
			escreverSessao();
			return;
		}

	throw "\nNao existe uma sessao com este id!\n"; // so entra aqui se nao entrou no if e nao fez a remocao
}

void GerenciaSessao::buscarSessao()
{
	if (!qtdSessoes)
		throw "\nNao existem sessoes cadastradas!\n";

	int id, i;
	cout << "Digite o id da sessao que deseja buscar: ";
	cin >> id;

	for (i = 0; i < qtdSessoes; i++)
		if (sessoes[i]->getQueryID() == id)
		{
			cout << "Sessao " << id << ": " << endl;
			cout << "Horario da sessao: " << sessoes[i]->getHorario() << endl;
			cout << "Sala da sessao: " << sessoes[i]->getSala()->getNumSala() << endl;
			cout << "Filme da sessao: " << sessoes[i]->getFilme()->getTituloFilme() << endl;

			cout << "Relacao de ingressos vendidos:" << endl;
			cout << "     ";

			for (int j = 0; j < sessoes[i]->getSala()->getQtdAssentos(); j++)
			{
				cout << j+1;

				// se j for 10 ou mais, alinhamos o texto com 1 espaco a menos
				j >= 9 ? cout << "  " : cout << "   ";
			}

			cout << endl << endl;

			for (int j = 0; j < sessoes[i]->getSala()->getCapacidade(); j++)
			{
				cout << sessoes[i]->getSala()->getFileira(j)->getIdFileira() << "    ";

				for (int k = 0; k < sessoes[i]->getSala()->getQtdAssentos(); k++)
				{
					// assento disponivel (isso implica no ingresso associado ahquele assento ter sido vendido)? printe S, caso contrario printe N
					sessoes[i]->getSala()->getFileira(j)->getAssento(k)->getDisponibilidade() ? cout << "N   " : cout << "S   ";
				}

				cout << endl;
			}
			cout << endl;
			return;
		}

	throw "\nNao existe uma sessao com este id!\n"; // so entra aqui se nao encontrou a sessao
}

Sessao* GerenciaSessao::buscarSessao(int id)
{
	if (!qtdSessoes)
		return NULL;

	for (int i = 0; i < qtdSessoes; i++)
		if (sessoes[i]->getQueryID() == id)
		{
			return sessoes[i];
		}

	return NULL;
}


void GerenciaSessao::editarSessao()
{
	if (!qtdSessoes)
		throw "\nNao existem sessoes cadastradas!\n";

	int id, _situacao, i, _numSala;
	string _tituloFilme;
	Horario _horario;
	Sala *sala;
	Filme *filme;
		
	cout << "Digite o id da sessao que deseja atualizar: ";
	cin >> id;

	for (i = 0; i < qtdSessoes; i++)
		if (sessoes[i]->getQueryID() == id)
		{
		cout << "Digite o novo horario para essa sessao (HH:MM): ";
		cin >> _horario;
	
		if (_horario.getHora() < 0 || _horario.getHora() > 23 || _horario.getMinuto() < 0 || _horario.getMinuto() > 59)
			throw "\nHorario invalido!\n";

		cout << "Digite o novo numero da sala para essa sessao: "; //alterar o status da sala para alocada
		cin >> _numSala;
		sessoes[i]->getSala()->setSituacao(disponivel);
		sala = gerencSala->buscarSala(_numSala);
		sessoes[i]->getSala()->setSituacao(alocada);

		cout << "Digite o novo titulo do filme associar a essa sessao: "; 
		cin.ignore();
		getline(cin, _tituloFilme);
		filme = gerencFilme->buscarFilme(_tituloFilme);

			cout << "Situacao atualizada com sucesso" << endl;
		
			// Chama funcao para reescrever as sessoes atuais no arquivo sessoes.data
			escreverSessao();
			return;
		}

	throw "\nNao existe uma sessao com este id!\n"; // so entra aqui se nao encontrou a sessao
}

void GerenciaSessao::escreverSessao(){

	ofstream escreve; // Variavel para escrever no arquivo sessoes.data
	int i;

	escreve.open("resources/sessoes.data"); // Comeca a escrever no inicio do arquivo
	
	char aux; // Variavel para gravar o valor de qtdSessoes no arquivo para leituras futuras
	
	escreve << qtdSessoes << "\n";
	for(i = 0; i < qtdSessoes && sessoes[i] != NULL; i++){
		
		// Escreve no arquivo sessoes.data
		escreve << sessoes[i]->getSala()->getNumSala() << "\n";
		escreve << sessoes[i]->getQueryID() << "\n";
		escreve << sessoes[i]->getHorario() << "\n";
		escreve << sessoes[i]->getFilme()->getTituloFilme() << "\n";
		
		for (int j = 0; j < sessoes[i]->getSala()->getCapacidade(); j++){	
			for (int k = 0; k < sessoes[i]->getSala()->getQtdAssentos(); k++)
				// assento disponivel? printe S, caso contrario printe N
				sessoes[i]->getSala()->getFileira(j)->getAssento(k)->getDisponibilidade() ? escreve << "N" : escreve << "S";
		escreve << "\n";
		}


	}
	escreve.close();	
}


