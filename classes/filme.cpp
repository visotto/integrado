#include "../headers/filme.h"

using std::string;
using std::endl;

Filme::Filme(string _tituloFilme, int _fxetaria, char _idioma)
{
  tituloFilme = _tituloFilme;
  fxetaria = _fxetaria;
  idioma = _idioma;
}

Filme::Filme(const Filme &f)
{
  tituloFilme = f.tituloFilme;
  fxetaria = f.fxetaria;
  idioma = f.idioma;
}

void Filme::setTituloFilme(string _tituloFilme)
{
  tituloFilme = _tituloFilme;
}

void Filme::setFxEtaria(int _fxetaria)
{
  fxetaria = _fxetaria;
}

void Filme::setIdioma(char _idioma)
{
  idioma = _idioma;
}

string Filme::getTituloFilme()
{
  return tituloFilme;
}

int Filme::getFxEtaria()
{
  return fxetaria;
}

char Filme::getIdioma()
{
  return idioma;
}

string Filme::getQueryID()
{
  return tituloFilme;
}

bool Filme::operator<(Filme &f)
{
  return (getQueryID().compare(f.getQueryID()) < 0);
}

bool Filme::operator>(Filme &f)
{
  return (getQueryID().compare(f.getQueryID()) > 0);
}

bool Filme::operator==(Filme &f)
{
  return (getQueryID().compare(f.getQueryID()) == 0);
}

bool Filme::operator!=(Filme &f)
{
  return (getQueryID().compare(f.getQueryID()) != 0);
}

ostream & operator<<(ostream &o, const Filme &f)
{
  o << "Titulo do filme: " << f.tituloFilme << "\n";
  o << "Faixa etaria: " << f.fxetaria << "\n";
  o << "Idioma: " << f.idioma << "\n";
  return o;
}

ofstream & operator<<(ofstream &o, Filme &f)
{
  o << f.tituloFilme << "\n";
  o << f.fxetaria << "\n";
  o << f.idioma << "\n";
  return o;
}
