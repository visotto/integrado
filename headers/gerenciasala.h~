// BOUNDARY - fronteira
#ifndef GERENCIASALA_H
#define GERENCIASALA_H

#include <iostream>
#include "../headers/sala.h"

#define MAX_SALAS 100

class GerenciaSessao{
  private:
	int qtdSalas;
	Sala *salas[MAX_SALAS];
  
  public:
	GerenciaSala();
	/* ------ CRUD ------- */            
    bool criarSala(); // retorna true se criou com sucesso
	bool removerSala(); // retorna true se removeu com sucesso
	void buscarSala();  
	void editarSala();  
	/* ------------------- */
};

#endif // GERENCIASALA_H
