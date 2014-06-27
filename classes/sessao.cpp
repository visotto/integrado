#include "../headers/sessao.h"
#include "../headers/consts.h"

Sessao(bool _encerrada, int _numVendido)
{
  horarios = new Horario[maxHorarios];
  encerrada = _encerrada;
  numVendido = _numVendido;
}

Sessao(const Sessao &s)
{
  encerrada = s.encerrada;
  numVendido = s.numVendido;
}

void Sessao::setStatus(bool encerrada)
{
  Sessao::encerrada = encerrada;
}

int Sessao::getStatus()
{
  return encerrada;
}

// posicionador usado para inserir um horario na primeira posicao
bool Sessao::setHorario(Horario* horario, Horario anterior, Horario atual)
{ 
  // posicionador para posicao valida, achei o anterior ou ele nao existe
  for(int i = 0; i < qtdHorarios && anterior != horario[i]; i++)
  
  if (i != qtdHorarios)
  {
    horario[i] = atual;

    return 1;
  }

  return 0;
}

void Sessao::setHorario()
{
    if (qtdHorarios < maxHorarios)
    {
      Sessao::horarios[qtdHorarios] = horario;
      qtdHorarios++;
    }
}

Horario* Sessao::getHorarios()
{
  Horario *retorno = new Horario[maxHorarios];

  // copia todos os horarios desta sessao
  for (int i = 0; i < qtdHorarios; i++)
      retorno[i] = horarios[i];
  // o retorno de um veotr auxiliar eh utilizado para nao quebrar o encapsulamento
  return retorno;
}

// altera o numero de ingressos vendidos
void Sessao::setNumVendido(int numVendido)
{
  Sessao::numVendido = numVendido;
}

int Sessao::getNumVendido()
{
  return numVendido;
}


