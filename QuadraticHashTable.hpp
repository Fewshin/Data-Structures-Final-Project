/*
Authors:
- Felix Pawlowski (functions, bug fixes, writing to file)
- Kenneth Strieker (functions, function timing)
*/

#include <iostream>
#include <vector>
using namespace std;

struct qHashNode {
    int key;
    bool isStoring = false;
};

class QuadraticHashTable {
    private:
        int * tableSize;
        qHashNode * hashTable;
        vector<int> insertCollisions;
        vector<int> searchCollisions;

    public:
        QuadraticHashTable();
        int insert(int key, int collIndex);
        int search(int key, int collIndex);
        std::vector<float> createTable(int size, long * input);
        std::vector<float> searchTable(long * input);
        int numOfInsertCollisions(int index);
        int numOfSearchCollisions(int index);
};