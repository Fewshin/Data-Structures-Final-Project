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

    public:
        LinearHashTable();
        int insert(int key);
        int search(int key);
        std::vector<float> createTable (int size, long * input);
        std::vector<float> searchTable (long * input);
};