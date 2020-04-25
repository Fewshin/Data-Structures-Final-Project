#include <iostream>

struct Node {
    int key;
    Node *left;
    Node *right;
};

class BST {
    private:
        Node *root;

    public:
        BST();
        void addNode(int x);
        bool searchKey(int x);
        void printTree();
};