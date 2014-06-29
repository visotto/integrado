// BOUNDARY - fronteira
#ifndef GERENCIASALA_H
#define GERENCIASALA_H

#include <iostream>
#include "../headers/sala.h"
#include "../headers/consts.h"

class GerenciaSala{
  private:
    int qtdSalas;
    Sala *salas[MAX_SALAS];

  public:
    GerenciaSala();
    /* ------ CRUD ------- */            
    void criarSala(); // retorna true se criou com sucesso
<<<<<<< HEAD
    void removerSala(); // retorna true se removeu com sucesso
    void buscarSala();
    Sala* buscarSala(int _id);  
    void editarSala(); 
    /* ------------------- */
    void escreverSala(); // funcao para escrever no arquivo salas.data as salas cadastradas
=======
	void removerSala(); // retorna true se removeu com sucesso
	void buscarSala();
	Sala* buscarSala(int _id);  
	void editarSala(); 
	/* ------------------- */

>>>>>>> FETCH_HEAD
};

#endif // GERENCIASALA_H
