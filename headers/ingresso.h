#ifndef INGRESSO_H
#define INGRESSO_H

#include <iostream>
#include "../headers/horario.h"
#include "../headers/assento.h"

enum Tipo {inteiro, meia};

class Ingresso{
  private: 
    Horario horaIngresso;
    double valor;
    Tipo tipo;
	Assento *assento;
	bool vendido;
  
  public:
    Ingresso(Horario _horaIngresso, Assento *_assento);

	bool isVendido(); // retorna se o ingresso foi vendido ou nao
    
    double getValor();
	Horario getHorario();
	Tipo getTipo();
	Assento* getAssento();
    void setValor(double valor);
    
    void venda(); // ocupa o assento
	void cancela(); // libera o assento
};

#endif // INGRESSO_H
