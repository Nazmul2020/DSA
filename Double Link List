#include<bits/stdc++.h>
using namespace std;

struct node{
    int num;
    node *next, *prev;
};

node *root, *tail;

void append(int num){
    if(root == NULL){
        root = new node();
        root->num = num;
        root->next = NULL;
        tail = root;
    }
    else{
        node *newNode = new node();
        newNode->num = num; // store value in new node
        newNode->next = NULL; 
        newNode->prev = tail; //point to the previous node
        tail->next = newNode; //point to the next node
        tail = tail->next; // point to the previous node
    }
}

void beginInsert(int num){
    if(root == NULL){
        root = new node();
        root->num = num;
        root->next = NULL;
        root = tail;
    }
    else{
        node *newNode = new node();
        newNode->num = num; // store value in new node
        newNode->prev = NULL; 
        newNode->next = root; //point to the previous node
        root->prev = newNode; //point to the next node
        root = root->prev; // point to the previous node
    }
}
void print(){
    node *currentNode = root;
    while(currentNode!= NULL){
        cout << currentNode->num <<" ";
        currentNode = currentNode->next;
    }
}

void reversePrint(){
    node *currentNode = tail;
    while(currentNode!= NULL){
        cout << currentNode->num <<" ";
        currentNode = currentNode->prev;
    }
}

void deleteNode(int num){
    node *currentNode = root;
    if(root->num == num){
        node *temp = root;
        root = currentNode->next;
        root->prev = NULL;
        delete(temp);
    }
    else if(tail->num == num){
        node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete(temp);
    }
    else{
        while(currentNode->num != num){
            currentNode = currentNode->next;
        }
        node *temp = currentNode;
        currentNode->prev->next = currentNode->next; // 
        currentNode->next->prev = currentNode->prev;
        delete(temp);
    }
}
int main(){
    append(3);
    append(4);
    append(6);
    append(8);
    append(33);
    append(234);

    print();
    cout << "\n";

    beginInsert(2);
    print();
    cout << "[insert 2]";
    
    beginInsert(1);
    cout << "\n";
    print();
    cout << "[insert 1]";

    append(989);
    cout << "\n";
    print();
    cout << "[insert at end 989]";

    cout << "\n";
    reversePrint();  
    cout << "[print reversly]"; 

    deleteNode(4);
    cout << "\n";
    print();
    cout << "[delete 4]";

    deleteNode(33);
    cout << "\n";
    print();
    cout << "[delete 33]";

    deleteNode(1);
    cout << "\n";
    print();
    cout << "[delete 1]";

    deleteNode(989);
    cout << "\n";
    print();
    cout << "[delete 989]";   
}
