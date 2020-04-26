#include "LinearHashTable.hpp"

LinearHashTable::LinearHashTable() {
  tableSize = NULL;
  hashTable = NULL;
}

int LinearHashTable::createTable (int size) {
  *tableSize = size;
  hashTable = new lHashNode[size];
}

int LinearHashTable::insert(int key) {
    int index = key % *tableSize;
    while(hashTable[index].isStoring == true) {
        index++;
        if(index >= (*tableSize - 1)) //Adjusted because arrays start at zero
            index = 0;
    }
    hashTable[index].isStoring = true;
    hashTable[index].key = key;
    return 0;
}

int LinearHashTable::search(int key) {
    int index = key % *tableSize;
    while(hashTable[index].isStoring == true) {
        index++;
        if(index >= (*tableSize - 1)) //See above
            index = 0;
    }
    return index;
}