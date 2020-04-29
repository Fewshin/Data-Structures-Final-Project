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
#include <string>

vector<long> getData (char letter) {
  std::string defaultName = "dataSet";
  defaultName.push_back(letter);
  defaultName = defaultName + ".csv";
  std::vector<long> store;
  std::ifstream data(defaultName);
  std::string line;
  std::getline(data, line); 
  std::string temp = "";
  for (int i = 0; i < (int) line.length(); i++) {
    if (line[i] != ',') {
      temp.push_back(line[i]);
    }
    if (line[i] == ',') {
      store.push_back(stoi(temp));
      temp = "";
    }
  }
  store.push_back(stoi(temp));
  return store;
}

int main () {
  printf("Testing speed of table A creation for BST\n");
  vector<long> _testData = getData('A');
  long * testData = &_testData[0];
  int testDataSize = _testData.size();
  printf("%ld\n", testData[0]);
  printf("%d\n", testDataSize);

  BST bst_A = BST();

  // float * insert = &bst.createTree(testData)[0];
  // float * search = &bst.searchTree(testData)[0];
  vector<float> insert = bst_A.createTree(testData);
  vector<float> search = bst_A.searchTree(testData);

  ofstream insertData;
  ofstream searchData;
  insertData.open("insert_performance_BST_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_BST_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();

  printf("Testing speed of table A creation for linked list\n");

  LinkedList ll_A = LinkedList();

  insert = ll_A.createList(testData);
  search = ll_A.searchList(testData);

  insertData.open("insert_performance_LL_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_LL_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();

  _testData.clear();
  _testData = getData('B');
  testData = &_testData[0];
  testDataSize = _testData.size();

  printf("Testing speed of table B creation for BST\n");

  BST bst_B = BST();

  insert = bst_B.createTree(testData);
  search = bst_B.searchTree(testData);

  insertData.open("insert_performance_BST_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_BST_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();

  printf("Testing speed of table B creation for linked list\n");

  LinkedList ll_B = LinkedList();

  insert = ll_B.createList(testData);
  search = ll_B.searchList(testData);

  insertData.open("insert_performance_LL_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_LL_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();



  //Code Here
  _testData.clear();
}