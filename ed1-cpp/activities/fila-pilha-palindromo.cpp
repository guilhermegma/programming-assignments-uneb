#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Node {
public:
    char info;
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

    void insert(char character);
    char remove();
    void print();
};

void Queue::insert(char character) {
    Node *newNode = new Node;

    if (newNode == nullptr) {
        cout << "No memory" << endl;
        exit(1);
    }

    newNode->info = character;
    newNode->prox = nullptr;

    if (front == nullptr) {
        front = newNode;
        back = newNode;
    } else {
        back->prox = newNode;
        back = newNode;
    }
}

char Queue::remove() {
    if (front == nullptr) {
        cout << "Empty queue" << endl;
        exit(1);
    }

    Node *aux = front;
    char removedCharacter = aux->info;

    front = front->prox;

    if (front == nullptr) {
        back = front;
    }

    delete aux;
    return removedCharacter;
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

    Stack() {
        top = nullptr;
    }

    void push(char character);
    char pop();
    void printStack();
};

void Stack::push(char character) {
    Node *newNode = new Node;

    if (newNode == nullptr) {
        cout << "No memory" << endl;
        exit(1);
    }

    newNode->info = character;

    // 1. O novo nó aponta para onde o topo atual está apontando (o antigo topo)
    newNode->prox = top;

    // 2. O topo da lista agora passa a ser o seu novo nó
    top = newNode;
}

char Stack::pop() {
    if  (top == nullptr) {
        cout<<"Empty stack"<< endl;
        exit(1);
    }

    Node *aux = top;
    char popped;

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
    int i = 0;
    int auxi = 0;
	Stack p;
	Queue f;
	string word;
	char c = 'x';
    bool isPalindrome = true;

    cout << "Type a word and we'll verify if it's a palindrome: " << endl;
	cin >> word;

	while (c != '\0') {
		c = word [i];
        if (c != '\0') {
            f.insert (c);
		    p.push (c);
		    i++;
        }
	}

    while(p.top != nullptr){
        char aux = p.pop();
        char aux2 = f.remove();

        if (aux != aux2) {
            cout << "The word isnt a palindrome.";
            isPalindrome = false;
            break;
        }
        auxi++;
    }

    if (auxi == i) {
        cout << "The word is a palindrome.";
    }

    return isPalindrome;
}

//for each 
//fazer função desempilhar e retirar
//chamar ela retornando o char