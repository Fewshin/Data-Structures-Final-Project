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

vector<long> getData (char letter/*,int * size*/) { //Note: Only works for vectors
  std::string defaultName = "dataSet";
  defaultName.push_back(letter);
  defaultName = defaultName + ".csv";
  std::vector<long> store;
  std::ifstream data(defaultName);
  std::string line;
  std::getline(data, line); 
  //printf("%s\n",line.c_str());
  std::string temp = "";
  //int count = 0;
  for (int i = 0; i < (int) line.length(); i++) {
    if (line[i] != ',') {
      temp.push_back(line[i]);
    }
    if (line[i] == ',') {
      store.push_back(stoi(temp));
      //printf(temp.c_str());
      //count++;
      temp = "";
    }
  }
  store.push_back(stoi(temp));
  //count++;
  //*size = count;
  //printf("|%s\n%d\n",temp.c_str(), count);//Final count is 40,000 as expected.
  //printf("%d\n", (int) store.size());//40,000 again, seems to be working as intended.
  return store;
}

int main () {
  printf("Testing speed of table creation for BST\n");
  vector<long> _testData = getData('A');
  long * testData = &_testData[0];//Asignment asks us to use an array
  int testDataSize = _testData.size();
  printf("%ld\n", testData[0]);
  printf("%d\n", testDataSize);

  BST bst = BST();

  // float * insert = &bst.createTree(testData)[0];
  // float * search = &bst.searchTree(testData)[0];
  vector<float> insert = bst.createTree(testData);
  vector<float> search = bst.searchTree(testData);

  ofstream insertData;
  ofstream searchData;
  insertData.open("insert_performance_BST_dataSetA.csv");
  searchData.open("search_performance_BST_dataSetA.csv");
  for(int i = 0; i < 400; i++) {
    insertData << insert[i] << "\n";
    searchData << search[i] << "\n";
  }
  insertData.close();
  searchData.close();

  printf("Testing speed of table creation for linked list\n");

  LinkedList ll = LinkedList();

  insert = ll.createList(testData);
  search = ll.searchList(testData);

  insertData.open("insert_performance_LL_dataSetA.csv");
  searchData.open("search_performance_LL_dataSetA.csv");
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
  //Code Here
  _testData.clear();
}