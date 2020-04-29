#include <iostream>
using namespace std;

struct qHashNode {
    int key;
    bool isStoring = false;
};

class QuadraticHashTable {
    private:
        int * tableSize;
        qHashNode * hashTable;

    public:
        QuadraticHashTable();
        int insert(int key);
        int search(int key);
        int createTable(int size, long * input);
};