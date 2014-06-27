#include <iostream>

// FDAFAFASFASFSAFASUJFHASLFKJHSAFLKSJA


using std::cin;
using std::cout;
using std::endl;

#define MAX_SESSOES 10

void gerenciaMain(Sessao **s)
{
  int opcao_externa, opcao_interna;

  while (1)
  {
    cout << "Escolha uma opcao:" << endl;
    cout << "0. Sair" << endl;
    cout << "1. Inserir sessao" << endl;
    cout << "2. Inserir sessao" << endl;
    cout << "3. Inserir sessao" << endl;
    cout << "1. Inserir sessao" << endl;
    cin >> opcao_externa;

    if (!opcao_externa) return;

    switch (opcao_externa)
    {
      case 1:   //Boundary ou control do Gerencia Sala
        cout << "Digite o"
        break;
        switch (opcao_interna){
          case 1:
          break;
        }
      break;

      case 2:   //Boundary ou control do Sessao Sala
      cout << "Digite o"
        break;
        switch (opcao_interna){
          case 1:
          break;
        }
      break;

      case 3:   //Boundary ou control do Filme Sala
      cout << "Digite o"
        break;
        switch (opcao_interna){
          case 1:
          break;
        }
      break;

      case 4:   //Boundary ou control do Venda Sala
      cout << "Digite o"
        break;
        switch (opcao_interna){
          case 1:
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
