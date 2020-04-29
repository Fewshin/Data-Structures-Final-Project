#include "QuadraticHashTable.hpp"
#include <chrono>

QuadraticHashTable::QuadraticHashTable() {
  tableSize = NULL;
  hashTable = NULL;
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

int QuadraticHashTable::createTable (int size, long * input) {
  tableSize = new int(size);
  hashTable = new qHashNode[*tableSize];
  auto sTime = chrono::steady_clock::now();
  for (int i = 0; i < size; i++) {
    insert((int) *(input + i));
  }
  auto eTime = chrono::steady_clock::now();
  return chrono::duration_cast<chrono::nanoseconds>((eTime - sTime) / 100).count();
}