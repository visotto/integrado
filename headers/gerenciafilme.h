// BOUNDARY - fronteira
#ifndef GERENCIAFILME_H
#define GERENCIAFILME_H

#include <iostream>
#include "../headers/consts.h"
#include "../headers/filme.h"
#include "../headers/arvore.h"

class GerenciaFilme{
  private:
<<<<<<< HEAD
  int qtdFilmes;
  Arvore<Filme> filmes;
  void escreverFilme(); // funcao para escrever no arquivo Filmes.data os Filmes cadastradas

  public:
  GerenciaFilme();
  /* ------ CRUD ------- */            
  void criarFilme(); // retorna true se criou com sucesso
  void removerFilme(); // retorna true se removeu com sucesso
  void buscarFilme();  
  Filme* buscarFilme(string _tituloFilme);  
  void editarFilme(); 
  /* ------------------- */
  void listarFilmes();
=======
	int qtdFilmes;
	Arvore<Filme> filmes;
//	Filme *filmes[MAX_FILMES];
  	void escreverFilme(); // funcao para escrever no arquivo Filmes.data os Filmes cadastradas

  public:
	GerenciaFilme();
	/* ------ CRUD ------- */            
    void criarFilme(); // retorna true se criou com sucesso
	void removerFilme(); // retorna true se removeu com sucesso
	void buscarFilme();  
	Filme* buscarFilme(string _tituloFilme);  
	void editarFilme(); 
	/* ------------------- */
	void listarFilmes();
>>>>>>> FETCH_HEAD
};

#endif // GERENCIAFILME_H
