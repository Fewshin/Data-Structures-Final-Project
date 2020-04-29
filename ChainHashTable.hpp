#include <iostream>
#include <vector>
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
        vector<int> createCollisionCounts;
    public:
        ChainHashTable();
        void insert(int key, int trialNum);
        int search(int key);
        vector<float> createTable(int size, long * input);
};