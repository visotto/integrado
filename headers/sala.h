#ifndef SALA_H
#define SALA_H

#include <iostream>
#include "../headers/fileira.h"

using std::string;

enum Situacao {disponivel, manuEquipamento, reforma, manuGeral, alocada};

class Sala
{
  private: 
    int numSala;
    int capacidade;
    int qtdAssentos;
    Situacao situacao;
    Fileira **fileiras; // vetor de ponteiros para alocar as fileiras relativas a esta sala

  public:
    Sala(int _numSala, int _capacidade, Situacao _situacao, int _qtdAssentos); // construtor
    ~Sala(); // destrutor

    int getQtdAssentos();

    int getNumSala();
    void setNumSala(int numSala);

    string getSituacao();
    void setSituacao(Situacao _situacao);

    int getCapacidade();
    void setCapacidade(int capacidade);

    Fileira* getFileira(int idFileira);

    int getQueryID(); // retorna o numero da sala
};

#endif // SALA_H
