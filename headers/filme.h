#ifndef FILME_H
#define FILME_H

#include <iostream>
#include <fstream>
using std::string;
using std::ostream;
using std::ofstream;

class Filme
{ 

  // sobrecarga do operador de escrita <<
  // escreve os dados do filme na saida padrao (terminal)
  friend ostream &operator<<(ostream &o, const Filme &f);
  
  // escreve os dados do filme em arquivo
  friend ofstream &operator<<(ofstream &o, Filme &f);

  private:
    string tituloFilme; 
    int fxetaria; // entre 0 e 18, sendo que 0 eh classificacao LIVRE
    char idioma; // L - legendado; D -  dublado; N - nacional

  public:
    Filme(string _tituloFilme = " ", int _fxetaria = 0, char _idioma = 'L'); // construtor
    Filme(const Filme &f); // construtor de copia

    void setTituloFilme(string _filme);
    void setFxEtaria(int _fxEtaria);
    void setIdioma(char idioma);

    string getTituloFilme();
    int getFxEtaria();
    char getIdioma();
    string getQueryID(); // retorna o titulo

    // sobrecargas necessarias para funcionamento da arvore
    bool operator<(Filme &f);
    bool operator>(Filme &f);
    bool operator==(Filme &f);
    bool operator!=(Filme &f);
};

#endif // FILME_H
