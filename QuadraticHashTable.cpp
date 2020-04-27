#include "QuadraticHashTable.hpp"

QuadraticHashTable::QuadraticHashTable() {
  tableSize = NULL;
  hashTable = NULL;
}

int QuadraticHashTable::createTable (int size) {
  tableSize = new int(size);
  hashTable = new qHashNode[*tableSize];
}

int QuadraticHashTable::insert(int key) {
    int index = key % *tableSize;
    int i = 0;

    while(hashTable[index].isStoring == true) {
        i++;
        index = (index + i * i) % *tableSize;
    }
    hashTable[index].isStoring = true;
    hashTable[index].key = key;
    return 0;
}

int QuadraticHashTable::search(int key) {
    int index = key % *tableSize;
    int i = 0;
    while(hashTable[index].key != key) {
        i++;
        index = (index + i * i) % *tableSize;
    }
    return index;
}