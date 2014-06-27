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
	int qtdAssentos;
    Situacao situacao;
    Fileira **fileiras; // vetor de ponteiros para fileiras

  public:
    Sala(int _numSala, int _capacidade, Situacao _situacao, int _qtdAssentos);
    Sala(const Sala &s);
	~Sala();

    int getNumSala();
    void setNumSala(int numSala);

	int getQtdAssentos();
	std::string getSituacao();
	void setSituacao(Situacao _situacao); // Foi Adicionado essa pola, favor colocar no relatorio
    
    void setCapacidade(int capacidade);
    int getCapacidade();

	Fileira* getFileira(int idFileira);
};

#endif // SALA_H
