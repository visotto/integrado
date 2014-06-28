// BOUNDARY - fronteira
#ifndef GERENCIAFILME_H
#define GERENCIAFILME_H

#include <iostream>
#include "../headers/consts.h"
#include "../headers/filme.h"

class GerenciaFilme{
  private:
	int qtdFilmes;
	Filme *filmes[MAX_FILMES];
  	void escreverFilme(); // funcao para escrever no arquivo Filmes.data os Filmes cadastradas

  public:
	GerenciaFilme();
	/* ------ CRUD ------- */            
    void criarFilme(); // retorna true se criou com sucesso
	void removerFilme(); // retorna true se removeu com sucesso
	void buscarFilme();  
	void editarFilme(); 
	/* ------------------- */
	void listarFilmes();

};

#endif // GERENCIAFILME_H
