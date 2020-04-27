#include <iostream>

struct Node {
    int key;
    Node *parent;
    Node *left;
    Node *right;
};

class BST {
    private:
        Node *root;

    public:
        BST();
        //Node* addNodeHelper(Node * current, int x);
        void addNode(int x);
        bool searchKey(int x);
        void printTree();
        int createTree(long * input);
};