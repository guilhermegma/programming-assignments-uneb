#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int info;
    Node *prox;
    Node *ant;
};

class Vector {
public:
    Node *head;
    Node *tail;

    Vector() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int n);
    void remove(int n); // Mudei para void porque a função exibe mensagens e não retorna um inteiro
};

void Vector::insert (int n) {
    Node *newNode = new Node;
    newNode->info = n;

    if (head == nullptr) {
        newNode->prox = nullptr;
        newNode->ant = nullptr;
        head = newNode;
    } else {
        newNode->ant = tail;
        tail->prox = newNode;
    }
    tail = newNode;
    newNode->prox = nullptr;
}

void Vector::remove (int n) {
    if (head == nullptr) {
        cout << "Empty list." << endl;
        return; // Retorno vazio condizente com 'void'
    }

    Node *aux = head;

    while (aux != nullptr) {
        if (aux->info == n) {
            // AJUSTE ESSENCIAL: removeAnt e removeProx movidos para cá!
            // Agora eles capturam os vizinhos reais do 'aux' atual onde o 'n' foi encontrado.
            Node *removeAnt = aux->ant;
            Node *removeProx = aux->prox;

            if (aux->ant == nullptr && aux->prox == nullptr) {
                cout << "The value " << n << " is the only number in the list." << endl;
                head = nullptr;
                tail = nullptr;
                delete aux; // Limpa o único elemento remanescente
                return;
            } 
            else if (aux->ant == nullptr) { // Cenario: N está no início, deleta o SUCESSOR
                aux->prox = removeProx->prox;
                if (removeProx->prox != nullptr) {
                    removeProx->prox->ant = aux;
                } else {
                    tail = aux; // Se o sucessor era o último, aux vira o novo tail
                }
                delete removeProx;
            } 
            else if (aux->prox == nullptr) { // Cenario: N está no fim, deleta o ANTECESSOR
                aux->ant = removeAnt->ant;
                if (removeAnt->ant != nullptr) {
                    removeAnt->ant->prox = aux;
                } else {
                    head = aux; // Se o antecessor era o primeiro, aux vira o novo head
                }
                delete removeAnt;
            } 
            else if (aux->prox != nullptr && aux->ant != nullptr) { // Cenario: N está no meio, deleta AMBOS
                // Remove o Antecessor (removeAnt)
                aux->ant = removeAnt->ant;
                if (removeAnt->ant != nullptr) {
                    removeAnt->ant->prox = aux;
                } else {
                    head = aux;
                }
                delete removeAnt;

                // Remove o Sucessor (removeProx)
                aux->prox = removeProx->prox;
                if (removeProx->prox != nullptr) {
                    removeProx->prox->ant = aux;
                } else {
                    tail = aux;
                }
                delete removeProx;
            }
            
            // Avança o aux após a remoção dos vizinhos e encerra a função
            aux = aux->prox;
            return; 
        } else {
            // Avança o aux caso o elemento atual não seja o valor N buscado
            aux = aux->prox;
        }
    }
    
    cout << "There is no " << n << " in the list." << endl;
}