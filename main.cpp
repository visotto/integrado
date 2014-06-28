#include <iostream>
#include "headers/gerenciasala.h"
#include "headers/gerenciafilme.h"
using std::cout;
using std::cin;
using std::string;
using std::endl;

void gerenciadorDeSalas(GerenciaSala &g)
{
	int opcao;

	while (1)
	{
		cout << "Escolha uma opcao:" << endl;
		cout << "0. Voltar para o Menu anterior" << endl;
		cout << "1. Criar Sala" << endl;
		cout << "2. Remover Sala" << endl;
		cout << "3. Buscar Sala" << endl;
		cout << "4. Editar Sala" << endl;
		cin >> opcao;

		switch (opcao){
		  case 0:
			return;

		  case 1:
				try
				{
			  		g.criarSala();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

				catch(...)
				{
					cout << "\nUm erro ocorreu ao adicionar a sala!" << endl;
				}

			    break;

		  case 2:
				try
				{
					g.removerSala();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

			    break;

		  case 3:
				try
				{
					g.buscarSala();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

  			    break;

		  case 4:
				try
				{
					g.editarSala();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

 			    break;
		 }
	}
}
void gerenciadorDeFilmes(GerenciaFilme &g)
{
	int opcao;

	while (1)
	{
		cout << "Escolha uma opcao:" << endl;
		cout << "0. Voltar para o Menu anterior" << endl;
		cout << "1. Criar Filme" << endl;
		cout << "2. Remover Filme" << endl;
		cout << "3. Buscar Filme" << endl;
		cout << "4. Editar Filme" << endl;
		cout << "5. Listar Filmes" << endl;
		cin >> opcao;

		switch (opcao){
		  case 0:
			return;

		  case 1:
				try
				{
			  		g.criarFilme();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

				catch(...)
				{
					cout << "\nUm erro ocorreu ao adicionar o filme!" << endl;
				}

			    break;

		  case 2:
				try
				{
					g.removerFilme();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

			    break;

		  case 3:
				try
				{
					g.buscarFilme();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

  			    break;

		  case 4:
				try
				{
					g.editarFilme();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

 			    break;

		  case 5:
				try
				{
					g.listarFilmes();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

 			    break;
		 }
	}
}

void ativarCinema()
{
	int opcao;
	GerenciaSala s;
	GerenciaFilme f;

	while (1)
	{
		cout << "Escolha um menu:" << endl;
		cout << "0. Sair do programa" << endl;
		cout << "1. Gerenciar salas" << endl;
		cout << "2. Gerenciar filmes" << endl;
		cin >> opcao;

		switch(opcao)
		{
			case 0:
				return;

			case 1:
				gerenciadorDeSalas(s);
				break;
			case 2:
				gerenciadorDeFilmes(f);
				break;
		}
	}
}

int main(int argc, char *argv[]) {
	ativarCinema();
	return 0;
}
