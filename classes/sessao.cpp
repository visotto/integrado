#include "../headers/sessao.h"
#include "../headers/consts.h"

Sessao::Sessao(Sala *_sala, int _id, Horario _horario, Filme *_filme)
{
  id = _id;
  sala = _sala;  
  horario = _horario;
  encerrada = false;
  filme = _filme;
  numVendido = 0;
  ingressos = new Ingresso*[sala->getCapacidade()*sala->getQtdAssentos()];

  for (int i = 0; i < sala->getCapacidade(); i++)
    for (int j = 0; j < sala->getQtdAssentos(); j++)
      ingressos[sala->getQtdAssentos()*i + j] = new Ingresso(horario, sala->getFileira(i)->getAssento(j));
}

Sessao::~Sessao()
{
  for (int i = 0; i < sala->getCapacidade()*sala->getQtdAssentos(); i++)
    delete ingressos[i];

  delete [] ingressos;
}

void Sessao::setStatus(bool encerrada)
{
  Sessao::encerrada = encerrada;
}

bool Sessao::getStatus()
{
  return encerrada;
}

void Sessao::setHorario(Horario _horario)
{
  horario = _horario;
}

Horario Sessao::getHorario()
{
  return horario;
}

Ingresso* Sessao::getIngresso(char idFileira, int idAssento)
{
  return ingressos[sala->getQtdAssentos() * ((int)idFileira-'A') + (idAssento-1)];
}

// altera o numero de ingressos vendidos
void Sessao::incNumVendido(char opcao) // disparado toda vez que uma venda eh realizada
{
  if (opcao == '+') // addIngresso
      numVendido++;
  if(opcao == '-')  // removeIngresso
    numVendido--;
}

int Sessao::getNumVendido()
{
  return numVendido;
}

int Sessao::getQueryID(){
  return id;
}

Sala* Sessao::getSala()
{
  return sala;
}

Filme* Sessao::getFilme()
{
  return filme;
}
