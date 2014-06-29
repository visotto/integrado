#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../headers/gerenciafilme.h"

using namespace std;

GerenciaFilme::GerenciaFilme()
{	
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
			filmes.insere(filmes.getEndRaiz(), Filme(_tituloFilme, _fxEtaria, _idioma));
			getline(leitura,leituraLinha);
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

		// apenas para usar na funcao busca
		Filme compara(tituloFilme, 0, '0');		

		try
		{
			filmes.busca(filmes.getRaiz(), compara); // aqui ira ocorrer excecao se nao ha filme com o titulo buscado, entao podemos criar
			cout << "\nJa existe um filme com esse titulo!\n";
		}

		// caso nao haja filme com este titulo
		catch (char const *s)
		{
			cout << "Digite a faixa etaria do filme: ";
			cin >> fxEtaria;			
			if(fxEtaria < 0 || fxEtaria > 18)
				throw "\nFaixa etaria invalida!\n";
		
			cout << "Digite o idioma do filme (L=legendado, D=dublado, N=nacional): ";
			cin >> idioma;
			if(idioma != 'L' && idioma != 'D' && idioma != 'N')
				throw "\nIdioma invalido!\n";

			filmes.insere(filmes.getEndRaiz(), Filme(tituloFilme, fxEtaria, idioma));

			cout << "\nFilme criado com sucesso!\n" << endl;
			qtdFilmes++;
		}

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

	// apenas para usar na funcao busca
	Filme compara(id, 0, '0');

	try
	{
		compara = filmes.busca(filmes.getRaiz(), compara); // aqui ira ocorrer excecao se nao ha filme com o titulo buscado
		filmes.setRaiz(filmes.remove(filmes.getRaiz(), compara));
		cout << "\nFilme removido com sucesso!\n" << endl;
		qtdFilmes--;

		// Chama funcao para reescrever os filmes atuais no arquivo filmes.data
		escreverFilme();
	}
	catch(...)
	{
		throw "\nNao existe um filme com este titulo!\n";
	}
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

	// apenas para usar na funcao busca
	Filme compara(id, 0, '0');

	try
	{
		compara = filmes.busca(filmes.getRaiz(), compara); // aqui ira ocorrer excecao se nao ha filme com o titulo buscado
		cout << compara << endl;
	}
	catch(...)
	{
		throw "\nNao existe um filme com este titulo!\n";
	}
}

Filme* GerenciaFilme::buscarFilme(string _tituloFilme)
{
	if (!qtdFilmes)
		throw "\nNao existem filmes cadastrados!\n";

	// apenas para usar na funcao busca
	Filme compara(_tituloFilme, 0, '0');

	try
	{
		Filme *novo = new Filme(" ", 0, '0');
		*novo = filmes.busca(filmes.getRaiz(), compara); // aqui ira ocorrer excecao se nao ha filme com o titulo buscado
		return novo;
	}
	catch(...)
	{
		throw "\nNao existe um filme com este titulo!\n";
	}
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
	cin.ignore();
	getline(cin, id);

	// apenas para usar na funcao busca
	Filme compara(id, 0, '0');

	try
	{
		compara = filmes.busca(filmes.getRaiz(), compara); // aqui ira ocorrer excecao se nao ha filme com o titulo buscado
		filmes.setRaiz(filmes.remove(filmes.getRaiz(), compara));
		cout << "Digite a nova faixa etaria do filme: ";
		cin >> fxEtaria;
		if(fxEtaria < 0 || fxEtaria > 18)
			throw "\nFaixa etaria invalida!\n";
		cout << "Digite o novo idioma do filme: ";
		cin >> idioma;
		if(idioma != 'L' && idioma != 'D' && idioma != 'N')
			throw "\nIdioma invalido!\n";
		filmes.insere(filmes.getEndRaiz(), Filme(compara.getTituloFilme(), fxEtaria, idioma));
		cout << "Filme editado com sucesso!" << endl;

		// Chama funcao para escrever novo filme no arquivo filmes.data
		escreverFilme();
	}
	catch(...)
	{
		throw "\nNao existe um filme com este titulo!\n";
	}
}

void GerenciaFilme::listarFilmes()
{
	if (!qtdFilmes)
		throw "\nNao existem filmes cadastrados!\n";

	cout << "Lista de filmes cadastrados:" << endl;
	filmes.listar(cout, filmes.getRaiz());

}

void GerenciaFilme::escreverFilme(){

	ofstream escreve; // Variavel para escrever no arquivo Filmes.data
	int i;

	escreve.open("resources/filmes.data"); // Comeca a escrever no inicio do arquivo
	
	char aux; // Variavel para gravar o valor de qtdFilmes no arquivo para leituras futuras
	
	escreve << qtdFilmes << "\n";

	// escreve os filmes no arquivo
	filmes.listar(escreve, filmes.getRaiz());
	escreve.close();	
}
