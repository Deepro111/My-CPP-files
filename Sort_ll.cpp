#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{

    // Creating a new Node
    Node *temp = new Node(d);

    // temp->data = d;

    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{

    // Creating a new Node
    Node *temp = new Node(d);

    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{

    // to insert at starting position
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < (position - 1))
    {
        temp = temp->next;
        count++;
    }

    // to insert at last position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d to insert it inbetween the list

    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}

Node *SortList(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // Create separate list 0s, 1s and 2s
    while (curr != NULL)
    {
        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // Now merge 3 sublists
    // 1s list not empty
    if(oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        // 1s list is empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup head
    head = zeroHead->next;

    // delete dummy Nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

void Print(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
 
    Node *node1 = new Node(3);

    Node *head = node1;
    Node *tail = node1;

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

    // uniqueSorted(head);
    // Print(head);

    return 0;
}