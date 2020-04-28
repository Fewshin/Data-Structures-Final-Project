#include "LinearHashTable.hpp"
#include <chrono>

LinearHashTable::LinearHashTable() {
  tableSize = NULL;
  hashTable = NULL;
}

int LinearHashTable::insert(int key) {
    int index = key % *tableSize;
    while(hashTable[index].isStoring == true) {
        index++;
        if(index >= *tableSize)
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
        if(index >= *tableSize)
            index = 0;
    }
    return index;
}

int LinearHashTable::createTable (int size, long * input) {
  int sTime = time(NULL);
  tableSize = new int(size);
  hashTable = new lHashNode[*tableSize];
  for (int i = 0; i < size; i++) {
    insert((int) *(input + i));
  }
  int eTime = time(NULL);
  return eTime - sTime;
}