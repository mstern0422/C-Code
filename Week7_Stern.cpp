#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;

// Partition code used for quick sort function
int partition(vector<int> &vec, int low, int high){
  int pivot = vec[high];
  int i = low - 1;
  
  for(int j = low; j <= high - 1; j++){
    if(vec[j] < pivot){
      i++;
      swap(vec[i], vec[j]);
    }
  }

  swap(vec[i + 1], vec[high]);
  return i + 1;
}

// Merge code for merge sort function
void merge(vector<int>& vec, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
  
    vector<int> leftVec(n1), rightVec(n2);

    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
  }
}

// Merge sort function
void mergeSort(vector<int>& vec, int left, int right) {
  
  if (left < right) {
    int mid = left + (right - left) / 2;
      mergeSort(vec, left, mid);
      mergeSort(vec, mid + 1, right);
      merge(vec, left, mid, right);
  }
}

// Selection sort function
void selectionSort(vector<int> &vec){
  int vecSize = vec.size();
  
  auto start = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < vecSize - 1; ++i){
    int minIndex = i;
    for(int j = i + 1; j < vecSize; ++j){
      if(vec[j] < vec[minIndex]){
        minIndex = j;
      }
    }
    swap(vec[i], vec[minIndex]);
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  cout << "Selection Sort function time: " << duration.count() << " microseconds" << endl;
}

// Quick sort function
void quickSort(vector<int> &vec, int low, int high){
  if (low < high) {
      int partIndex = partition(vec, low, high);
    
      quickSort(vec, low, partIndex - 1);
      quickSort(vec, partIndex + 1, high);
  }
}

// Bubble sort function
void bubblesort(vector<int> &vec){
  int n = vec.size();

  auto start = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(vec[j] > vec[j + 1])
        swap(vec[j], vec[j + 1]);
    }
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  cout << "Bubble Sort function time: " << duration.count() << " microseconds" << endl;
};

// Linear serach function
int linearSearch(vector<int> &vec, int target){ 
  for(int i = 0; i < vec.size(); i++)
    if(vec[i] == target){
      cout << "Linear Search Target found." << endl;
      return i;
  }
  cout << "Linear Search Target not found." << endl;
  return -1;
}

// Binary search function
int binarySearch(vector<int> &vec, int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (vec[mid] == x)
            return mid;
        if (vec[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


int main(){
  std::ifstream file("TextInput.txt");
  vector<int> numVec;
  int targetInt = 9022;
  int n = sizeof(numVec) / sizeof(numVec[0]);
  int num;
  
  while (file >> num) {
      numVec.push_back(num);
  }
// Calling bubble and selection sort functions
  bubblesort(numVec);
  selectionSort(numVec);

// Calling quick sort function
  auto qstart = std::chrono::high_resolution_clock::now();
  quickSort(numVec, 0, numVec.size() - 1);
  auto qend = std::chrono::high_resolution_clock::now();
  auto qduration = std::chrono::duration_cast<std::chrono::microseconds>(qend - qstart);

  cout << "Quick Sort function time: " << qduration.count() << " microseconds" << endl;

// Calling merge sort function
  auto mstart = std::chrono::high_resolution_clock::now();
  mergeSort(numVec, 0, numVec.size() - 1);
  auto mend = std::chrono::high_resolution_clock::now();
  auto mduration = std::chrono::duration_cast<std::chrono::microseconds>(mend - mstart);

  cout << "Merge Sort function time: " << mduration.count() << " microseconds" << endl;

// Calling linear search function
  auto lstart = std::chrono::high_resolution_clock::now();
  linearSearch(numVec, targetInt);
  auto lend = std::chrono::high_resolution_clock::now();
  auto lduration = std::chrono::duration_cast<std::chrono::microseconds>(lend - lstart);

  cout << "Linear Search function time: " << lduration.count() << " microseconds" << endl;

// Calling binary search function
  auto bstart = std::chrono::high_resolution_clock::now();
  binarySearch(numVec, 0, n - 1, targetInt);
  auto bend = std::chrono::high_resolution_clock::now();
  auto bduration = std::chrono::duration_cast<std::chrono::microseconds>(bend - bstart);

  cout << "Binary Search function time: " << bduration.count() << " microseconds" << endl;
    
  return 0;
}