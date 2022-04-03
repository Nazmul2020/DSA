#include<iostream>
using namespace std;

int stack_size = 30;
int count = 1;

struct node{
    int num;
    node *next, *prev;
};
node *root, *tail;

void push(int num){
    if(count <= stack_size){
        if(root == NULL){
            root = new node();
            root->num = num;
            root->next = NULL;
            tail = root;
            count++;
        }
        else{
            node *newNode = new node();
            newNode->num = num; // store value in new node
            newNode->next = NULL; 
            newNode->prev = tail; //point to the previous node
            tail->next = newNode; //point to the next node
            tail = newNode; // point to the previous node
            count++;
        }
    }
    else
        cout << "stack full\n";
}

void peek(){
    if(root == NULL)
        cout << "stack underflow\n";
    else
        cout << tail->num <<"\n";   
}

void pop(){
    if(root == NULL)
        cout << "stack underflow\n";
    else{
        node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete(temp);
        count--;
    }

}

bool isFull(){
    if(count > 30)
        return true;
    else
        return false;
}

bool isEmpty(){
    if(root == NULL)
        return true;
    else
        return false;
}

int main(){
    
    if(isEmpty())
        cout << "stack empty\n";
    else
        cout << "stack not empty\n";


    if(isFull())
        cout << "stack full\n";
    else
        cout << "stack not full\n";


    for(int i=1; i<=10; i++){
        push(i);
    }

    if(isEmpty())
        cout << "empty\n";
    else
        cout << "not empty\n";

    peek();    

       
    for(int i=11; i<=30; i++){
        push(i);
    }

    if(isFull())
        cout << "full\n";
    else
        cout << "not full\n";

    peek();
    pop();
    peek();
}
