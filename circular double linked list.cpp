#include<iostream>
using namespace std;

struct node{
    int num;
    node *next, *prev;
};

node *root, *tail;

void insert_at_head(int num);
void insert_at_tail(int num);
void insert_at_middle(int num, int position);

void delete_at_head();
void delete_at_tail();
void delete_at_middle(int position);

void print();
void reversePrint();

int main(){
    insert_at_tail(3);
    insert_at_tail(4);
    insert_at_tail(6);
    insert_at_tail(8);
    insert_at_tail(33);
    insert_at_tail(234);

    print();
    cout << "[list print]\n\n";

     insert_at_head(2);
     print();
    cout << "[insert at head 2]\n\n";
    
    insert_at_head(1);
    print();
    cout << "[insert at head 1]\n\n";

    insert_at_tail(989);
    print();
    cout << "[insert at tail 989]\n\n";

    reversePrint();  
    cout << "[print reversly]\n\n"; 

    insert_at_middle(45,3);
    print();
    cout << "[insert at 3 position 45]\n\n";

    delete_at_head();
    print();
    cout << "[delete at head]\n\n";

    delete_at_tail();
    print();
    cout << "[delete at tail]\n\n";

    delete_at_middle(8);
    print();
    cout << "[delete at 8 position]\n\n";

    delete_at_middle(1);
    print();
    cout << "[delete at 1 position]\n\n";
    cout <<"\n";

    delete_at_middle(6);
    print();
    cout << "[delete at 6 position]\n\n";
    cout <<"\n";

    insert_at_middle(25,1);
    print();
    cout << "[insert at head 25]\n\n";

    insert_at_middle(83,6);
    print();
    cout << "[insert at tail 83]\n\n";  

    
}


void insert_at_tail(int num){ //if linked empty
    if(root == NULL){
        root = new node();
        root->num = num;
        root->next = root;
        root->prev = root;
        tail = root;
    }
    else{
        node *newNode = new node();
        newNode->num = num; // store value in new node
        newNode->next = root; 
        newNode->prev = tail; //point to the previous node
        tail->next = newNode; //point to the next node
        tail = newNode; // point to the previous node
        root->prev = newNode;
    }
}

void insert_at_head(int num){
    if(root == NULL){
        root = new node();
        root->num = num;
        root->next = root;
        root->prev = root;
        root = tail; // tail = root is same
    }
    else{
        node *newNode = new node();
        newNode->num = num; // store value in new node
        newNode->prev = tail; 
        newNode->next = root; //point to the previous node
        root->prev = newNode; //point to the next node
        root = newNode; // point to the previous node
        tail->next = newNode;
    }
}

void insert_at_middle(int num, int position){
    if(position == 1){
        insert_at_head(num);
        return;
    }
    
    else if(position > 1 && root != NULL){
        node *currentNode = root;
        node *previousNode = NULL;
        int count = 1;
        do{
            count++;
            previousNode = currentNode;
            currentNode = currentNode->next;

        }while(currentNode != root && count<position);

        if(count == position){
            if(currentNode == tail)
                insert_at_tail(num);
            else{
                node *newNode = new node();
                newNode->num = num;
                newNode->next = currentNode;
                currentNode->prev = newNode;
                previousNode->next = newNode;
                newNode->prev = previousNode;
            }
            return;
        }

    }
    cout << "position does not exist\n";      

}

void print(){
    node *currentNode = root;
    do{
        cout << currentNode->num <<" ";
        currentNode = currentNode->next;
    }while(currentNode!= root);
}

void reversePrint(){
    node *currentNode = tail;
    do{
        cout << currentNode->num <<" ";
        currentNode = currentNode->prev;
    } while(currentNode != tail);
}

void delete_at_head(){
   if(root == NULL) return;
    node *temp = root;
    tail->next = root->next;
    root->next->prev = tail;
    root = root->next;
    delete(temp);
    
}

void delete_at_tail(){
    if(root == NULL) return;
    node *temp = tail;
    root->prev = tail->prev;
    tail->prev->next = root;
    tail=tail->prev;
    delete(temp);
    
}

void delete_at_middle(int position){
    if(position == 1){
        delete_at_head();
        return;
    }
    node *currentNode = root->next;
    node *previousNode = root;
    int count=2;
    
    while(currentNode != root && count<position){
        count++;
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode != tail && count == position){
        previousNode->next = currentNode->next;
        currentNode->next->prev = previousNode;
        delete(currentNode);
    }
    else if(currentNode == tail && count == position){
        delete_at_tail();
        return;
    }
       
    else
        cout << "position does not exist\n";
}

