class Node {
    int info;
    Node *left, *right;
};

class tree{
public:
   
}

node *tree::insert (node *root, int n) {
    if (root == nullptr) {
        root = newNode();
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