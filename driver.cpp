#include "BST.hpp"
#include "ChainHashTable.hpp"
//#include "hash.hpp" 
#include "LinearHashTable.hpp" 
#include "LinkedList.hpp"
#include "QuadraticHashTable.hpp"
#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <cstdlib>

long * getData (char letter) {
  std::string defaultName = "dataSet";
  defaultName.push_back(letter);
  defaultName = defaultName + ".csv";
  std::vector<long> store;
  std::ifstream data(defaultName);
  /*Objective: Pull all long ints from the .csv file
  Push them into the vector, then return the address
  of the first value in the vector*/
  return &store[0];
}

int main () {
  printf("Testing speed of table creation for BST\n");
  /*Key:
  S = Start
  C = Creating Table
  Z = Searching Table
  E = End
  D = Difference/Time taken*/

  // S
  long testData[] = getData('A');
  BST bst = BST();

  float insert[400];
  float search[400];
  clock_t start, end;

  // C
  for(int i = 0; i < 400; i++) {
    start = clock();
    for(int j = (i * 100); j < (100 + i * 100); j++) {
      bst.addNode((int) testData[j]);
    }
    end = clock();
    // D
    float avgTime = float(end - start) / (float(CLOCKS_PER_SEC) * 100);
    insert[i] = avgTime;
  }

  // Z
  for(int i = 0; i <= 40000; i = i + 100) {
    int set[100];
    for(int j = 0; j < 100; j++)
      set[j] = rand() % (i + 100);
    start = clock();
    for(int k = 0; k < 100; k++) {
      bst.searchKey(set[j]);
    }
    end = clock();
    // D
    float avgTime = float(end - start) / (float(CLOCKS_PER_SEC) * 100);
    search[i / 100] = avgTime;
  }

  // E
}