#include "ChainHashTable.hpp"

ChainHashTable::ChainHashTable() {

}

void ChainHashTable::insert(int key) {
    int index = key % tableSize;
    cHashNode *check = hashTable[index];
    while(check->isStoring == true)
        check = check->next;
    check->isStoring = true;
    check->key = key;
}

int ChainHashTable::search(int key) {
    return key % tableSize;
}

