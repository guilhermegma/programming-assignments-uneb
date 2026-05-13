#include <iostream>
#include <ctime> 
#include <cstdlib>

using namespace std;

class Nodo {
public:
    char info;
    Nodo *prox;
};

class Pilha {

public:
    Nodo *topo;

    Pilha() {
        topo = nullptr;
    }

    void empilhar(char n);
    int desempilhar();
    void imprimir();
};

void Pilha::empilhar(char n) {
    Nodo *novo = new Nodo;
    if (novo == nullptr) exit(1);

    novo->info = n;
    novo->prox = topo;
    topo = novo;
}

