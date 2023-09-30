#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
                  
        //Creating a new Node
        Node *temp = new Node(d); 

        // temp->data = d;

        temp->next = head;
        head = temp;
    }

void insertAtTail(Node* &tail, int d){

    //Creating a new Node
    Node* temp = new Node(d);

    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){

    // to insert at starting position
    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < (position - 1)){
        temp = temp->next;
        count++;
    }

    // to insert at last position
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return ;
    }

    // creating a node for d to insert it inbetween the list

    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

Node* uniqueSorted(Node* head){
    //empty lis
    if(head == NULL){
        return NULL;
    }

    //non empty list
    Node* curr = head;

    while(curr != NULL){

        if((curr -> next != NULL) && (curr -> data == curr -> next -> data)){
            Node* next_next = curr -> next -> next;
            Node* nodetoDelete = curr -> next;
            delete(nodetoDelete);
            curr -> next = next_next;
        }
        else{
            curr = curr -> next;
        }
    }

    return head;
}

void Print(Node* &head){

        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        } cout<<endl;
    }

int main(){

    Node* node1 = new Node(3);
   
    Node* head = node1;
    Node* tail = node1;

    insertAtPosition(head, tail, 1, 1);
    Print(head);
    
    insertAtPosition(head, tail, 2, 2);
    Print(head);
    
    insertAtPosition(head, tail, 3, 2);
    Print(head);
    
    insertAtPosition(head, tail, 4, 2);
    Print(head);
    
    insertAtPosition(head, tail, 5, 3);
    Print(head);

    uniqueSorted(head);
    Print(head);
    
    return 0;
}

