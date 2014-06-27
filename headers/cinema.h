#include <iostream>
#include "../headers/consts.h"

using std::cin;
using std::cout;
using std::endl;

void gerenciaMain(Sessao **s)
{
  int opcao_externa, opcao_interna;

  while (1)
  {
    cout << "Escolha uma opcao:" << endl;
    cout << "0. Sair" << endl;
    cout << "1. Inserir Sala" << endl;
    cout << "2. Inserir Sessao" << endl;
    cout << "3. Inserir Filme" << endl;
    cout << "4. Inserir Venda" << endl;
    cin >> opcao_externa;

    if (!opcao_externa) return;

    switch (opcao_externa)
    {
      case 0:
      break;

      case 1:   //Boundary ou control do Gerencia Sala
        cout << "Escolha uma opcao para manipulacao da Sala"
        cout << "0. Voltar para o Menu anterior" << endl;
        cout << "1. Criar Sala" << endl;
        cout << "2. Remover Sala" << endl;
        cout << "3. Buscar Sala" << endl;
        cout << "4. Editar Sala" << endl;
        break;
        switch (opcao_interna){
          case 0:
          break;
          case 1:
          break;
          case 2:
          break;
          case 3:
          break;
          case 4:
          break;
        }
      break;

      case 2:   //Boundary ou control do Gerencia Sessao
        cout << "Escolha uma opcao para manipulacao da Sessao"
        cout << "0. Voltar para o Menu anterior" << endl;
        cout << "1. Criar Sessao" << endl;
        cout << "2. Remover Sessao" << endl;
        cout << "3. Buscar Sessao" << endl;
        cout << "4. Editar Sessao" << endl;
        break;
        switch (opcao_interna){
          case 0:
          break;
          case 1:
          break;
          case 2:
          break;
          case 3:
          break;
          case 4:
          break;
        }
      break;

      case 3:   //Boundary ou control do Gerencia Filme
        cout << "Escolha uma opcao para manipulacao da Filme"
        cout << "0. Voltar para o Menu anterior" << endl;
        cout << "1. Criar Filme" << endl;
        cout << "2. Remover Filme" << endl;
        cout << "3. Buscar Filme" << endl;
        cout << "4. Editar Filme" << endl;
        break;
        switch (opcao_interna){
          case 0:
          break;
          case 1:
          break;
          case 2:
          break;
          case 3:
          break;
          case 4:
          break;
        }
      break;

     case 4:   //Boundary ou control do Gerencia Venda
        cout << "Escolha uma opcao para manipulacao da Venda"
        cout << "0. Voltar para o Menu anterior" << endl;
        cout << "1. Criar Venda" << endl;
        cout << "2. Remover Venda" << endl;
        cout << "3. Buscar Venda" << endl;
        cout << "4. Editar Venda" << endl;
        break;
        switch (opcao_interna){
          case 0:
          break;
          case 1:
          break;
          case 2:
          break;
          case 3:
          break;
          case 4:
          break;
        }
      break;

  }
}

using namespace std;
int main(int argc, char *argv[]) {
  Sessao *sessoes[MAX_SESSOES];

  gerenciaSessao(sessoes);
}
