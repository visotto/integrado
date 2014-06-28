#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../headers/gerenciafilme.h"

using namespace std;

GerenciaFilme::GerenciaFilme()
{	
	int i;
	
	for (i = 0; i < MAX_FILMES; i++)
		filmes[i] = NULL;
	qtdFilmes = 0;

	// Variavel para leitura do arquivo
	ifstream leitura; 
	
	// Carrega o arquivo
	leitura.open("resources/filmes.data");	

	// Caso o arquivo nao seja aberto corretamente
	if(!leitura.is_open( )) 
	{
		leitura.clear( ); //reseta o objeto leitura, para limpar memória do sistema
		cout << "Nao foi possível abrir arquivo filmes.data!\n";
		return;	
	}

	// Variavel para leitura de cada linha do arquivo
	string leituraLinha;

	// Variaveis que sera passada para o construtor de cada filme
	int _qtdFilmes, _fxEtaria;
	string _tituloFilme;
	char _idioma;


	// Le do arquivo a quantidade de filmes armazenadas
	getline(leitura, leituraLinha);

	// Veririca se arquivo esta vazio
	if(leituraLinha != "")
	{
		//Temos agora uma string stream para processar a string leituraLinha;
		stringstream convertQtdFilmes(leituraLinha);
		
		//Extrai o inteiro da string stream para a variável "qtdFilmes"	  	 	    
		convertQtdFilmes >> qtdFilmes;
		
		int k = 0;
		// Enquanto tiver salas armazenadas no arquivo
		while(k < qtdFilmes){
	
		int _qtdFilmes, _fxEtaria;
		string _tituloFilme;
		char _idioma;

		
			// Le do arquivo o titulo do filme
			getline(leitura, leituraLinha);
			_tituloFilme = leituraLinha;				
 
			// Le do arquivo a faixa etaria do filme
			getline(leitura, leituraLinha);
			stringstream convertFxEtaria(leituraLinha);
			convertFxEtaria >> _fxEtaria;

			// Le do arquivo o idioma do filme
			getline(leitura, leituraLinha);
			_idioma = leituraLinha[0];
			
			// Aloca o filme k armazenado no arquivo
			filmes[k] = new Filme(_tituloFilme, _fxEtaria, _idioma);
			
			k++;
		}
	}
	// Fecha o arquivo
	leitura.close();	

}

void GerenciaFilme::criarFilme()
{
	string tituloFilme;
	int fxEtaria;
	char idioma;

	if (qtdFilmes < MAX_FILMES)
	{
		cout << "Digite o titulo do filme: ";
		cin.ignore();		
		getline(cin, tituloFilme);
		
		for (int i = 0; i < qtdFilmes; i++)
			if (tituloFilme.compare(filmes[i]->getTituloFilme()) == 0)
				throw "\nJa existe um filme com esse titulo!\n";

		cout << "Digite a faixa etaria do filme: ";
		cin >> fxEtaria;
		cout << "Digite o idioma do filme (L=legendado, D=dublado, N=nacional): ";
		cin >> idioma;

		filmes[qtdFilmes] = new Filme(tituloFilme, fxEtaria, idioma);

		cout << "\nFilme criado com sucesso!\n" << endl;
		qtdFilmes++;


		// Chama funcao para escrever novo filme no arquivo filmes.data
		escreverFilme();
	}

	else
		throw "Nao ha espaco para criar novos filmes!\n";
}

void GerenciaFilme::removerFilme()
{
	if (!qtdFilmes)
		throw "\nNao existem filmes cadastrados!\n";

	string id;
	int i;
	cout << "Digite o titulo do filme que deseja remover: ";
	cin.ignore();		
	getline(cin, id);
		
	for (i = 0; i < qtdFilmes; i++)
		if (id.compare(filmes[i]->getTituloFilme()) == 0)
		{
			qtdFilmes--;
			*filmes[i] = *filmes[qtdFilmes]; // movemos o ultimo filme para o lugar do filme que foi removido
			filmes[qtdFilmes] = NULL; // e fazemos a ultima posicao apontar para null para evitar duplicacao
			cout << "\nFilme removido com sucesso!\n" << endl;
			
			// Chama funcao para reescrever os filmes atuais no arquivo filmes.data
			escreverFilme();
			return;
		}

	throw "\nNao existe um filme com este titulo!\n"; // so entra aqui se nao entrou no if e nao fez a remocao
}

void GerenciaFilme::buscarFilme()
{
	if (!qtdFilmes)
		throw "\nNao existem filmes cadastrados!\n";

	string id;
	int i;
	cout << "Digite o titulo do filme que deseja buscar: ";
	cin.ignore();		
	getline(cin, id);
		
	for (i = 0; i < qtdFilmes; i++)
		if (id.compare(filmes[i]->getTituloFilme()) == 0)
		{
			cout << "Filme " << id << ": " << endl;
			cout << "Faixa etaria: " << filmes[i]->getFxEtaria() << endl;
			cout << "Idioma: " << filmes[i]->getIdioma() << endl;
			return;
		}

	throw "\nNao existe um filme com este titulo!\n"; // so entra aqui se nao encontrou o filme
}

void GerenciaFilme::editarFilme()
{
	if (!qtdFilmes)
		throw "\nNao existem filmes cadastrados!\n";

	string id;
	int i;
	int fxEtaria;
	char idioma;
		
	cout << "Digite o titulo do filme que deseja atualizar: ";
	cin >> id;

	for (i = 0; i < qtdFilmes; i++)
		if (id.compare(filmes[i]->getTituloFilme()) == 0)
		{
			cout << "Digite a nova faixa etaria do filme: ";
			cin >> fxEtaria;
			filmes[i]->setFxEtaria(fxEtaria);

			cout << "Digite o novo idioma do filme (L=legendado, D=dublado, N=nacional): ";
			cin >> idioma;
			filmes[i]->setIdioma(idioma);

			cout << "Filme atualizado com sucesso" << endl;
		
			// Chama funcao para reescrever os filmes atuais no arquivo filmes.data
			escreverFilme();
			return;
		}

	throw "\nNao existe um filme com este titulo!\n"; // so entra aqui se nao encontrou o filme
}

void GerenciaFilme::listarFilmes()
{
	cout << "Lista de filmes cadastrados" << endl;

	if (!qtdFilmes)
		throw "\nNao existem filmes cadastrados!\n";

	for (int i = 0; i < MAX_FILMES; i++)
		if (filmes[i] != NULL)
			cout << filmes[i]->getTituloFilme() << endl;

}

void GerenciaFilme::escreverFilme(){

	ofstream escreve; // Variavel para escrever no arquivo Filmes.data
	int i;

	escreve.open("resources/filmes.data"); // Comeca a escrever no inicio do arquivo
	
	char aux; // Variavel para gravar o valor de qtdFilmes no arquivo para leituras futuras
	
	escreve << qtdFilmes << "\n";
	for(i = 0; i < qtdFilmes && filmes[i] != NULL; i++){	
		// Escreve no arquivo filmes.data
		escreve << filmes[i]->getTituloFilme() << "\n";
		escreve << filmes[i]->getFxEtaria() << "\n";
		escreve << filmes[i]->getIdioma() << "\n";
	}

	escreve.close();	
}
