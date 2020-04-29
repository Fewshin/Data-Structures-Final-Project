#include "QuadraticHashTable.hpp"
#include <chrono>

QuadraticHashTable::QuadraticHashTable() {
  tableSize = NULL;
  hashTable = NULL;
}

int QuadraticHashTable::insert(int key, int collIndex) {
    int index = key % *tableSize;
    int i = 0;

    while(hashTable[index].isStoring == true) {
        insertCollisions[collIndex]++;
        i++;
        index = (index + i * i) % *tableSize;
    }
    hashTable[index].isStoring = true;
    hashTable[index].key = key;
    return 0;
}

int QuadraticHashTable::search(int key, int collIndex) {
    int index = key % *tableSize;
    int i = 0;
    while(hashTable[index].key != key) {
        searchCollisions[collIndex]++;
        i++;
        index = (index + i * i) % *tableSize;
    }
    return index;
}

vector<float> QuadraticHashTable::createTable (int size, long * input) {
  vector<float> insertData;
  tableSize = new int(size);
  hashTable = new qHashNode[*tableSize];
  for(int j = 0; j < 400; j++) {
    insertCollisions.push_back(0);
    auto sTime = chrono::steady_clock::now();
    for(int i = (j * 100); i < (100 + j * 100); i++) {
      insert((int) *(input + i), j);
    }
    auto eTime = chrono::steady_clock::now();
    auto avgTime = chrono::duration_cast<chrono::nanoseconds>((eTime - sTime) / 100).count();
    insertData.push_back(avgTime);
  }
  return insertData;
}

vector<float> QuadraticHashTable::searchTable(long * input) {
  vector<float> searchData;
  for(int i = 0; i <= 40000; i = i + 100) {
    int set[100];
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

int QuadraticHashTable::numOfInsertCollisions(int index) {
  return insertCollisions[index];
}

int QuadraticHashTable::numOfSearchCollisions(int index) {
  return searchCollisions[index];
}