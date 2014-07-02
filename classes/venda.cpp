#include "../headers/venda.h"

#include <iomanip> // fixed e setprecision()

using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

Venda::Venda(Sessao *_sessao, int _id ,FormaPagto _formaPagto)
{
  id = _id;
  sessao = _sessao;
  formaPagto = _formaPagto;

  ingressos = new Ingresso*[MAX_INGRESSOS];

  for (int i = 0; i < MAX_INGRESSOS; i++)
    ingressos[i] = NULL;

  qtdIngressos = 0;
}

Venda::~Venda()
{
  delete [] ingressos;
}

double Venda::calcularValorTotal()
{
  double total = 0;

  for (int i = 0; i < MAX_INGRESSOS; i++)
    if (ingressos[i] != NULL)
      total += ingressos[i]->getValor();

  // set
  valorTotal = total;

  // get
  return total;
}

void Venda::emitirIngresso(Ingresso *ingresso)
{
  cout << "==============================" << endl;
  cout << "| Filme:\t" << sessao->getFilme()->getTituloFilme() << endl;
  cout << "| Horario:\t" << ingresso->getHorario() << endl;
  cout << "| Valor:\t" << "R$ " << fixed << setprecision(2) << ingresso->getValor() << endl;
  cout << "| Tipo:\t\t" << ingresso->getTipo() << endl;
  cout << "| Poltrona:\t" << ingresso->getAssento()->getIdFileira() << ingresso->getAssento()->getIdAssento() << endl;
  cout << "==============================" << endl;
                 
}

void Venda::addIngresso(Ingresso *ingresso, double valor, Tipo tipo)
{
  if (qtdIngressos < MAX_INGRESSOS)
  {
//VENDE UM INGRESSO
    for (int i = 0; i < MAX_INGRESSOS; i++)
    {
      if (ingressos[i] == NULL)
      {
        ingressos[i] = ingresso; // associa um ingresso a esta venda
        ingressos[i]->venda(); // altera a disponibilidade do assento para indisponivel e o status do ingresso para vendido
        ingressos[i]->setValor(valor);
        ingressos[i]->setTipo(tipo);
        qtdIngressos++;  // incrementa o numero de ingressos vendidos nesta venda
        sessao->incNumVendido('+'); // incrementa o numero de ingressos vendido na sessao relativa a esta venda
        return;
      }
    }
  }
  else
    cout << "Maximo de ingressos atingido!" << endl;
}

void Venda::removeIngresso(Ingresso *ingresso)
{
  for (int i = 0; i < qtdIngressos; i++)
    if (ingressos[i] == ingresso && ingressos[i]->isVendido()) // se o ingresso buscado foi vendido
    {
      ingressos[i]->cancela();
      ingressos[i] = NULL;
      qtdIngressos--;
      sessao->incNumVendido('-');
      return;
    }

  // so chegamos neste cout se nao encontrarmos o ingresso, ou se ele nao foi vendido
  cout << "Este ingresso ainda nao foi vendido!" << endl;
}

int Venda::getQueryID(){
  return id;
}

int Venda::getQtdIngressos()
{
  return qtdIngressos;
}

Sessao* Venda::getSessao()
{
  return sessao;
}

string Venda::getFormaPagto()
{
  if (formaPagto == dinheiro)
    return "dinheiro";
  else
    return "cartao";
}

Ingresso* Venda::getIngresso(int id)
{
  if (id >= 0 && id < qtdIngressos)
    return ingressos[id];
  else
    return NULL;
}
