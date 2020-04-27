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

vector<float> LinkedList::createList(long * input) {
    vector<float> insert;
    clock_t start, end;

    for(int i = 0; i < 400; i++) {
        start = clock();
        for(int j = (i * 100); j < (100 + i * 100); j++) {
            insert((int) input[j]);
        }
        end = clock();
        float avgTime = float(end - start) / (float(CLOCKS_PER_SEC) * 100);
        insert.push_back(avgTime);
    }
    return insert;
}

vector<float> LinkedList::searchList(long * input) {
    vector<float> search;
    clock_t start, end;

    for(int i = 0; i < 40000; i++) {
        insert((int) input[i])
    }

    for(int i = 0; i <= 40000; i = i + 100) {
        int set[100];
        for(int j = 0; j < 100; j++)
            set[j] = rand() % (i + 100);
        start = clock();
        for(int k = 0; k < 100; k++) {
            bool t = searchList(set[k]);
        }
        end = clock();
        float avgTime = float(end - start) / (float(CLOCKS_PER_SEC) * 100);
        search.push_back(avgTime);
    }
    return search;
}