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
        int insertCollisions[400];
        int searchCollisions[400];
        for(int i = 0; i < 400; i++) {
            insertCollisions[i] = 0;
            searchCollisions[i] = 0;
        }

    public:
        LinearHashTable();
        int insert(int key, int collIndex);
        int search(int key, int collIndex);
        std::vector<float> createTable (int size, long * input);
        std::vector<float> searchTable (long * input);
        int numOfInsertCollisions(int index);
        int numOfSearchCollisions(int index);
};