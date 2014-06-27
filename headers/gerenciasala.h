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
	void removerSala(); // retorna true se removeu com sucesso
	void buscarSala();  
	void editarSala();  
	/* ------------------- */
};

#endif // GERENCIASALA_H
