#include<iostream>
#include<map>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    //Constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    // Destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }

        cout<< "Memory is free for node with data "<< value <<endl;
    }
};

void insertNode(Node* &tail, int element, int d){
    // empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
    }
    else{
        // assuming that element is presentin the list i.e. non empty list

        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }

        // curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    // Empty value
    if(tail == NULL){
        cout << " List is empty, please check again"<<endl;
        return;
    }
    else{
        //non-empty
        //assuming that value is present in the linked list
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node linked list
        if(curr == prev){
            tail == NULL;
        }

        // >=2 Node linked list
        else if(tail == curr){
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* tail){

    Node* temp = tail;

    // empty list
    // if(tail == NULL){
    //     cout<<"List is empty"<<endl;
    //     return;
    //}

   do{
    cout<<tail -> data <<" ";
    tail = tail -> next;
   } while(tail != temp);

   cout<<endl;
}

bool isCircularList(Node* head){
    //empty list
    if(head == NULL){
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }

    if(temp == head){
        return true;
    }

    return false;
}




int main(){

    Node* tail = NULL;
    // Node* tail = new Node(7);

    //insertNode(tail, 7, 50);
    //print(tail);

    if(isCircularList(tail)){
        cout<<" Linked List is Circular in nature"<<endl;
    }
    else{
        cout<<"Linked List is not Circular"<<endl;
    }
    
    return 0;
}