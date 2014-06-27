#include "../headers/venda.h"

Venda(Date _dtVenda, double _valorTotal, FormaPagto _formaPagto)
{
  dtVenda = _dtVenda;
  valorTotal = _valorTotal;
  formaPagto = _formaPagto;
}

Venda(const Venda &v)
{
  dtVenda = v.dtVenda;
  valorTotal = v.valorTotal;
  formaPagto = v.formaPagto;
}

double Venda::calcularValorTotal()
{

}

void Venda::emitirIngresso(Arrays ingresso)
{

}

void Venda::addIngresso(Ingresso ingresso)
{

}

void Venda::removeIngresso(Ingresso ingresso)
{

}
