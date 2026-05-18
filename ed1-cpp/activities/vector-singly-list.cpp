#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int info;
    Node *prox;
};

class Vector {
private:
    Node *head;
public: 
    Vector() {
        head = nullptr;
    }

    int size(); 
    void append(int value);
    void insertAtPosition(int value, int position);
    void remove(int value); 
    void order(); 
    void print(); 
};

int Vector::size() {
    Node *aux = head;
    int sizeOfVector = 0;

    if (head == nullptr) {
        return sizeOfVector;
    }

    while (aux != nullptr) {
        aux = aux->prox;
        sizeOfVector += 1;
    }

    return sizeOfVector;

}

void Vector::append(int value) {
    Node *newNode = new Node;

    if (newNode == nullptr) {
        cout << "No memory" << endl;
        return;
    }

    newNode->info = value;
    newNode->prox = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node *aux = head;
    while (aux->prox != nullptr) {
        aux = aux->prox;
    }

    aux->prox = newNode;
}

void Vector::insertAtPosition(int value, int position) {
    if (position < 0 || position > size()) {
        cout << "Invalid position." << endl;
        return;
    }

    Node *newNode = new Node;
    if (newNode == nullptr) {
        cout << "No memory" << endl;
        return;
    }
    newNode->info = value;

    if (head == nullptr || position == 0) {
        newNode->prox = head;
        head = newNode;
        return;
    }

    // Insertion at the middle or at the end
    Node *current = head;
    Node *previous = nullptr;
    int counter = 0;

    while (current != nullptr && counter != position) {
        previous = current;
        current = current->prox;
        counter += 1;
    }

    previous->prox = newNode;
    newNode->prox = current;
}

void Vector::remove (int value) {
    Node *current = head;
    Node *previous = nullptr;

    if (head == nullptr) {
        cout << "Empty vector.";
        return;
    }

    while (current != nullptr && current->info != value) {
        previous = current;
        current = current->prox;
    }

    if (current == nullptr) {
        cout << "There is no " << value << " in the list";
        return;
    } else if (previous == nullptr) {
        head = current->prox;
    } else {
        previous->prox = current->prox;
    }
    
    delete current;
}

void Vector::order() {
    if (head == nullptr || head->prox == nullptr) {
        return; 
    }

    Node *i;
    Node *j;
    int aux;

    // Bubble Sort 
    for (i = head; i->prox != nullptr; i = i->prox) {
        for (j = i->prox; j != nullptr; j = j->prox) {
            if (i->info > j->info) {
                aux = i->info;
                i->info = j->info;
                j->info = aux;
            }
        }
    }
}

void Vector::print () {
    if (head == nullptr) {
        cout << "Empty vector.";
        return;
    }

    Node *aux = head;

    cout << "Vector: ";

    while (aux != nullptr) {
        cout << "[" << aux->info << "] ";
        aux = aux->prox;
    }

    cout << endl;
}