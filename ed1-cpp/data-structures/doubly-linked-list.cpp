#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int info;
    Node *prox;
    Node *ant;
};

class DoublyList {
private:
    Node *head;
    Node *tail; 

public:
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }
    
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void remove(int value);
    void printForward();  
    void printBackward(); 
};

void DoublyList::insertAtBeginning(int value) {
    Node *newNode = new Node;

    if (newNode == nullptr) {
        cout << "No memory" << endl;
        return;
    }

    newNode->info = value;
    newNode->ant = nullptr;
    newNode->prox = head;

    // CORREÇÃO: Se a lista estiver vazia, o newNode também será o tail!
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Se já tinha gente, o antigo head precisa apontar para trás para o novo nó
    head->ant = newNode;
    head = newNode;
}

void DoublyList::insertAtEnd(int value) {
    Node *newNode = new Node;
    if (newNode == nullptr) {
        cout << "No memory" << endl;
        return;
    }

    newNode->info = value;
    newNode->prox = nullptr; 
    newNode->ant = nullptr;  

    if (head == nullptr) { 
        head = newNode; 
        tail = newNode; 
        return;
    }

    tail->prox = newNode;
    newNode->ant = tail; 
    tail = newNode;
}

// CORREÇÃO: Implementação do seu método remove convencional para listas normais
void DoublyList::remove(int value) {
    if (head == nullptr) {
        cout << "Empty list." << endl;
        return; // Melhor usar return do que fechar o programa com exit(1)
    }

    Node *aux = head;

    // Busca o elemento
    while (aux != nullptr && aux->info != value) {
        aux = aux->prox;
    }

    // Se não encontrou o valor
    if (aux == nullptr) {
        cout << "Value " << value << " not found." << endl;
        return;
    }

    // CASO 1: É o único elemento da lista
    if (aux->ant == nullptr && aux->prox == nullptr) {
        head = nullptr;
        tail = nullptr;
    }
    // CASO 2: É o primeiro elemento (head)
    else if (aux->ant == nullptr) {
        head = aux->prox;
        head->ant = nullptr;
    }
    // CASO 3: É o último elemento (tail)
    else if (aux->prox == nullptr) {
        tail = aux->ant;
        tail->prox = nullptr;
    }
    // CASO 4: Está no meio
    else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }

    delete aux; // Deleta o nó correto da memória
}

// FINALIZAÇÃO: Imprime do início ao fim usando o 'head' e 'prox'
void DoublyList::printForward() {
    if (head == nullptr) {
        cout << "Empty list." << endl;
        return;
    }

    Node *aux = head;
    cout << "Forward:  ";
    while (aux != nullptr) {
        cout << "[" << aux->info << "] ";
        aux = aux->prox;
    }
    cout << endl;
}

// FINALIZAÇÃO: Imprime do fim para o início usando o 'tail' e 'ant'
void DoublyList::printBackward() {
    if (tail == nullptr) {
        cout << "Empty list." << endl;
        return;
    }

    Node *aux = tail;
    cout << "Backward: ";
    while (aux != nullptr) {
        cout << "[" << aux->info << "] ";
        aux = aux->ant; // Volta para trás!
    }
    cout << endl;
}