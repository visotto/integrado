#ifndef GERENCIASESSAO_H
#define GERENCIASESSAO_H

#include "../headers/sessao.h"
#include "../headers/consts.h"
#include "../headers/gerenciasala.h"
#include "../headers/gerenciafilme.h"

class GerenciaSessao
{
  private:
    int qtdSessoes;
    Sessao *sessoes[MAX_SESSOES];
    GerenciaSala *gerencSala;
    GerenciaFilme *gerencFilme;

  public:
    GerenciaSessao(GerenciaSala *g, GerenciaFilme *f); // construtor
    /* ------ CRUD ------- */
    void criarSessao();
    void removerSessao();
    void buscarSessao();
    Sessao* buscarSessao(int id);
    void editarSessao();
    /* ------------------- */
    void escreverSessao(); // metodo para escrever no arquivo sessoes.data as salas cadastradas
    void listarSessoes();
};

#endif // GERENCIASESSAO_H
