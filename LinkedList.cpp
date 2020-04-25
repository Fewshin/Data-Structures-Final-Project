#include "LinkedList.hpp"
using namespace std;

void LinkedList::insert(int newKey) {
    if(head == NULL) {
        head = new llNode;
        head->key = newKey;
        head->next = NULL;
    }

    else {
        llNode *lastNode = head;
        while(lastNode->next != NULL)
            lastNode = lastNode->next;
        llNode *addNode = new llNode;
        addNode->key = newKey;
        addNode->next = NULL;
        lastNode->next = addNode;
    }
}

llNode* LinkedList::searchList(int key) {
    llNode *ptr = head;
    while(ptr != NULL && ptr->key != key)
        ptr = ptr->next;
    return ptr;
}

void LinkedList::printList() {
  llNode *temp = head;
  while(temp->next != NULL) {
    cout << temp->key << " -> ";
    temp = temp->next;
  }
  cout << temp->key << endl;
}