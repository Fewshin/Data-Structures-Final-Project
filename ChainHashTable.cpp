#include "ChainHashTable.hpp"
#include <chrono>
#include <vector>

ChainHashTable::ChainHashTable() {
    tableSize = NULL;
    hashTable = NULL;
}

void ChainHashTable::insert(int key, int trialNum) {
  int index = key % *tableSize;
  cHashNode *check = (hashTable + index);//Line is sus but don't want to redo if I don't have to.
  while(check->isStoring == true) {
    createCollisionCounts[trialNum]++;
    check = check->next;
  }
  check->isStoring = true;
  check->key = key;
}

int ChainHashTable::search(int key) {
    return key % *tableSize;
}

vector<float> ChainHashTable::createTable(int size, long * input) {
  vector<float> store;
  tableSize = new int(size);
  hashTable = new cHashNode[*tableSize];
  int trialNum = 0;
  createCollisionCounts.push_back(0);
  auto sTime = chrono::steady_clock::now();
  for (int i = 0; i < size; i++) {
    insert((int) *(input + i), trialNum);
    if (i%100 == 0) {
      auto eTime = chrono::steady_clock::now();
      store.push_back((float) chrono::duration_cast<chrono::nanoseconds>((eTime - sTime) / 100).count());
      trialNum++;
      createCollisionCounts.push_back(0);
      sTime = chrono::steady_clock::now();
    }
  }
  return store;
}