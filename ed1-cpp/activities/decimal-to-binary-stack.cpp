#include <iostream>
#include <cstdlib>
#include <cmath>
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

    Stack() {
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
    int dec = 0;
    int aux[size];
    int count = 0;

    for (int i = 0; i < size; i++) {
        aux[i] = binaryNumber[i];
    }

    for (int i = 0; i < size; i++) {
        stack.push(aux[i]);
    }

    cout<< "The binary number ";

    for (int i = 0; i < size; i++) {
        cout<< "["<< aux[i] << "] ";
    }

    cout<< " in converted into a decimal number is: ";

    
    while (stack.top != nullptr) {
        dec += stack.pop() * round(pow(2, count));
        cout<< " * 2^"<< count<< " + ";
        count += 1;
    }

    cout<< " = "<< dec <<endl;
    
}

int main() {
    int choice;
    int decimal;
    int size;
    int binaryNumber[32];

    while(true) {
        cout << "Tap 0 to convert a decimal number to a binary or 1 to convert a binary to a decimal: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Enter a number: ";
            cin >> decimal;
            decimalToBinary(decimal);
            break;

        case 1:
            cout << "Enter the size of the binary number (max 32): ";
            cin >> size;
            
            if (size > 32 || size <= 0) {
                cout << "Invalid size! Please enter a value between 1 and 32." << endl;
                break;
            }

            for (int i = 0; i < size; i++) {
                cout << "Tap the " << i + 1 << " binary number: ";
                cin >> binaryNumber[i];
            }
            
            binaryToDecimal(binaryNumber, size);
            break;

        default:
            cout << "Invalid value...try again" << endl;
            break;
        }
        
        cout << "\n--------------------------------------------------\n" << endl; 
    }
    
    return 0;
}
