#include <bits/stdc++.h>
using namespace std;

int left(int i){
	return i*2;
}

int right(int i){
	return i*2+1;
}

void maxHeapify(int heap[],int heapSize,int i){
	int largest;
	int l = left(i);
	int r = right(i);

	//(l<=heapSize) use for index out of bound
	if(l<=heapSize && heap[l]>heap[i])
		largest = l;
	else
		largest = i;

	if(r<=heapSize && heap[r]>heap[largest])
		largest = r;

	if(largest!=i){ // swapping for make parent node to max value
		int temp = heap[i];
		heap[i] = heap[largest];
		heap[largest]=temp;

		maxHeapify(heap,heapSize,largest);

	}
}

void buildMaxHeap(int heap[],int heapSize){

	for(int i=heapSize/2; i>=1;i--){
		maxHeapify(heap,heapSize,i);
	}
}

void heapSort(int heap[], int heapSize){
	for (int i = heapSize; i>1; i--){
		int temp =heap[1];
		heap[1]  = heap[i];
		heap[i] = temp;
		heapSize--;
		maxHeapify(heap,heapSize,1);
	}
}

int main(){
	
	int heap[100];
	int size;
	cin >> size;

	for(int i=0; i<size; i++)
		cin >> heap[i];

	for(int i = 1;i<size;i++)
		cout << heap[i] << " ";

	buildMaxHeap(heap,size-1);

	cout << "\n";

	for(int i = 1;i<size;i++)
		cout << heap[i] << " ";

	heapSort(heap,size-1);
	cout << "\n";

	for(int i = 1;i<size;i++)
		cout << heap[i] << " ";
}
