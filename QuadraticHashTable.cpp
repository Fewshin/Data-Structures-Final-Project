#include "QuadraticHashTable.hpp"

QuadraticHashTable::QuadraticHashTable() {

}

void QuadraticHashTable::insert(int key) {
    int index = key % tableSize;
    int i = 0;

    while(hashTable[index].isStoring == true) {
        i++;
        index = (index + i * i) % tableSize;
    }
    hashTable[index].isStoring = true;
    hashTable[index].key = key;
}

int QuadraticHashTable::search(int key) {
    int index = key % tableSize;
    int i = 0;
    while(hashTable[index].key != key) {
        i++;
        index = (index + i * i) % tableSize;
    }
    return index;
}