#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

  Node* newNode(int data){
    Node* newNode = new Node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    };

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
 cout<< root->data<<" " ;
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
inOrder(root->left);
   cout<< root->data<< " ";
   inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
postOrder(root->left);
 postOrder(root->right);
cout<< root->data<<" " ;
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"pre order series = ";
    preOrder(root);
    cout<<endl;
    cout<<"in order series = ";
    inOrder(root);
    cout<<endl;
    cout<<" post Order series = ";
    postOrder(root);
    cout<<endl;
    return 0;

}

