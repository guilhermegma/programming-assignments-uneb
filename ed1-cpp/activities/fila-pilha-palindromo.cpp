#include <iostream>
#include <ctime> 
#include <cstdlib>

using namespace std;

class Node {
public:
    char info;
    Node *prox;
};

class queue {
    Node *front;
    Node *back;

public:
    queue() {
        front = nullptr;
        back = nullptr;
    }

    void insert(char n);
    int remove();
    void print();
};

void queue::insert(char n) {
    Node *novo = new Node;

    if (novo == nullptr) {
        exit(1);
    }

    novo->info = n;
    novo->prox = nullptr;

    if (front == nullptr) {
        front = novo;
    } else {
        back->prox = novo;
    }

    back = novo;
}

class Pilha {
private:
    Node *topo;

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
    Node *novo = new Node;

    if (novo == nullptr) exit(1);
    
    novo->info = letra;
    novo->prox = topo;
    topo = novo;
}

char Pilha::desempilhar() {
    if (topo == nullptr) exit(1);

    char caractereDesempilhado;
    Node *aux = topo;

    caractereDesempilhado = aux->info;

    topo = topo->prox;

    delete aux;

    return caractereDesempilhado;

}

int main() {
	Pilha p;
	queue f;
	string palavra;
	char c;
    bool ehPalindromo = true;

    cout << "Informe uma palavra, verificaremos se é um palindromo: " << endl;
	cin >> palavra;
	int i = 0;

	while (c != '\0') {
		c = palavra [i];
		f.insert (c);
		p.empilhar (c);
		i++;
	}

    while(p.topo != nullptr){
        char aux = p.desempilhar;
        char aux2 = f.remove;

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