#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:

    int data;
    Node* next = NULL;

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

// bool CheckPalindrome(vector<int> arr){
    
//     int n = arr.size();
//     int s = 0;
//     int e = n-1;

//     while(s<=e){
//         if(arr[s] != arr[e]){
//             return false;
//         }
//         s++;
//         e--;
//     }
//     return true;
// }

// bool isPalindrome(Node* head){
//     vector<int> arr;

//     Node* temp = head;
//     while(temp != NULL){
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     return CheckPalindrome(arr);
// }

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* reverse(Node* head){
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head){
    if(head == NULL){
        return true;
    }

    //step 1 : Find middle 
    Node* middle = getMid(head);

    //step 2 : Reverse list after Middle
    Node* temp = middle -> next;

    middle -> next = reverse(temp);

    //step 3 : Compare Both halves
    Node* head1 = head;
    Node* head2 = middle -> next;

    while(head2 != NULL){
        if(head2->data != head1->data){
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    } 

    //step 4 : repeat step 2
    temp = middle -> next;
    middle -> next = reverse(temp);

    return true;
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

    insertAtHead(head, 10);
    insertAtPosition(head, tail, 2, 1);
    insertAtPosition(head, tail, 3, 1);
    // insertAtPosition(head, tail, 4, 2);
    // insertAtPosition(head, tail, 5, 2);

    if(isPalindrome(head)){
        cout<<"Linked List is Palindrome"<<endl;
    }
    else{
        cout<<"Linked List is Not Palindrome"<<endl;
    }
    
    return 0;
}