/*
    queue First in First Out(FIFO)
*/

#include <stdio.h>

#define size 100

int rear=-1,front=0;
int arr[size];

void enque(int v){
  if(rear != size)
    arr[++rear] = v;
  else
    printf("queue full!");
}

void quePop(){
  if(front<size)
    front++;
  else
    printf("queue empty!");
}

void peek(){
  if(front<size)
    printf("%d\n",arr[front]);
  else
    printf("queue empty!");
}

void allDisplay(){
  for(int i = front; i<=rear; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

int main() {

  enque(10);
  enque(20);
  enque(40);
  enque(50);

  allDisplay();
  quePop();
  allDisplay();
  peek();

  return 0;
}
