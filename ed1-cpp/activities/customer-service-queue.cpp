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
    
    // NOVO MÉTODO: Essencial para checar se a fila está vazia com segurança
    bool isEmpty() {
        return front == nullptr;
    }
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
    cout << removedNumber;
    return removedNumber;
}

void Queue::print() {
    // AJUSTE: Removido o exit(1) para o menu não fechar o programa ao tentar exibir filas vazias
    if (front == nullptr) {
        cout << "Empty line";
        return;
    }

    Node *aux = front;

    while (aux != nullptr) {
        cout << " [" << aux->info << "]";
        aux = aux->prox;
    }
}

void priorityQueue(int password, Queue &priority) {
    priority.insert(password);
}

void regularQueue(int password, Queue &regular) {
    regular.insert(password);
}

void displayQueues (Queue &priority, Queue &regular) {
    cout << "\n--- Current Lines ---" << endl;
    cout << "Priority Line: ";
    priority.print();
    cout << "\nRegular Line: ";
    regular.print();
    cout << "\n---------------------" << endl;
}

// FUNÇÃO ATUALIZADA: Agora com as checagens de segurança solicitadas
void callNextToBeServed(Queue &priority, Queue &regular, int &priorityCounter) {
    
    // 1. Cenário Crítico: Ninguém em nenhuma das filas
    if (priority.isEmpty() && regular.isEmpty()) {
        cout << "No customers waiting in any line." << endl;
        return;
    }

    // 2. Regra dos 3 prioritários: Se atingiu o limite E tem alguém na comum, o comum passa na frente
    if (priorityCounter >= 3 && !regular.isEmpty()) {
        cout << "Please go to the service counter ticket C";
        regular.remove();
        priorityCounter = 0; // Reseta porque atendeu um comum
    } 
    // 3. Caso padrão: Se houver alguém na prioritária, atende a prioridade
    else if (!priority.isEmpty()) {
        cout << "Please go to the service counter ticket P";
        priority.remove();
        priorityCounter++; // Soma 1 no contador de prioritários seguidos
    } 
    // 4. Se a prioritária estiver vazia, mas ainda houver pessoas na comum
    else {
        cout << "Please go to the service counter ticket C";
        regular.remove();
        priorityCounter = 0; // Reseta por segurança
    }
}

int main() {
    int age;
    int password = 0;
    int option = 0;
    int priorityCounter = 0;
    bool enterAge = true; 
    Queue priority;
    Queue regular;

    while (option != 4) {
        cout << "\n=================================" << endl;
        cout << "    CUSTOMER SERVICE SYSTEM      " << endl;
        cout << "=================================" << endl;
        cout << " 1. Issue a New Ticket (New User)" << endl;
        cout << " 2. Call Next to be Served       " << endl;
        cout << " 3. Display Current Queues       " << endl;
        cout << " 4. Exit System                  " << endl;
        cout << "=================================" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            enterAge = true;
            cout << "Welcome! " << endl;
            cout << "Please enter your age: ";

            while(enterAge) {
                cin >> age;

                if (age >= 60) {
                    priorityQueue(password, priority);
                    password ++;
                    enterAge = false;
                } else if (age > 0 && age < 60) {
                    regularQueue(password, regular);
                    password ++;
                    enterAge = false;
                } else {
                    cout << "Invalid Age...please try again: ";
                }
            }
            break;
        
        case 2:
            callNextToBeServed(priority, regular, priorityCounter);
            cout << endl;
            break;
        
        case 3:
            displayQueues(priority, regular);
            break;
        
        case 4:
            cout << "Quitting..." << endl;
            break;
        
        default:
            cout << "Invalid number...try again." << endl;
            break;
        }
    }

    return 0;
}