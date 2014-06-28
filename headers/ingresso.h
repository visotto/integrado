#ifndef INGRESSO_H
#define INGRESSO_H

#include <iostream>

enum Tipo {inteiro, meia};

class Ingresso{
  private: 
    Date dtIngresso;
    double valor;
    Tipo tipo;
	Assento *assento;
	bool vendido;
  
  public:
    Ingresso(Date _dtIngresso, double _valor, Tipo _tipo, Assento *_assento);
    Ingresso(const Ingresso &i); // construtor de copia FUTURO

    Date getDtingresso();
    void setDtingresso(Date dtIngresso);
    
    double getValor();
    void setValor(double valor);
    
    void venda();
	{
		vendido = true;
		assento->getDisponibilidade() = false;
	}
};

#endif // INGRESSO_H
