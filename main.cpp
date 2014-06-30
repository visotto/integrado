#include <iostream>

#include "headers/gerenciasala.h"
#include "headers/gerenciafilme.h"
#include "headers/gerenciasessao.h"
#include "headers/gerenciavenda.h"

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

void gerenciadorDeSessoes(GerenciaSessao &g)
{
	int opcao;

	while (1)
	{
		cout << "Escolha uma opcao:" << endl;
		cout << "0. Voltar para o Menu anterior" << endl;
		cout << "1. Criar Sessao" << endl;
		cout << "2. Remover Sessao" << endl;
		cout << "3. Buscar Sessao" << endl;
		cout << "4. Editar Sessao" << endl;
		cin >> opcao;

		switch (opcao){
		  case 0:
			return;

		  case 1:
				try
				{
			  		g.criarSessao();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

				catch(...)
				{
					cout << "\nUm erro ocorreu ao adicionar a sessao!" << endl;
				}

			    break;

		  case 2:
				try
				{
					g.removerSessao();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

			    break;

		  case 3:
				try
				{
					g.buscarSessao();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

  			    break;

		  case 4:
				try
				{
					g.editarSessao();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

 			    break;

		 }
	}
}

void gerenciadorDeVendas(GerenciaVenda &g)
{
	int opcao;

	while (1)
	{
		cout << "Escolha uma opcao:" << endl;
		cout << "0. Voltar para o Menu anterior" << endl;
		cout << "1. Criar Venda" << endl;
		cout << "2. Exibir Venda" << endl;
		cout << "3. Adicionar ingresso em uma venda" << endl;
		cout << "4. Remover ingresso de uma venda" << endl;
		cin >> opcao;

		switch (opcao){
		  case 0:
			return;

		  case 1:
				try
				{
			  		g.criaVenda();
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

				catch(...)
				{
					cout << "\nUm erro ocorreu ao criar a venda!" << endl;
				}

			    break;

		  case 2:
				try
				{
					int _id;
					cout << "\nEntre com ID da venda: ";
					cin >> _id;
					g.exibirVenda(_id);
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

			    break;

		  case 3:
				try
				{
					int _id;
					cout << "\nEntre com ID da venda: ";
					cin >> _id;
					g.addIngressoVenda(_id);
				}

				catch(char const* s)
				{
					cout << s << endl;
				}

  			    break;

		  case 4:
				try
				{
					int _id;
					cout << "\nEntre com ID da venda: ";
					cin >> _id;
					g.removeIngressoVenda(_id);
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
	GerenciaSessao se(&s,&f);
	GerenciaVenda gv(&s, &se);

	while (1)
	{
		cout << "Escolha um menu:" << endl;
		cout << "0. Sair do programa" << endl;
		cout << "1. Gerenciar salas" << endl;
		cout << "2. Gerenciar filmes" << endl;
		cout << "3. Gerenciar sessoes" << endl;
		cout << "4. Gerenciar vendas" << endl;
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
			case 3:
				gerenciadorDeSessoes(se);
			break;
			case 4:
				gerenciadorDeVendas(gv);
			break;


		}
	}
}

int main(int argc, char *argv[]) {
	ativarCinema();
	return 0;
}
