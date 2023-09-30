#include <iostream>
#include <map>
using namespace std;

class Node{
public:

    int data;
    Node *next;

    // Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    // Destructor
    ~Node(){
        int value = this -> data;
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }

        cout<<"Memory is freed for node with data "<< value <<endl;
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

void deleteNode(Node* &head, int position){

    // deleting starting wali Node
    if(position == 1){
        Node* temp = head;
        head = head -> next;

        // memory free start Node
        temp -> next = NULL;
        delete temp;
    }
    else{
        // deleting any middle Node or last Node

        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

    }
}

bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL){

        //cycle is present
        if(visited[temp] == true){
            cout<<"present on element "<<temp->data<<endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node* floydDetectLoop(Node* head){
    if(head == NULL)
       return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast){
            cout << "Present at " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;
}

Node* getStartingNode(Node* &head){

    if(head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}

void removeLoop(Node* head){
    if(head == NULL){
        return;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }

    temp -> next = NULL;

}


void Print(Node* &head){

        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        } cout<<endl;
    }


int main(){

    Node* node1 = new Node(10);
   
    Node* head = node1;
    Node* tail = node1;

    // cout<< node1 -> data<<endl;
     Print(node1);


    insertAtHead(head, 87);
    Print(head);

    insertAtHead(head, 88);
    Print(head);

    insertAtHead(head, 89);
    Print(head);

    insertAtTail(tail, 11);
    Print(head);

    insertAtTail(tail, 12);
    Print(head);

    insertAtPosition(head, tail, 4, 9);
    Print(head);

    // deleteNode(head, 1);
    // Print(head);

    // deleteNode(head, 1);
    // Print(head);

    tail->next = head->next;

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    if(floydDetectLoop(head)){
        cout << " Cycle is Present " << endl;
    }
    else{
        cout << " No Cycle is Present " << endl;
    }

   removeLoop(head);

   if(floydDetectLoop(head)){
        cout << " Cycle is Present " << endl;
    }
    else{
        cout << " No Cycle is Present " << endl;
    }

    return 0;
}