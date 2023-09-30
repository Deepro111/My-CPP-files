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
void Print(Node* &head){

        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        } cout<<endl;
    }


Node* KReverse(Node* head, int k){
    // base call
    if(head == NULL){
        return NULL;
    }

    //Step 1 : Reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //Step 2 : Recursion dekh lega aage ka
    if(next != NULL){
        head -> next = KReverse(next , k);
    }

    //Step 3 : return head of reversed list
    return prev;
}

int main(){

    Node* node1 = new Node(10);
   
    Node* head = node1;
    Node* tail = node1;

    // cout<< node1 -> data<<endl;
     Print(node1);


    // insertAtHead(head, 87);
    // Print(head);

    // insertAtHead(head, 88);
    // Print(head);

    // insertAtHead(head, 89);
    // Print(head);

    insertAtTail(tail, 11);
    Print(head);

    insertAtTail(tail, 12);
    Print(head);

    // insertAtPosition(head, tail, 4, 9);
    // Print(head);

    KReverse(head, 2);
    Print(head);

    
    return 0;
}