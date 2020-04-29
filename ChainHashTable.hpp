#include <iostream>
using namespace std;

struct cHashNode {
    int key;
    bool isStoring = false; 
    cHashNode *next = NULL;
};

class ChainHashTable {
    private:
        int * tableSize;
        cHashNode * hashTable;
    
    public:
        ChainHashTable();
        void insert(int key);
        int search(int key);
        int createTable(int size, long * input);
};