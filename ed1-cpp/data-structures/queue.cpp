#include <iostream>
#include <ctime> 
#include <cstdlib>

using namespace std;

class Node {
public:
    int info;
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

    void insert(int number);
    int remove();
    void print();
};

void queue::insert(int number) {
    Node *newNode = new Node;

    if (newNode == nullptr) {
        cout << "No memory" << endl;
        exit(1);
    }

    newNode->info = number;
    newNode->prox = nullptr;

    if (front == nullptr) {
        front = newNode;
        back = newNode;
    } else {
        back->prox = newNode;
        back = newNode;
    }
}

int queue::remove() {
    if (front == nullptr) {
        cout << "Empty queue" << endl;
        exit(1);
    }

    Node *aux = front;
    int removedNumber = aux->info;

    front = front->prox;

    if (front == nullptr) {
        back = front;
    }

    delete aux;
    return removedNumber;
}

void queue::print() {
    if (front == nullptr) {
        cout << "Empty queue" << endl;
        exit(1);
    }

    Node *aux = front;

    cout << "Queue: ";

    while (aux != nullptr) {
        cout << " [" << aux->info << "]";
        aux = aux->prox;
    }

    cout << endl;
}