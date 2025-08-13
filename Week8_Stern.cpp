#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;

int logarAlgo(vector<int> &arr, int target){
  int arraySize = arr.size();
  int i, j = 0;

  while(i < arraySize - 1){
    while(j < arraySize - 1){
      if(arr[i] + arr[j] == target){
        return 0;
      }
      ++j;
      j = 0;
    }
    ++i;
  }
  return -1;
};

int main(){
  std::ifstream file("TextInput.txt");
  vector<int> myArray;
  int num;
  // Replace value with desired target value
  int target = 10;
  
  while (file >> num) {
      myArray.push_back(num);
  }

// Calling quick sort function
  auto qstart = std::chrono::high_resolution_clock::now();
  logarAlgo(myArray, target);
  auto qend = std::chrono::high_resolution_clock::now();
  auto qduration = std::chrono::duration_cast<std::chrono::microseconds>(qend - qstart);
  cout << "O(n^2) Algorithm Time: " << qduration.count() << " microseconds" << endl;
    
  return 0;
}