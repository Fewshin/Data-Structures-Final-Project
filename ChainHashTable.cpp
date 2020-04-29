#include "ChainHashTable.hpp"
#include <chrono>

ChainHashTable::ChainHashTable() {
    tableSize = NULL;
    hashTable = NULL;
}

void ChainHashTable::insert(int key) {
    int index = key % *tableSize;
    cHashNode *check = (hashTable + index);//Line is sus but don't want to redo if I don't have to.
    while(check->isStoring == true)
        check = check->next;
    check->isStoring = true;
    check->key = key;
}

int ChainHashTable::search(int key) {
    return key % *tableSize;
}

int ChainHashTable::createTable(int size, long * input) {
  tableSize = new int(size);
  hashTable = new cHashNode[*tableSize];
  auto sTime = chrono::steady_clock::now();
  for (int i = 0; i < size; i++) {
    insert((int) *(input + i));
  }
  auto eTime = chrono::steady_clock::now();
  return chrono::duration_cast<chrono::nanoseconds>((eTime - sTime) / 100).count();
}