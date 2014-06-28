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
    Arvore();
    ~Arvore();
    void setRaiz(No<T> *r);
    No<T>* getRaiz();
    No<T>** getEndRaiz();
    void listar(No<T> *r);
    T busca(No<T> *r, T chave);
    bool insere(No<T> **r, T chave);
    No<T> *removeAux(No<T> *r, T chave);
    No<T>* remove(No<T>* r, T chave);
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
No<T>* Arvore<T>::removeAux(No<T> *r, T chave)
{
  if (chave < r->info) // chave menor que no atual
    r->esq = removeAux(r->esq, chave); // desco p/ esq
  else if (chave > r->info) // chave maior que no atual
    r->dir = removeAux(r->dir, chave); // desco p/ dir
  else
  { // encontrou elemento a ser removido
       // elemento sem filhos, soh remover
    if (r->esq == NULL && r->dir == NULL)
    {
      // free(r);
      // r = NULL;
      r->~No();
    }

    // soh tem o filho da direita
    else if (r->esq == NULL)
    {
      No<T>* temp;
      temp = new No<T>;
      temp = r;

      r = r->dir;
      // free(temp);
      temp->~No(); 
    }

    // soh tem o filho da esquerda
    else if (r->dir == NULL)
    {
     No<T>* temp;
      temp = new No<T>;
      temp = r;

      r = r->esq;
      // free(temp);
      temp->~No();
    }

    // tem os 2 filhos
    else
    {
      // No* temp = r->esq; // vai p/ o filho da esq
      No<T>* temp;
      temp = new No<T>;
      temp = r->esq;

      while (temp->dir != NULL) // atualiza ateh achar o maior filho da sub arvore a dir
        temp = temp->dir;

      r->info = temp->info; // troca as infos, coloca no lugar do no a ser removido
      temp->info = chave;
      // trocou r->info com temr->info

      r->esq = removeAux(r->esq, chave); // chama recursivamente p/ filho da esq
    }
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

class Busca
{
  friend ostream & operator<<(ostream &o, const Busca &b);
 
  private:
    int id;
    float valor;
    
  public:
    Busca() : id(0), valor(0.0) {};
    Busca(int i, float v) : id(i), valor(v) {} ;
    int getQueryID() const
    {
      return id;
    }
    float getValor() const
    {
      return valor;
    }
    bool operator<(const Busca &b)
    {
      return (id < b.id);
    }
    bool operator>(const Busca &b)
    {
      return (id > b.id);
    }
    bool operator==(const Busca &b)
    {
      return (id == b.id);
    }
    bool operator!=(const Busca &b)
    {
      return (id != b.id);
    }
};

ostream & operator<<(ostream &o, const Busca &b)
{
  o << "ID: " << b.getQueryID() << " Valor: " << b.getValor();
  return o;
}

int main(int argc, char *argv[]) {
  
  Arvore<Busca> r;
  Busca b1(44,99.9), b2(14, 6.0);
  
  r.insere(r.getEndRaiz(), Busca(5,1.0));
  r.insere(r.getEndRaiz(), Busca(78,2.0));
  r.insere(r.getEndRaiz(), Busca(10,3.0));
  r.insere(r.getEndRaiz(), Busca(14,4.0));
  r.insere(r.getEndRaiz(), Busca(37,5.0));
  r.insere(r.getEndRaiz(), Busca(25,6.0));
  r.insere(r.getEndRaiz(), Busca(2,7.0));
  r.insere(r.getEndRaiz(), Busca(44,8.0));
  r.listar(r.getRaiz());
  
  try {r.busca(r.getRaiz(), b1);
    cout << "tem b1" << endl;}
  catch(char const* s){cout<<s<<endl;}

  try {r.busca(r.getRaiz(), b2);
    cout << "tem b2" << endl;}
  catch(char const* s){cout<<s<<endl;}
  
  printf("\n");
  
  r.setRaiz(r.remove(r.getRaiz(), b1));
  r.listar(r.getRaiz());  
//  printf("%d", r->busca(*r, 2));
  
  return 0;
}