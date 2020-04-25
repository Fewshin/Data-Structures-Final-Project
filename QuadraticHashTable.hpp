#include <iostream>
using namespace std;

struct qHashNode {
    int key;
    bool isStoring = false;
};

class QuadraticHashTable {
    private:
        int tableSize = 40009;
        qHashNode hashTable[40009];

    public:
        QuadraticHashTable();
        void insert(int key);
        int search(int key);
};