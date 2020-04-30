#include "BST.hpp"
#include <time.h>
#include <chrono>
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
          return NULL;
        }
        current->right->parent = current;
    }

    else if(current->key > x) {
        current->left = addNodeHelper(current->left, x);
        if (current->left == NULL) {
          return NULL;
        }
        current->left->parent = current;
    }
    else {
    }

    return current;
}

void BST::addNode(int x) {
    root = addNodeHelper(root, x);
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

vector<float> BST::createTree(long * input) {
    vector<float> insert;
    for(int i = 0; i < 400; i++) {
        auto start = chrono::steady_clock::now();
        for(int j = (i * 100); j < (100 + i * 100); j++) {
            addNode((int) input[j]);
        }
        auto end = chrono::steady_clock::now();
        auto avgTime = chrono::duration_cast<chrono::nanoseconds>((end - start) / 100).count();
        insert.push_back(avgTime);
    }
    return insert;
}

vector<float> BST::searchTree(long * input) {
    vector<float> search;
    for(int i = 0; i <= 40000; i = i + 100) {
        int set[100];
        for(int j = 0; j < 100; j++)
            set[j] = rand() % (i + 100);
        auto start = chrono::steady_clock::now();
        for(int k = 0; k < 100; k++) {
            bool t = searchKey(input[set[k]]);
        }
        // end = clock();
        // end = time(NULL);
        auto end = chrono::steady_clock::now();
        auto avgTime = chrono::duration_cast<chrono::nanoseconds>((end - start) / 100).count();
        search.push_back(avgTime);
    }
    return search;
}