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

}