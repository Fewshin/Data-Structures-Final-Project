#include "LinkedList.hpp"
#include <chrono>
using namespace std;

void LinkedList::addToList(int newKey) {
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

vector<float> LinkedList::createList(long * input) {
    vector<float> insert;

    for(int i = 0; i < 400; i++) {
        auto start = chrono::steady_clock::now();
        for(int j = (i * 100); j < (100 + i * 100); j++) {
            addToList((int) input[j]);
        }
        auto end = chrono::steady_clock::now();
        auto avgTime = chrono::duration_cast<chrono::nanoseconds>((end - start) / 100).count();
        insert.push_back(avgTime);
    }
    return insert;
}

vector<float> LinkedList::searchList(long * input) {
    vector<float> search;

    for(int i = 0; i < 40000; i++) {
        addToList((int) input[i]);
    }

    for(int i = 0; i <= 40000; i = i + 100) {
        int set[100];
        for(int j = 0; j < 100; j++)
            set[j] = rand() % (i + 100);
        auto start = chrono::steady_clock::now();
        for(int k = 0; k < 100; k++) {
            bool t = searchList(set[k]);
        }
        auto end = chrono::steady_clock::now();
        auto avgTime = chrono::duration_cast<chrono::nanoseconds>((end - start) / 100).count();
        search.push_back(avgTime);
    }
    return search;
}