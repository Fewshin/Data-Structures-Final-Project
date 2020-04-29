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
        vector<int> searchCollisionCounts;
    public:
        ChainHashTable();
        void insert(int key, int trialNum);
        int search(int key, int trialNum);
        vector<float> createTable(int size, long * input);
        vector<float> searchTable(int size, long * input);
        int numOfInsertCollisions(int index);
        int numOfSearchCollisions(int index);
};