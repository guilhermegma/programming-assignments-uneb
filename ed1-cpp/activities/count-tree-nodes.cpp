#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public: 
    int info;
    Node *left, *right;
};

class tree {
public:
   Node *root;
   tree() {
    root = nullptr;
   }
   Node* insert(Node *root, int n); 
   Node *remove(Node *root, int n);
   Node *searchSuccessor(Node *sus, int n, Node *root);
   int count(Node *root);
};

Node* tree::insert (Node *root, int n) {
    if (root == nullptr) {
        root = new Node;
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
Node* tree::remove (Node *root, int n) {
    Node *aux;
    if (root == nullptr) {
        return root;
    } 
    if (root->info < n) {
        root->right = remove(root->right, n); 
    }
    else if (root->info > n) {
        root->left = remove(root->left, n);
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

int tree::count (Node *root) {
    if (root == nullptr) {
        return 0;
    }

    return (count(root->left) + 1 + count(root->right));
}