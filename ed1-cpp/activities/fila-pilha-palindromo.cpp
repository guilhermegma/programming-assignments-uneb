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

class Pilha {
private:
    Nodo *topo;

public:
    Pilha();
    void empilhar(char n);
    void desempilhar();
    void imprimir();

};

Pilha::Pilha() {
    topo = nullptr;
}

void Pilha::empilhar(char letra) {
    Nodo *novo = new Nodo;

    if (novo == nullptr) exit(1);
    
    novo->info = letra;
    novo->prox = topo;
    topo = novo;
}

char Pilha::desempilhar() {
    if (topo == nullptr) exit(1);

    char caractereDesempilhado;
    Nodo *aux = topo;

    caractereDesempilhado = aux->info;

    topo = topo->prox;

    delete aux;

    return caractereDesempilhado;

}

int main() {
	Pilha p;
	Fila f;
	string palavra;
	char c;
    bool ehPalindromo = true;

    cout << "Informe uma palavra, verificaremos se é um palindromo: " << endl;
	cin >> palavra;
	int i = 0;

	while (c != '\0') {
		c = palavra [i];
		f.inserir (c);
		p.empilhar (c);
		i++;
	}

    while(p.topo != nullptr){
        char aux = p.desempilhar;
        char aux2 = f.retirar;

        if (aux != aux2) {
            ehPalindromo = false;
            break;
        }
    }

    return ehPalindromo;
}

//for each 
//fazer função desempilhar e retirar
//chamar ela retornando o char