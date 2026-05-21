#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int info;
    Node *prox;
};

class Node2 {
public:
    int info, count;
    Node2 *prox;
    Node2 *ant;
};

class DoublyList {
public:
    Node2 *head;
    Node2 *tail;

    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int number, int count) {
        Node2 *newNode = new Node2;
        if (newNode == nullptr) {
            cout << "No memory" << endl;
            exit(1);
        }
        newNode->info = number;
        newNode->count = count;
        newNode->prox = nullptr;

        if (head == nullptr) {
            newNode->ant = nullptr;
            head = newNode;
            tail = newNode;
        } else {
            newNode->ant = tail;
            tail->prox = newNode;
            tail = newNode;
        }
    }
};

class SinglyList {
public:
    Node *head;

    SinglyList() {
        head = nullptr;
    }

    void insertAtBeginning(int number);
    void compress(DoublyList &dl);
    void print();
};

void SinglyList::insertAtBeginning(int number) {
    if (number != 0 && number != 1) {
        cout << "Invalid number. Only 0 or 1 allowed." << endl;
        exit(1);
    }

    Node *newNode = new Node;
    if (newNode == nullptr) {
        cout << "No memory" << endl;
        exit(1);
    }

    newNode->info = number;
    newNode->prox = head;
    head = newNode;
}

void SinglyList::print() {
    Node *aux = head;
    while (aux != nullptr) {
        cout << aux->info;
        if (aux->prox != nullptr) cout << " -> ";
        aux = aux->prox;
    }
    cout << endl;
}

void SinglyList::compress(DoublyList &dl) {
    if (head == nullptr) {
        cout << "Empty list." << endl;
        return;
    }

    Node *aux = head;

    while (aux != nullptr) {
        int number = aux->info;
        int counter = 1;

        while (aux->prox != nullptr && aux->prox->info == number) {
            counter++;
            aux = aux->prox;
        }

        dl.insertAtEnd(number, counter);

        aux = aux->prox;
    }
}

void unpack(DoublyList &dl, SinglyList &sl) {
    if (dl.head == nullptr) {
        cout << "Empty doubly linked list." << endl;
        return;
    }

    Node2 *aux2 = dl.head;

    while (aux2 != nullptr) {
        for (int i = 0; i < aux2->count; i++) {
            sl.insertAtBeginning(aux2->info);
        }
        aux2 = aux2->prox;
    }
}

void printDoublyList(DoublyList &dl) {
    Node2 *aux = dl.head;
    while (aux != nullptr) {
        cout << "[" << aux->info << "," << aux->count << "]";
        if (aux->prox != nullptr) cout << " <-> ";
        aux = aux->prox;
    }
    cout << endl;
}

int main() {
    SinglyList sl;
    int n, value;

    cout << "Singly Linked List Builder" << endl;
    cout << "How many numbers do you want to insert? ";
    cin >> n;

    cout << "Enter " << n << " numbers (only 0 or 1), from last to first" 
         << " (they will be inserted at the beginning): " << endl;

    for (int i = 0; i < n; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> value;
        sl.insertAtBeginning(value);
    }

    cout << "\nSingly linked list: ";
    sl.print();

    cout << "Question 1: Compressing" << endl;
    DoublyList dl;
    sl.compress(dl);
    cout << "Doubly linked list (value, count): ";
    printDoublyList(dl);

    cout << "Question 2: Reconstructing in reverse order" << endl;
    SinglyList sl2;
    unpack(dl, sl2);
    cout << "Reconstructed singly linked list (reversed): ";
    sl2.print();

    return 0;
}

