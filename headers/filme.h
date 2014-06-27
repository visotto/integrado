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
    Filme();
    Filme(const Sessao &s);
    ~Filme();

    void setStatus(bool encerrada); // modifica o status da sessao: 1 = encerrada, 0 caso contrario
    int getStatus();

    void setFilme(string _filme, int faixaet = 0, char idioma = 'D'): tituloFilme(_filme), fxetaria(_faixaet), idioma(_idioma);
    //Filme getFilme(const Filme &f);
};

#endif // FILME_H
