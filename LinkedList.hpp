/*
Authors:
- Felix Pawlowski (function timing, bug fixes, retrieving file data)
- Kenneth Strieker (functions, writing to files)
*/

#include <iostream>
#include <vector>

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
        void addToList(int newKey);
        llNode *searchList(int key);
        void printList();
        std::vector<float> createList(long * input);
        std::vector<float> searchList(long * input);
};