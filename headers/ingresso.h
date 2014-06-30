#ifndef INGRESSO_H
#define INGRESSO_H

#include <iostream>
#include "../headers/horario.h"
#include "../headers/assento.h"

using std::string;

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
	string getTipo();
	void setTipo(Tipo t);
	Assento* getAssento();
    void setValor(double valor);
    
    void venda(); // ocupa o assento
	void cancela(); // libera o assento
};

#endif // INGRESSO_H
