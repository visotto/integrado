#ifndef FILEIRA_H
#define FILEIRA_H

#include <iostream>
#include "../headers/assento.h"

class Fileira
{
  private:
    char idFileira;
	int qtdAssentos;
    Assento **assentos; // vetor de ponteiros para assentos

  public:
    Fileira(char _idFileira, int _qtdAssentos);
	~Fileira();
    bool verificaDisponibilidade();
	char getIdFileira();
	void setIdFileira(int _idFileira);
	Assento* getAssento(int idAssento);

};

#endif // FILEIRA_H
