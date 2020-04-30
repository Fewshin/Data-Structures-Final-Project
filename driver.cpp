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
  BST bst_A = BST();

  // float * insert = &bst.createTree(testData)[0];
  // float * search = &bst.searchTree(testData)[0];
  vector<float> insert = bst_A.createTree(testData);

  printf("Testing speed of table A searching for BST\n");

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

  printf("Testing speed of table A searching for linked list\n");

  search = ll_A.searchList(testData);

  insertData.open("insert_performance_LL_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_LL_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();

  printf("Testing speed of table A creation for linear hash table\n");

  LinearHashTable lht_A = LinearHashTable();

  insert = lht_A.createTable(40009, testData);

  printf("Testing speed of table A searching for linear hash table\n");

  search = lht_A.searchTable(testData);

  insertData.open("insert_performance_LHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_LHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();
  insertData.open("insert_collisions_LHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_collisions_LHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << lht_A.numOfInsertCollisions(i) << "\n";
    searchData << lht_A.numOfSearchCollisions(i) << "\n";
  }
  insertData.close();
  searchData.close();

  printf("Testing speed of table A creation for quadratic hash table\n");

  QuadraticHashTable qht_A = QuadraticHashTable();

  insert = qht_A.createTable(40009, testData);

  printf("Testing speed of table A searching for quadratic hash table\n");

  search = qht_A.searchTable(testData);

  insertData.open("insert_performance_QHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_QHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();
  insertData.open("insert_collisions_QHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_collisions_QHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << qht_A.numOfInsertCollisions(i) << "\n";
    searchData << qht_A.numOfSearchCollisions(i) << "\n";
  }
  insertData.close();
  searchData.close();

  ChainHashTable cht_A = ChainHashTable();

  printf("Testing speed of table A creation for chain hash table\n");

  insert = cht_A.createTable(40009, testData);

  printf("Testing speed of table A searching for chain hash table\n");

  search = cht_A.searchTable(40009, testData);

  insertData.open("insert_performance_CHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_CHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < testDataSize/100; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();

  insertData.open("insert_collisions_CHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_collisions_CHT_dataSetA.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < testDataSize/100; i++) {
    insertData << cht_A.numOfInsertCollisions(i) << "\n";
    searchData << cht_A.numOfSearchCollisions(i) << "\n";
  }
  insertData.close();
  searchData.close();













///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  _testData.clear();
  _testData = getData('B');
  testData = &_testData[0];
  testDataSize = _testData.size();

  printf("Testing speed of table B creation for BST\n");

  BST bst_B = BST();

  insert = bst_B.createTree(testData);

  printf("Testing speed of table B searching for BST\n");

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

  printf("Testing speed of table B searching for linked list\n");

  search = ll_B.searchList(testData);

  insertData.open("insert_performance_LL_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_LL_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();

  printf("Testing speed of table B creation for linear hash table\n");

  LinearHashTable lht_B = LinearHashTable();

  insert = lht_B.createTable(40009, testData);
  
  printf("Testing speed of table B searching for linear hash table\n");

  search = lht_B.searchTable(testData);

  insertData.open("insert_performance_LHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_LHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();
  insertData.open("insert_collisions_LHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_collisions_LHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << lht_B.numOfInsertCollisions(i) << "\n";
    searchData << lht_B.numOfSearchCollisions(i) << "\n";
  }
  insertData.close();
  searchData.close();

  printf("Testing speed of table A creation for quadratic hash table\n");

  QuadraticHashTable qht_B = QuadraticHashTable();

  insert = qht_B.createTable(40009, testData);

  printf("Testing speed of table A searching for quadratic hash table\n");

  search = qht_B.searchTable(testData);

  insertData.open("insert_performance_QHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_QHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();
  insertData.open("insert_collisions_QHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_collisions_QHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < 400; i++) {
    insertData << qht_B.numOfInsertCollisions(i) << "\n";
    searchData << qht_B.numOfSearchCollisions(i) << "\n";
  }
  insertData.close();
  searchData.close();

  ChainHashTable cht_B = ChainHashTable();

  printf("Testing speed of table B creation for chain hash table\n");

  insert = cht_B.createTable(40009, testData);

  printf("Testing speed of table B searching for chain hash table\n");

  search = cht_B.searchTable(40009, testData);

  insertData.open("insert_performance_CHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_performance_CHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < testDataSize/100; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();
  insertData.open("insert_collisions_CHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  searchData.open("search_collisions_CHT_dataSetB.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  for(int i = 0; i < testDataSize/100; i++) {
    insertData << cht_B.numOfInsertCollisions(i) << "\n";
    searchData << cht_B.numOfSearchCollisions(i) << "\n";
  }
  insertData.close();
  searchData.close();


  _testData.clear();
}