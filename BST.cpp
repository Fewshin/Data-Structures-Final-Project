#include "BST.hpp"
using namespace std;

BST::BST() {
    root = NULL;
}

Node* addNodeHelper(Node *current, int x) {
    if(current == NULL) {
        Node *newNode = new Node;
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
        return newNode;
    }

    else if(current->key < x) {
        current->right = addNodeHelper(current->right, x);
        if (current->right == NULL) {
          printf("Node failed to be created\n");
          return NULL;
        }
        current->right->parent = current;
    }

    else if(current->key > x) {
        current->left = addNodeHelper(current->left, x);
        if (current->left == NULL) {
          printf("Node failed to be created\n");
          return NULL;
        }
        current->left->parent = current;
    }
    else {
      printf("Key of child node is equal to parent node.\n");
    }

    return current;
}

void BST::addNode(int x) {
    root = addNodeHelper(root, x);
    cout << x << " has been added" << endl;
}

Node* searchKeyHelper(Node *current, int x) {
    if(current == NULL)
        return NULL;
    
    if(current->key == x)
        return current;

    if(current->key > x)
        return searchKeyHelper(current->left, x);
    
    else
        return searchKeyHelper(current->right, x);
}

bool BST::searchKey(int key) {
    Node *tree = searchKeyHelper(root, key);
    if(tree != NULL)
        return true;
    cout << "Key not present in the tree" << endl;
    return false;
}

void printTreeHelper(Node *current) {
    if(current) {
        printTreeHelper(current->left);
        cout << " " << current->key;
        printTreeHelper(current->right);
    }
}

void BST::printTree() {
    printTreeHelper(root);
    cout << endl;
}