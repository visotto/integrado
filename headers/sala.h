#ifndef SALA_H
#define SALA_H

#include <iostream>
#include "../headers/fileira.h"

enum Situacao {disponivel, manuEquipamento, reforma, manuGeral};

class Sala
{
  private: 
    int numSala;
    int capacidade;
    Situacao situacao;
    Fileira **fileiras; // vetor de ponteiros para fileiras

  public:
    Sala(int _numSala, int _capacidade, Situacao _situacao, int qtdAssentos);
    Sala(const Sala &s);
	~Sala();

    int getNumSala();
    void setNumSala(int numSala);
    
    void setCapacidade(int capacidade);
    int getCapacidade();
    
};

#endif // SALA_H
