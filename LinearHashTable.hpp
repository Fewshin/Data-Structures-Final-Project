#include <iostream>
#include <vector>
using namespace std;

struct lHashNode {
    int key;
    bool isStoring = false;
};

class LinearHashTable {
    private:
        int * tableSize;
        lHashNode * hashTable;
        vector<int> insertCollisions;
        vector<int> searchCollisions;

    public:
        LinearHashTable();
        int insert(int key, int collIndex);
        int search(int key, int collIndex);
        std::vector<float> createTable (int size, long * input);
        std::vector<float> searchTable (long * input);
        int numOfInsertCollisions(int index);
        int numOfSearchCollisions(int index);
};