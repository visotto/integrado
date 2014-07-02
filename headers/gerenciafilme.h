#ifndef GERENCIAFILME_H
#define GERENCIAFILME_H

#include "../headers/consts.h"
#include "../headers/filme.h"
#include "../headers/arvore.h"

class GerenciaFilme
{
  private:
    int qtdFilmes;
    Arvore<Filme> filmes; // estrutura ABB que armazena os filmes
    void escreverFilme(); // metodo para escrever no arquivo filmes.data os filmes cadastradas

  public:
    GerenciaFilme(); // construtor
    /* ------ CRUD ------- */
    void criarFilme();
    void removerFilme();
    void buscarFilme();
    Filme* buscarFilme(string _tituloFilme);
    void editarFilme();
    /* ------------------- */
    void listarFilmes();
};

#endif // GERENCIAFILME_H
