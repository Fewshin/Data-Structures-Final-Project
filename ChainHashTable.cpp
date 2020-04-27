#include "ChainHashTable.hpp"

ChainHashTable::ChainHashTable() {
    tableSize = NULL;
    hashTable = NULL
}

int ChainHashTable::createTable(int size) {
    tableSize = new int(size);
    hashTable = new cHashNode[*tableSize];
}

void ChainHashTable::insert(int key) {
    int index = key % *tableSize;
    cHashNode *check = hashTable[index];
    while(check->isStoring == true)
        check = check->next;
    check->isStoring = true;
    check->key = key;
}

int ChainHashTable::search(int key) {
    return key % *tableSize;
}

