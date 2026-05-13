#include <iostream>
#include <ctime> 
#include <cstdlib>

using namespace std;

class Nodo {
public:
    char info;
    Nodo *prox;
};

class Fila {
    Nodo *inicio;
    Nodo *fim;

public:
    Fila() {
        inicio = nullptr;
        fim = nullptr;
    }

    void inserir(char n);
    int retirar();
    void imprimir();
};

void Fila::inserir(char n) {
    Nodo *novo = new Nodo;

    if (novo == nullptr) {
        exit(1);
    }

    novo->info = n;
    novo->prox = nullptr;

    if (inicio == nullptr) {
        inicio = novo;
    } else {
        fim->prox = novo;
    }

    fim = novo;
}
