/*
stack implementaion with array
code written by nazmul hasan
*/

#include <stdio.h>

#define stackSize 15
int myStack[stackSize], top = -1;

// push --> to insert the value in the stack
void push(int value){
    if(top < stackSize - 1){
        printf("Push: %d\n", value);
        myStack[++top] = value;
    }
    else
        printf("stack is overflow!\n");
}

// peek --> to read the top value in the stack
void peek(){
    if(top >= 0)
        printf("%d\n",myStack[top]);
    else
        printf("stack underflow!\n");
}

// pop --> to remove the top value in the stack
void pop(){
    if(top >= 0){
        printf("\nPopped %d, from Stack\n", myStack[top]);
        top--;
    }   
    else
        printf("stack underflow!");
}
int empty(){
    if(top < 0)
        return 1;
    else
        return 0;
}

// full stack display
void displayStack(){
    printf("\nPrint the full stack from TOP to BOTTOM:\n");
    for(int i = top; i >= 0; i--)
        printf("%d ",myStack[i]);
}

int main(){
    int i;

    push(10);
    push(20);
    push(30);
    push(40);
    peek();
    pop();
    peek();
    displayStack();
    if(empty())
        printf("\nstack empty");
    else
        printf("\nstack not empty");
    
    pop();
    pop();
    pop();

    peek();
    if(empty())
        printf("\nstack empty");
    else
        printf("\nstack not empty");  
   
}
