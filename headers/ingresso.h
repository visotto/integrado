#ifndef INGRESSO_H
#define INGRESSO_H

#include "../headers/horario.h"
#include "../headers/assento.h"

using std::string;

enum Tipo {inteiro, meia};

class Ingresso
{
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
    Assento* getAssento();

    void setValor(double valor);
    void setTipo(Tipo t);

    void venda(); // ocupa o assento relacionado a este ingresso
    void cancela(); // libera o assento relacionado a este ingresso
};

#endif // INGRESSO_H
