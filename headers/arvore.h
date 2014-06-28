#include <iostream>

using namespace std;

template<class T>
class No {
  public:
    T info;
    No<T>*esq;
    No<T>*dir;
    No();
    No(T &obj);
    No(No* no);
};

template <class T>
class Arvore {
  private:
    No<T> *raiz;

  public:
    // Construtor e destrutor
    Arvore();
    ~Arvore();
    
    // Metodos para manipular a raiz da arvore
    void setRaiz(No<T> *r);
    No<T>* getRaiz();
    No<T>** getEndRaiz();
    
    // CRUD
    bool insere(No<T> **r, T chave);
    No<T>* remove(No<T>* r, T chave);
    void listar(No<T> *r);
    T busca(No<T> *r, T chave);
};

// =================================
// Metodos relativas a classe No

template<class T>
No<T>::No()
{  
  esq = NULL;
  dir = NULL;
}

template<class T>
No<T>::No(T &obj)
{
  info = obj;
  esq = NULL;
  dir = NULL;
}

template<class T>
No<T>::No(No<T>* no)
{
  info = no->info;
  esq = no->esq;
  dir = no->dir;
}

// Fim das metodos da classe No
// =================================

// =================================
// Metodos relativas a classe Arvore

template <class T>
Arvore<T>::Arvore()
{
  raiz = NULL;
}

template <class T>
Arvore<T>::~Arvore()
{
  delete raiz;
}

template<class T>
void Arvore<T>::setRaiz(No<T> *r)
{
  raiz = r;
}


template<class T>
No<T>* Arvore<T>::getRaiz()
{
  return raiz;
}

template<class T>
No<T>** Arvore<T>::getEndRaiz()
{
  return &raiz;
}

template <class T>
void Arvore<T>::listar(No<T> *r)
{
  if (r != NULL) {
    listar(r->esq);
    cout << r->info << endl;
    listar(r->dir);
  }
}

template <class T>
T Arvore<T>::busca(No<T> *r, T chave)
{
  if (r == NULL)
    throw "Item nao encontrado\n";

  if (chave == r->info)
    return r->info;

  if (chave < r->info)
  {
    return busca(r->esq, chave);
  } 
  else
  {
    return busca(r->dir, chave);
  }
}

template <class T>
bool Arvore<T>::insere(No<T> **r, T chave)
{
  No<T>* novo;

  if (*r == NULL)
  {
    novo = new No<T>(chave);
    *r = novo;
    return true;
  }
  else
  {
    if (chave < (*r)->info)
    {
      return insere(&(*r)->esq, chave);
    }
    else if (chave > (*r)->info)
    {
      return insere(&(*r)->dir, chave);
    }
    else
      return false;
  }
}

template <class T>
No<T>* Arvore<T>::remove(No<T>* r, T chave)
{
  try
  {
    busca(r, chave);
  }
  catch(char const* s)
  {
    cout << s << endl;
    return r;
  }

  No<T> *fila[12345], *rem;
  int head, tail;
  Arvore *ret = new Arvore<T>;
  
  head = tail = 0;
  
  fila[tail++] = r;
  while (head != tail)
  {
     rem = fila[head++];
     if (rem->info != chave)
       ret->insere(ret->getEndRaiz(), rem->info);
      
     if (rem->esq != NULL) fila[tail++] = rem->esq;
     if (rem->dir != NULL) fila[tail++] = rem->dir;
  }
  
  return ret->getRaiz();
}  
