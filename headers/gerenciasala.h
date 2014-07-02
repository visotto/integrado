#ifndef GERENCIASALA_H
#define GERENCIASALA_H

#include "../headers/sala.h"
#include "../headers/consts.h"

class GerenciaSala
{
  private:
    int qtdSalas;
    Sala *salas[MAX_SALAS];

  public:
    GerenciaSala(); // construtor
    /* ------ CRUD ------- */
    void criarSala();
    void removerSala();
    void buscarSala();
    Sala* buscarSala(int _id);
    void editarSala();
    /* ------------------- */
    void escreverSala(); // metodo para escrever no arquivo salas.data as salas cadastradas
    void listarSalas();
};

#endif // GERENCIASALA_H
