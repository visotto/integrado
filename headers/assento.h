#ifndef ASSENTO_H
#define ASSENTO_H

class Assento
{
  private:
    int idAssento; // num do assento na fileira
    bool disponibilidade; // 1 se disponivel, 0 caso contrario
    char idFileira; // num da fileira da qual este assento faz parte

  public:
    Assento(int _idAssento, bool _disponibilidade, char _idFileira); // construtor
    void setDisponibilidade(bool _disponibilidade);
    void setIdAssento(int _idAssento);
    void setIdFileira(char _idFileira);
    bool getDisponibilidade();
    int getIdAssento();
    char getIdFileira();
};

#endif // ASSENTO_H
