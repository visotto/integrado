#include "../headers/Filme.h"

Filme()
{
  
}

Filme(const Filme &s)
{
 
}

void Filme::setStatus(bool encerrada)
{
  Filme::encerrada = encerrada;
}

int Filme::getStatus()
{
  return encerrada;
}

void Filme::setFilme(Filme f, string _tituloFilme, int _fxetaria, char idioma)
{
}

/*
Filme Filme::getFilme(const Filme &f) // usa default e lista de inicializadores para retorna as informacoes relativas ao filme 
{
  return filme;
}
*/
