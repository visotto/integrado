// BOUNDARY - fronteira
#ifndef GERENCIASESSAO_H
#define GERENCIASESSAO_H

#include <iostream>
#include "../headers/sessao.h"
#include "../headers/consts.h"
#include "../headers/gerenciasala.h"
#include "../headers/gerenciafilme.h"

class GerenciaSessao{
  private:
    int qtdSessoes;
    Sessao *sessoes[MAX_SESSOES];
    GerenciaSala *gerencSala;
    GerenciaFilme *gerencFilme;  

  public:
    GerenciaSessao(GerenciaSala *g, GerenciaFilme *f);
    /* ------ CRUD ------- */            
    void criarSessao(); // retorna true se criou com sucesso
    void removerSessao(); // retorna true se removeu com sucesso
    void buscarSessao();  
    Sessao* buscarSessao(int id);  
    void editarSessao(); 
    /* ------------------- */
    void escreverSessao(); // funcao para escrever no arquivo sessoes.data as salas cadastradas
    void listarSessoes();
};

#endif // GERENCIASESSAO_H
