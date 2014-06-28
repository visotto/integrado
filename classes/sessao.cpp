#include "../headers/sessao.h"
#include "../headers/consts.h"

Sessao::Sessao(Sala *_sala, bool _encerrada, int _numVendido, Filme *_filme)
{
  sala = _sala;	
  horarios = new Horario[maxHorarios];
  qtdHorarios = 0;
  encerrada = _encerrada;
  numVendido = _numVendido;
  filme = _filme;
  numVendido = 0;
}
/*
Sessao(const Sessao &s)
{
  encerrada = s.encerrada;
  numVendido = s.numVendido;
}
*/
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

    return true;
  }

  else
	setHorario(horario);

  return false;
}

void Sessao::setHorario(Horario* horario)
{
    if (qtdHorarios < maxHorarios)
    {
      horarios[qtdHorarios] = horario;
      qtdHorarios++;
    }
}

Horario* Sessao::getHorarios()
{
  Horario *retorno = new Horario[maxHorarios];

  // copia todos os horarios desta sessao
  for (int i = 0; i < qtdHorarios; i++)
      retorno[i] = horarios[i];
  // o retorno de um vetor auxiliar eh utilizado para nao quebrar o encapsulamento
  return retorno;
}

// altera o numero de ingressos vendidos
void Sessao::incNumVendido(char opcao) //disparado toda vez que uma venda eh realizada
{
	if (opcao == '+') //addIngresso
  		numVendido++;
	if(opcao == '-')	//removeIngresso
		numVendido--;
}

int Sessao::getNumVendido()
{
  return numVendido;
}


