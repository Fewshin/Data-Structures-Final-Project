#include <iostream>
using namespace std;

struct lHashNode {
    int key;
    bool isStoring = false;
};

class LinearHashTable {
    private:
        int * tableSize;
        lHashNode * hashTable;

    public:
        LinearHashTable();
        int createTable (int size);
        int insert(int key);
        int search(int key);
};