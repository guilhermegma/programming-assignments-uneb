#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int info;
    Node *prox;
};

class Queue {
    Node *front;
    Node *back;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    void insert(int number);
    int remove();
    void print();
};

void Queue::insert(int number) {
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

int Queue::remove() {
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

void Queue::print() {
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

int main() {
	Stack p;
	Queue f;
	string palavra;
	char c;
    bool ehPalindromo = true;

    cout << "Informe uma palavra, verificaremos se é um palindromo: " << endl;
	cin >> palavra;
	int i = 0;

	while (c != '\0') {
		c = palavra [i];
		f.insert (c);
		p.push (c);
		i++;
	}

    while(p.top != nullptr){
        char aux = p.pop;
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