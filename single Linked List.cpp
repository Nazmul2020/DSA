#include<iostream>
using namespace std;

struct node{
    int num;
    node *next;
};
node *root = NULL;

//insert for last node
void append(int num){
    if(root == NULL){ // if empty node
        root = new node(); //create new node in root
        root->num = num;
        root->next = NULL;
    }
    else{
        node *currentNode = root; //copy root node to current node
        while(currentNode->next != NULL){ //find the last node
            currentNode = currentNode->next; // go to next address
        }
        node *newNode = new node(); //create new node
        newNode->num = num;
        newNode->next = NULL;
        currentNode->next = newNode; //link the last node with the new node
    }
    

}

void print(){
    node *currentNode = root; // make a copy of root node
    while(currentNode!=NULL){ //print untill NULL get
        cout << currentNode->num << " " ;
        currentNode = currentNode->next; //go to the next node
    }
}

void deleteNode(int num){
    node *currentNode = root; // copy root node
    node *previousNode = NULL;
    while(currentNode->num!=num){ // searching num
        previousNode = currentNode; // remember previous node address
        currentNode = currentNode->next; // go to the next address
    }
    if(currentNode == root){ // delete root
      node *temp = root; // save root in temp variable
      root = root->next; // move root to forward
      delete(temp); //free memory
    }
    else{ //delete non root node
        previousNode->next = currentNode->next; // previous node point to the current node's next node
        delete(currentNode);  //free memory
    }
}

void insertNodeBeforValue(int newNum, int num ){
    node *currentNode = root; //make copy of root
    node *previousNode = NULL;

    while(currentNode->num!=num){ //searching number
        previousNode = currentNode; 
        currentNode = currentNode->next;
    }
    node *newNode = new node();
    newNode->num = newNum;
    newNode->next = currentNode;
    if(currentNode == root){
         node *temp = root;
        root = newNode;
        root->next = temp;
    }
    else{
        previousNode->next = newNode;
        
    }

}

int nodeCount(){
    int count = 0;
    node *currentNode = root;
    while(currentNode != NULL){
        count++;
        currentNode = currentNode->next;
    }
    return count;
}
int main(){

    append(3);
    append(4);
    append(6);
    append(8);
    append(33);
    append(234);
    cout << nodeCount() << "\n";
    print();
    cout<<"\n";
    deleteNode(8);
    cout << nodeCount() << "\n";
    print();
    cout <<"\n";

    insertNodeBeforValue(23,33); // 23 insert before 33, if 33 is exist
    print();
}
