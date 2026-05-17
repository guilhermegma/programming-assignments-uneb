#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int info;
    Node *prox;
};

class Stack{
private:
public:
    Node *top;

    Stack::Stack() {
        top = nullptr;
    }

    void push(int number);
    int pop();
    void print();
};

void Stack::push (int number) {

    Node *newNode = new Node;

    if (newNode == nullptr) {
        cout << "No memory" << endl;
        exit(1);
    }

    newNode->info = number;
    newNode->prox = top;
    top = newNode;
}

int Stack::pop () {

    if (top == nullptr) {
        cout << "Stack empty" << endl;
        exit(1);
    }

    Node *aux = top;
    int poppedNumber;

    poppedNumber = aux->info;
    top = aux->prox;
    delete aux;

    cout << "[" << poppedNumber << "]";
    return poppedNumber;
}

void Stack::print (){

    if (top == nullptr) {
        cout << "Stack empty" << endl;
        exit(1);
    }

    Node *aux = top;

    cout << "Stack:";

    while (aux != nullptr) {
        cout << "[ " << aux->info << "] ";
        aux = aux->prox;
    }

    cout << " <- End of stack" <<endl;
}

void decimalToBinary(int decimalNumber) {

    Stack stack;
    int bin;
    int aux = decimalNumber;

    while(aux != 0) {
        bin = aux%2;
        stack.push(bin);
        aux = aux/2;
    }

    cout << "THe decimal number [" << decimalNumber << "] in binary is: ";

    while(stack.top != nullptr) {
        stack.pop();
    }

}

void binaryToDecimal(int binaryNumber[], int size) {

    Stack stack;
    int dec;
    int aux[size];
    int count = 0;

    for (int i = 0; i <= size; i++) {
        aux[i] = binaryNumber[i];
    }

    for (int i = 0; i <= size; i++) {
        while (aux [i] <= size) {
            stack.push(aux[i]);
        }
    }

    cout<< "The binary number ";

    for (int i = 0; i <= size; i++) {
        cout<< "["<< aux[i] << "] ";
    }

    cout<< " in converted into a decimal number is: ";

    
    while (stack.top != nullptr) {
        dec += stack.pop() * (2^count);
        cout<< " * 2^"<< count<< " + ";
    }

    cout<< " = "<< dec <<endl;
    
}

void 

int main() {
    
    return 0;
}
