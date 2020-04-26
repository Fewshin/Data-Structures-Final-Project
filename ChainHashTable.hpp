#include <iostream>
using namespace std;

struct cHashNode {
    int key;
    bool isStoring = false; 
    cHashNode *next = NULL;
};

class ChainHashTable {
    private:
        int tableSize = 40009;
        cHashNode hashTable[40009];
    
    public:
        ChainHashTable();
        void insert(int key);
        int search(int key);
};