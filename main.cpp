#include <iostream>
#include "headers/gerenciasala.h"
using namespace std;

void gerenciaMain()
{
	int opcao;
	GerenciaSala g;

	while (1)
	{
		cout << "Escolha uma opcao para manipulacao da Sala" << endl;
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

using namespace std;
int main(int argc, char *argv[]) {
	gerenciaMain();
	return 0;
}
