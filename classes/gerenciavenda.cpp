#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>

#include "../headers/gerenciavenda.h"

using namespace std;

GerenciaVenda::GerenciaVenda(GerenciaSessao *g) : gerencSala(g), gerencFilme(f)
{	
		
	int i, j;
	for (i = 0; i < MAX_SESSOES; i++)
		vendas[i] = NULL;
	qtdVendas = 0;

	// Variavel para leitura do arquivo
	ifstream leitura; 
	
	// Carrega o arquivo
	leitura.open("resources/vendas.data");	

	// Caso o arquivo nao seja aberto corretamente
	if(!leitura.is_open( )) 
	{
		leitura.clear( ); //reseta o objeto leitura, para limpar memória do sistema
		cout << "Nao foi possível abrir arquivo vendas.data!\n";
		return;	
	}

	// Variavel para leitura de cada linha do arquivo
	string leituraLinha;

	// Variaveis que sera passada para o construtor de cada sessao
	int _id, _idSessao;
	Sessao *_sessao;
	FormaPagto _formaPagto;
	Filme *_filme;
	string _string;
	Ingresos **ingressos;

	// Le do arquivo a quantidade de vendas armazenadas
	getline(leitura, leituraLinha);
  
	// Veririca se arquivo esta vazio
	if(leituraLinha != "")
	{
		//Temos agora uma string stream para processar a string leituraLinha;
		stringstream convertQtdVendas(leituraLinha);
		
		//Extrai o inteiro da string stream para a variável "qtdVendas"	  	 	    
		convertQtdVendas >> qtdVendas;

		int k = 0;
		// Enquanto tiver vendas armazenadas no arquivo
		while(k < qtdVendas){
			
			// Le do arquivo o numero da sala
			getline(leitura, leituraLinha);
			stringstream convertIdVenda(leituraLinha);  	 	    
  	 	    convertIdVenda >> _id;

			// Le do arquivo o numero da sessao
			getline(leitura, leituraLinha);
			stringstream convertIdSessao(leituraLinha);
			convertIdSessao >> _idSessao;

			// Le do arquivo o horario da sessao
			getline(leitura, leituraLinha);
			stringstream convertFormaPagto(leituraLinha);
			convertFormaPagto >> _formaPagto;

			// Le do arquivo o horario da sessao
			getline(leitura, leituraLinha);
			_tituloFilme = leituraLinha;



			sala = gerencSala->buscarSala(_idSala);

			// Aloca a sessao k armazenada no arquivo
			vendas[k] = new Venda(Sessao *_sessao, int _id ,FormaPagto _formaPagto);

			// Le os status dos assentos
			for(i = 0; i < vendas[k]->getSala()->getCapacidade(); i++){
				getline(leitura, leituraLinha);
				
				for(j = 0; j < vendas[k]->getSala()->getQtdAssentos(); j++){ //PILHA PILHA
					if(leituraLinha[j] == 'S')
						vendas[k]->getSala()->getFileira(i)->getAssento(j)->setDisponibilidade(false);
					else
						vendas[k]->getSala()->getFileira(i)->getAssento(j)->setDisponibilidade(true);
				}
			}
			k++;
		}
	}
	// Fecha o arquivo
	leitura.close();	
}

