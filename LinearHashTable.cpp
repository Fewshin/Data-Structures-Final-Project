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
  tableSize = new int(size);
  hashTable = new lHashNode[*tableSize];
  auto sTime = chrono::steady_clock::now();
  for (int i = 0; i < size; i++) {
    insert((int) *(input + i));
  }
  auto eTime = chrono::steady_clock::now();
  return chrono::duration_cast<chrono::nanoseconds>((eTime - sTime) / 100).count();
}