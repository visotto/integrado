#include <iostream>

// AAAAAAAAAAAAAAAAAAAAAAAAAAAA

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
    cin >> opcao_externa;

    if (!opcao_externa) return;

    switch (opcao_externa)
    {
      case 1:
        cout << "Digite o"
        switch (opcao_interna)
    }
  }
}

using namespace std;
int main(int argc, char *argv[]) {
  Sessao *sessoes[MAX_SESSOES];

  gerenciaSessao(sessoes);
}
