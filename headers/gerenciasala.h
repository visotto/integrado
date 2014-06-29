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
  	void escreverSala(); // funcao para escrever no arquivo salas.data as salas cadastradas
	

  public:
	GerenciaSala();
	/* ------ CRUD ------- */            
    void criarSala(); // retorna true se criou com sucesso
	void removerSala(); // retorna true se removeu com sucesso
	void buscarSala();
	Sala* buscarSala(int _id);  
	void editarSala(); 
	/* ------------------- */

};

#endif // GERENCIASALA_H
