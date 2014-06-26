#ifndef ASSENTO_H
#define ASSENTO_H

#include <iostream>

class Assento
{
  private:
    int idAssento; // num do assento na fileira
    bool disponibilidade;
    char idFileira; // num da fileira da qual este assento faz parte

  public:
    Assento(int _idAssento, bool _disponibilidade, char _idFileira);
    Assento(const Assento &a); // construtor de copia FUTURO
    bool verificaDisponibilidade(); // eh disparado pela classe fileira
    void setIdAssento(int _idAssento);
    void setIdFileira(char _idFileira);
    int getIdAssento();
    char getIdFileira();
};

#endif // ASSENTO_H
