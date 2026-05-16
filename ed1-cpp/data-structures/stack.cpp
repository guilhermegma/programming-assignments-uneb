#include <iostream>

using namespace std;

class Node {
public:
    int info;
    Node *prox;
};

class Stack {

public:
    Node *top;

    Stack::Stack() {
        top = nullptr;
    }

    void push(int number);
    int pop();
    void printStack();
};

void Stack::push(int number) {
    Node *newNode = new Node;

    if (newNode == nullptr) {
        cout << "No memory" << endl;
        exit(1);
    }

    newNode->info = number;

    // 1. O novo nó aponta para onde o topo atual está apontando (o antigo topo)
    newNode->prox = top;

    // 2. O topo da lista agora passa a ser o seu novo nó
    top = newNode;
}

int Stack::pop() {
    if  (top == nullptr) {
        cout<<"Empty stack"<< endl;
        exit(1);
    }

    Node *aux = top;
    int popped;

    popped = aux->info;
    top = aux->prox;
    delete aux;

    return popped;
}

void Stack::printStack () {
    if  (top == nullptr) {
        cout<<"Empty stack"<< endl;
        exit(1);
    }

    Node *aux = top;

    cout<<"Stack:";

    while (aux!= nullptr) {
        cout<<" ["<<aux->info<<"]";
        aux = aux->prox;
    }

    cout<<" <-End of stack"<< endl;
}