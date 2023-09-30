#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    // Destructor
    ~Node(){
        int value = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory freed for node with data "<< value <<endl;
    }
};

void insertAtHead(Node* &tail, Node* &head, int d){

    //Empty List

    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d){

    //Empty List

    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){

    // insert at start
    if(position == 1){
        insertAtHead(tail, head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp->next;
        count++;
    }

    // insert at last position
    if(temp -> next == NULL){
        insertAtTail(tail, head, d);
        return;
    }

    //creating a new node for d
    Node* nodetoInsert = new Node(d);

    nodetoInsert -> next = temp -> next;
    temp -> next -> prev = nodetoInsert;
    temp -> next = nodetoInsert;
    nodetoInsert -> prev = temp;
}

int getlength(Node* &head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }

    return len;
}

void deleteNode(Node* &head, int position){

    //deleting starting wali Node
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        delete temp;
    }
    else{
        // to delete any middle or last Node

        Node* curr = head;
        Node* prev = NULL;

        int count = 1;

        while(count < position){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

       free(curr);
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data <<" ";

        temp = temp -> next;
    }
    cout<<endl;
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;

    // print(head);

    insertAtHead(tail, head, 49);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    insertAtHead(tail, head, 48);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    insertAtTail(tail, head, 50);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    insertAtPosition(tail, head, 2, 76);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    cout << "length of our linked list is "<<getlength(head) <<endl;

    deleteNode(head, 2);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    cout << "length of our linked list is "<<getlength(head) <<endl;

    
    return 0;
}