#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){

    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of "<< data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of "<< data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            // purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()){
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp->data <<" ";
            if(temp -> left){
                q.push(temp -> left);
            }

            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void preOrderTraversal(Node* root){

    if(root == NULL){
        return;
    }

    cout << root->data << endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// 1 3 -1 -1 5 -1 -1

int main(){

    Node* root = NULL;
    buildTree(root);
    levelOrderTraversal(root);
    
    return 0;
}