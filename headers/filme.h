#ifndef FILME_H
#define FILME_H

#include <iostream>
#include <fstream>
using std::string;
using std::ostream;
using std::ofstream;

class Filme
{
  friend ostream & operator<<(ostream &o, const Filme &f);
  friend ofstream & operator<<(ofstream &o, Filme &f);

  private:
    string tituloFilme;
    int fxetaria;
    char idioma;  // L - legendado; D -  dublado; N - nacional

  public:
    Filme(string _tituloFilme = " ", int _fxetaria = 0, char _idioma = ' ');
    Filme(const Filme &f);

    void setTituloFilme(string _filme);
    void setFxEtaria(int _fxEtaria);
    void setIdioma(char idioma);

    string getTituloFilme();
    int getFxEtaria();
    char getIdioma();
    string getQueryID();

    // sobrecargas necessarias para funcionamento da arvore
    bool operator<(Filme &f);
    bool operator>(Filme &f);
    bool operator==(Filme &f);
    bool operator!=(Filme &f);
};

#endif // FILME_H
