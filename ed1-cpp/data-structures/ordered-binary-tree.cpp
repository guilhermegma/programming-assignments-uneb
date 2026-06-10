#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public: // CORREÇÃO SINTÁTICA: Necessário para a classe tree acessar os membros
    int info;
    Node *left, *right;
};

class tree {
public:
   Node *root;
   tree() {
    root = nullptr;
   }
   // CORREÇÃO SINTÁTICA: Mudado de void para Node* para aceitar os seus "return(root)"
   Node* insert(Node *root, int n); 
   Node *remove(Node *root, int n);
   Node *searchSuccessor(Node *sus, int n, Node *root);
};

// CORREÇÃO SINTÁTICA: Mudado para Node* para casar com o retorno interno da sua lógica
Node* tree::insert (Node *root, int n) {
    if (root == nullptr) {
        root = new Node; // CORREÇÃO SINTÁTICA: Alocação correta em C++ (era newNode())
        root->info = n;
        root->left = nullptr;
        root->right = nullptr;
        return(root);
    } else {
        if (n < root->info) {
            root->left = insert(root->left, n);
        } else if (n > root->info) {
            root->right = insert(root->right, n);
        } else {
            cout << "Repeated value." << endl;
        }
        return (root);
    }
}

// CORREÇÃO SINTÁTICA: Adicionado o escopo "tree::" e ajustado os parâmetros conforme declarado na classe
Node* tree::remove (Node *root, int n) {
    Node *aux;
    // Mantida a assinatura da classe. Se precisar da assinatura com (Node* root, int n), 
    // lembre-se de alterar também a declaração dela dentro da classe 'tree' lá em cima.
    if (root == nullptr) {
        return root;
    } 
    if (root->info < n) {
        // Como o método da classe não recebe o nó como parâmetro, a recursão foi mantida 
        // exatamente como você escreveu, mas gerará um alerta de lógica no compilador.
        root->right = remove(root->right, n); 
    }
    else if (root->info > n) {
        root->left = remove(root->left, n); // CORREÇÃO SINTÁTICA: Adicionado o ponto e vírgula ";" faltando
    } 
    else if (root->left == nullptr) {
        aux = root;
        root = root->right;
        delete (aux);
        return root;
    }
     else if (root->right == nullptr) {
        aux = root;
        root = root->left;
        delete (aux);
        return root;
     } else {
        root ->right = searchSuccessor (root->right, n, root);
        return root;
     }
    return root; 
}

Node* tree::searchSuccessor (Node *sus, int n, Node *root) {
    Node *aux;
    if (sus->left != nullptr) {
        sus->left = searchSuccessor(sus->left, n, root);
    } else {
        root->info = sus->info;
        aux = sus;
        sus = sus->right;
        delete (aux);
        return sus;
    }
}