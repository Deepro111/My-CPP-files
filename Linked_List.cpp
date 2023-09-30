#include <iostream>
using namespace std;

class Node{
public:

    int data;
    Node *next;

    Node(int d){
    }
};

void insertAtHead(Node* &head, int d){
                  
        //Creating a new Node
        Node *temp = new Node(d);

        temp->data = d;

        temp->next = head;
        head = temp;
    }

void Print(Node* &head){

        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        } cout<<endl;
    }


int main(){

    Node* node;

    insertAtHead(node, 87);
    // Print(node);

    insertAtHead(node, 88);
   //Print(node);

    insertAtHead(node, 89);
    Print(node);

    return 0;
}