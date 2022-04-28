#include <bits/stdc++.h>

using namespace std;
#define ll long long

// for swapping two number
void swap(int &a, int &b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void insertionSort(int arr[], int size){
  for(int i = 0; i<size; i++){
    for(int j = i; j>=0; j--){
      if(arr[j-1]>arr[j]){
        swap(arr[j-1], arr[j]);

      }
    }
  }
}

void print(int arr[], int size){
  int count= 0;
  for(int i = 0; i<size; i++){
    count++;
    cout << arr[i] << " "; 
  }
}

int main(){
  int num[] = {3,10,2,9,4,8,1,5,6,7,12,45,24,36,25,58,524,235,5412,2514,2215,878,5456,21215,234,341,1454,3210,369,
  141,441,215,1214,541,214,212,784,541,6541,4564,2147483647,987,6522,2614,5644,21413,5461,54,51,21552,544,2114,5451,
  24714,345,214,1443,2154,3544,111,10121,24114,241,23314,24124,244,1234,31032,14413,5451,54561,5465,545114,545,1541,
  5461,541,5141,63541,3541,1514,54,354,561,6564,32131,561,201321,2021,7644,45676,46874,47874,7897,87944,894,567,6544,545611,5413};

  int size = sizeof(num) / sizeof(num[0]);

  insertionSort(num,size);
  print(num,size);

}
