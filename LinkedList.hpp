#include <iostream>

struct llNode {
    int key;
    llNode *next;
};

class LinkedList {
    private:
        llNode *head;

    public:
        LinkedList() {
            head = NULL;
        }
        void insert(int newKey);
        llNode *searchList(int key);
        void printList();
};