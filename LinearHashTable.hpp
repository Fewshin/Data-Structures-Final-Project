#include <iostream>
using namespace std;

struct lHashNode {
    int key;
    bool isStoring = false;
};

class LinearHashTable {
    private:
        int tableSize = 40009;
        lHashNode hashTable[40009];

    public:
        LinearHashTable();
        void insert(int key);
        int search(int key);
};