#include "LinearHashTable.hpp"
#include <chrono>

LinearHashTable::LinearHashTable() {
  tableSize = NULL;
  hashTable = NULL;
}

int LinearHashTable::insert(int key, int collIndex) {
    int index = key % *tableSize;
    while(hashTable[index].isStoring == true) {
        index++;
        insertCollisions[collIndex]++;
        if(index >= *tableSize)
            index = 0;
    }
    hashTable[index].isStoring = true;
    hashTable[index].key = key;
    return 0;
}

int LinearHashTable::search(int key, int collIndex) {
    int index = key % *tableSize;
    while(hashTable[index].isStoring == true) {
        index++;
        searchCollisions[collIndex]++;
        if(index >= *tableSize)
            index = 0;
    }
    return index;
}

vector<float> LinearHashTable::createTable (int size, long * input) {
  vector<float> insertData;
  tableSize = new int(size);
  hashTable = new lHashNode[*tableSize];
  for(int j = 0; j < 400; j++) {
    insertCollisions.push_back(0);
    auto sTime = chrono::steady_clock::now();
    insertCollisions.push_back(0);
    for (int i = (j * 100); i < (100 + j * 100); i++) {
      insert((int) *(input + i), j);
    }
    auto eTime = chrono::steady_clock::now();
    auto avgTime = chrono::duration_cast<chrono::nanoseconds>((eTime - sTime) / 100).count();
    insertData.push_back(avgTime);
  }
  return insertData;
}

vector<float> LinearHashTable::searchTable (long * input) {
  vector<float> searchData;
  for(int i = 0; i <= 40000; i = i + 100) {
    int set[100];
    searchCollisions.push_back(0);
    for(int j = 0; j < 100; j++)
      set[j] = rand() % (i + 100);
    searchCollisions.push_back(0);
    auto start = chrono::steady_clock::now();
    for(int k = 0; k < 100; k++) {
      int t = search(input[set[k]], i/100);
    }
    auto end = chrono::steady_clock::now();
    auto avgTime = chrono::duration_cast<chrono::nanoseconds>((end - start) / 100).count();
    searchData.push_back(avgTime);
  }
  return searchData;
}

int LinearHashTable::numOfInsertCollisions(int index) {
  return insertCollisions[index];
}

int LinearHashTable::numOfSearchCollisions(int index) {
  return searchCollisions[index];
}