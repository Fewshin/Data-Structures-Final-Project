/*
Authors:
- Felix Pawlowski (bug fixes, retrieving file data)
- Kenneth Strieker (functions, function timing, writing to files)
*/

#include <iostream>
#include <vector>

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
        std::vector<float> createTree(long * input);
        std::vector<float> searchTree(long * input);
};