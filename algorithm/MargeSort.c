#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define size 1000

int temp[size];
int str[size];

void marge(int left,int midpoint,int right){
	int firstArrCnt=left,secondArrCnt=midpoint+1,i;
	for(i=firstArrCnt; firstArrCnt<=midpoint && secondArrCnt<=right;i++){
		if(str[firstArrCnt]<str[secondArrCnt]){
			temp[i]=str[firstArrCnt++];
		}
		else{
			temp[i]=str[secondArrCnt++];
		}

	}
	while(firstArrCnt<=midpoint)
		temp[i++]=str[firstArrCnt++];

	while(secondArrCnt<=right)
		temp[i++]=str[secondArrCnt++];

	for(i=left;i<=right;i++)
		str[i]=temp[i];
}

void margeSort(int left,int right){
	int midpoint;
	if(left>=right)
		return;

	midpoint = left+(right-left)/2;

	margeSort(left,midpoint);
	margeSort(midpoint+1,right);

	marge(left, midpoint, right);
}


int main(){

		int n;
		scanf("%d",&n);
		for(int i = 0; i<n; i++){
			scanf("%d",&str[i]);
		}

		margeSort(0,n-1);

		for (int i = 0; i < n; ++i)
		{
			printf("%d ", str[i]);
		}
		
}


