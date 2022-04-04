#include<iostream>
using namespace std;

struct node{
    int num;
    node *next;
};
node *head;

void push(int num){
    node *newNode = new node();
    if(!newNode)
        cout << "stack overflow\n";
        
    else{
        if(head == NULL){
            head = new node();
            head->num = num;
            head->next = NULL;
            
        }
        else{
            newNode->num = num;
            newNode->next = head;
            head = newNode;
            
        }
     }
            
}

void peek(){
    if(head == NULL)
        cout << "stack underflow\n";
    else
        cout << head->num <<"\n";
    
}

void pop(){
    if(head == NULL)
        cout << "stack underflow\n";
    else{
        node *temp = head;
        head = head->next;
        delete(temp);
    }

}

bool isEmpty(){
    if(head == NULL)
        return true;
    else
        return false;
}

void print(){
    node *currentNode = head;
    if(head == NULL)
        cout << "stack  empty\n";
    else{
        while(currentNode != NULL){
        cout << currentNode->num << " ";
        currentNode = currentNode->next;
        }
        cout << "\n";
    }
}

int main(){
    peek();
    pop();
    
    if(isEmpty())
        cout << "stack empty\n";
    else
        cout << "stack not empty\n";


    for(int i=1; i<=10; i++){
        push(i);
    }

    print();
    peek();
    pop();
    peek();

    if(isEmpty())
        cout << "stack empty\n";
    else
        cout << "stack not empty\n"; 

   

   // while()
}
