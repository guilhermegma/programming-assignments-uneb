#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int info;
    Node *prox;
};

class SinglyList {
private:
    Node *head;
public:
    SinglyList() {
        head = nullptr;
    }

    void insertAtBeginning (int number);
    void insertOrdered (int number);
    void remove (int number);
    void print();
};

void SinglyList::insertAtBeginning(int number) {
    Node *newNode = new Node;

    if (newNode == nullptr) {
        cout << "No memory" << endl;
        exit(1);
    }

    newNode -> info = number; 
    newNode->prox = head;
    head = newNode;

}

void SinglyList::insertOrdered(int number) {
    Node *newNode = new Node;
    Node *current = head;
    Node *previous = nullptr;

    if (newNode == nullptr) {
        cout << "No memory" << endl;
        exit(1);
    }

    newNode->info = number;
    
    while (current != nullptr && newNode->info >= current->info) {
        previous = current;
        current = current->prox;
    }

    if (previous == nullptr) {
        newNode->prox = head;
        head = newNode;
    } else {
        previous->prox = newNode;
        newNode->prox = current;
    }
}

void SinglyList::remove (int number) {
    Node *current = head;
    Node *previous = nullptr;

    if (head == nullptr) {
        cout << "Empty list." << endl;
        exit(1);
    }

    while (current != nullptr && current->info != number) {
        previous = current;
        current = current->prox;
    }

    if (current == nullptr) {
        cout << "There is no "<< number << " in the list." << endl;
    } else if (previous == nullptr) {
        head = current->prox;
    } else {
        previous->prox = current->prox;
    }

    delete current;
}