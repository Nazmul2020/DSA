#include <iostream>

using namespace std;

#define range 110

void countSort(int arr[], int arrSize){
    int count[range]= {0};

  for(int i = 1; i<=arrSize; i++){ //frequency count
    count[arr[i]]+=1;
  }

  //sorting here
  for(int i = 1; i<=range; i++){
      if(count[i]>0){
          for(int j = 1; j<=count[i]; j++)
            cout << i << " ";
      }
      
  }  
}

int main(){
    int age[] = {44,85,5,98,54,74,6,2,8,99,40,32,1,5,7,10,50,11,20,25,15,12,14,13,18,3,17,42,4,9,16,19};

    int size = sizeof(age)/sizeof(age[0]) - 1;

    countSort(age,size);
    
}
