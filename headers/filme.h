#ifndef FILME_H
#define FILME_H

#include <iostream>
using std::string;

class Filme
{
  private:
	Filme *filme;
	int qtdFilmes
    string tituloFilme;
    int fxetaria;
    char idioma;  //L - legendado; D -  dublado; N - nacional


  public:
    Filme();
    Filme(const Sessao &s);
    ~Filme();

    void setTituloFilme(string _filme);
    void setFxEtaria(string _filme);
    void setIdioma(string _filme);

	string getTituloFilme();
    int getFxEtaria();
    char getIdioma();

};

#endif // FILME_H
