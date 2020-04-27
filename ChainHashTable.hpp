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
        int createTable(int size);
        void insert(int key);
        int search(int key);
};