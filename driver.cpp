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
  /*Objective: Pull all long ints from the .csv file
  Push them into the vector, then return the address
  of the first value in the vector*/
  std::string line;
  std::getline(data, line); 
  //printf("%s\n",line.c_str());//Holy hell, I just maxed my CPU printing this.
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
  //printf("|%s\n%d\n",temp.c_str(), count);//Final count is 40,000 as expected.
  //printf("%d\n", (int) store.size());//40,000 again, seems to be working as intended.
  return store;
}

int main () {
  //printf("Testing speed of table creation for BST\n");
  /*Key for timing variable names:
  S = Start
  C = Creating Table
  Z = Searching Table
  E = End
  D = Difference/Time taken*/

  vector<long> _testData = getData('A');
  long * testData = &_testData[0];
  //printf("%ld\n", testData[0]);
  BST bst = BST();

  float insert[400];
  float search[400];
  clock_t start, end;

  for(int i = 0; i < 400; i++) {
    start = clock();
    for(int j = (i * 100); j < (100 + i * 100); j++) {
      bst.addNode((int) testData[j]);
    }
    end = clock();
    float avgTime = float(end - start) / (float(CLOCKS_PER_SEC) * 100);
    insert[i] = avgTime;
  }

  for(int i = 0; i <= 40000; i = i + 100) {
    int set[100];
    for(int j = 0; j < 100; j++)
      set[j] = rand() % (i + 100);
    start = clock();
    for(int k = 0; k < 100; k++) {
      bst.searchKey(set[k]);
    }
    end = clock();
    float avgTime = float(end - start) / (float(CLOCKS_PER_SEC) * 100);
    search[i / 100] = avgTime;
  }

}