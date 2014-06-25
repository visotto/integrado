#ifndef INGRESSO_H
#define INGRESSO_H

#include <iostream>

enum Tipo {inteiro, meia};

class Ingresso{
  private: 
    Date dtIngresso;
    double valor;
    Tipo tipo;
  
  public:
    Ingresso(Date _dtIngresso, double _valor, Tipo _tipo);
    Ingresso(const Ingresso &i);

    Date getDtingresso();
    void setDtingresso(Date dtIngresso);
    
    double getValor();
    void setValor(double valor);
    
    
};

#endif // INGRESSO_H
