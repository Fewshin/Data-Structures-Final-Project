#include "LinearHashTable.hpp"

LinearHashTable::LinearHashTable() {

}

void LinearHashTable::insert(int key) {
    int index = key % tableSize;
    while(hashTable[index].isStoring == true) {
        index++;
        if(index >= 40009)
            index = 0;
    }
    hashTable[index].isStoring = true;
    hashTable[index].key = key;
}

int LinearHashTable::search(int key) {
    int index = key % tableSize;
    while(hashTable[index].key != key) {
        index++;
        if(index >= 40009)
            index = 0;
    }
    return index;
}