#ifndef FILME_H
#define FILME_H

#include <iostream>
using std::string;

class Filme
{
  private:
    string tituloFilme;
    int fxetaria;
    char idioma;  //L - legendado; D -  dublado; N - nacional


  public:
    Filme(string _tituloFilme, int _fxetaria, char _idioma);

    void setTituloFilme(string _filme);
    void setFxEtaria(int _fxEtaria);
    void setIdioma(char idioma);

	string getTituloFilme();
    int getFxEtaria();
    char getIdioma();
	string getQueryID();

};

#endif // FILME_H
