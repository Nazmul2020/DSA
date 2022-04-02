/*
    circular single linked list 
    programm written by nazmul hasan
*/
    
#include<iostream>
using namespace std;

struct node{
    int num;
    node *next;
};
node *root = NULL;
node *tail = NULL;

void insertBeforeValue(int newNum, int num);
void insert_at_head(int num);
void insert_at_tail(int num);
void insert_at_middle(int num, int position);

void delete_at_head();
void delete_at_tail();
void delete_at_middle(int position);
void print();

int main(){

    insert_at_tail(3);
    insert_at_tail(4);
    insert_at_tail(6);
    insert_at_tail(8);
    insert_at_tail(33);
    insert_at_tail(234);
    print();
    insert_at_head(2);
    print();
    insertBeforeValue(78,33);
    print();
    insert_at_middle(47,4);
    print();

    cout << "delete \n";

   delete_at_head();
   print();

    delete_at_tail();
   print();

    delete_at_middle(3);
    print();

}


void insert_at_tail(int num){
    if(root == NULL){ // if empty node
        root = new node(); //create new node in root
        root->num = num;
        root->next = root;
        tail = root;
    }
    else{
        node *newNode = new node(); //create new node
        newNode->num = num;
        newNode->next = root;
        tail->next = newNode; //link the last node with the new node
        tail = newNode;
    }
    

}

void insert_at_head(int num){
    if(root == NULL){ // if empty node
        root = new node(); //create new node in root
        root->num = num;
        root->next = root;
        tail = root;
    }
    else{
        node *newNode = new node(); //create new node
        newNode->num = num;
        newNode->next = root;
        root = newNode;
        tail->next = root;
    }

}

void insert_at_middle(int num, int position){
    if(position == 1){
        insert_at_head(num);
        return;
    }
    
    else if(position > 1 && root != NULL){
        node *currentNode = root;
        node *temp = new node();
        int count = 0;
        do{
            count++;
            temp = currentNode;
            currentNode = currentNode->next;

        }while(currentNode->next != root && count<position-1);

        if(count == position-1){
            if(temp == tail)
                insert_at_tail(num);
            else{
                node *newNode = new node();
                newNode->num = num;
                newNode->next = currentNode;
                temp ->next = newNode;
            }
            return;
        }

    }
    cout << "position does not exist\n";      

}

void print(){
    node *currentNode = root; // make a copy of root node
    do{
        cout << currentNode->num << " " ;
        currentNode = currentNode->next; //go to the next node
    }while(currentNode!=root);

    cout << "\n";
}

void delete_at_head(){
    if(root == NULL)
        return;

    node *temp = root;
    root = root->next;
    tail->next = root;
    delete(temp);
}

void delete_at_tail(){
    if(root == NULL)
        return;
    node *currentNode = root;
    node *previousNode = NULL;
    while(currentNode != tail ){
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    previousNode->next = root;
    tail = previousNode;
    delete(currentNode);
    
}

void delete_at_middle(int position){
    if(position == 1){
        delete_at_head();
        return;
    }
    node *currentNode = root->next;
    node *previousNode = root;
    int count=2;
    
    while(currentNode->next != tail && count<position){
        count++;
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode->next != tail && count == position){
        previousNode->next = currentNode->next;
        delete(currentNode);
    }
    else if(currentNode->next == tail && count == position){
        delete_at_tail();
        return;
    }
       
    else
        cout << "position does not exist\n";
}

void insertBeforeValue(int newNum, int num ){
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
        insert_at_head(num);
        return;
    }
    else if(currentNode == tail){
        insert_at_tail(num);
        return;
    }
    else{
        previousNode->next = newNode;
        newNode->next = currentNode;
        
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
