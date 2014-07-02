#ifndef FILEIRA_H
#define FILEIRA_H

#include "../headers/assento.h"

class Fileira
{
  private:
    char idFileira; // letras de A-Z, portanto o maximo eh 26
    int qtdAssentos;
    Assento **assentos; // vetor de ponteiros para alocar os assentos relativos a esta fileira

  public:
    Fileira(char _idFileira, int _qtdAssentos); // construtor
    ~Fileira(); // destrutor para desalocar os assentos
    // bool verificaDisponibilidade(); // verifica se existe ao menos 1 assento disponivel
    char getIdFileira();
    void setIdFileira(char _idFileira);
    Assento* getAssento(int idAssento); // retorna o endereco do assento cujo id eh idAssento
};

#endif // FILEIRA_H
