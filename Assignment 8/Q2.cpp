#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
};

Node* newNode(int data){
    Node* newNode = new Node;
    newNode-> data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key){
    if(root == NULL ){
        return newNode(key);
    }
    if (key < root->data) {
    root->left = insert(root->left, key);
} 
else if (key > root->data) {
    root->right = insert(root->right, key);
}
return root;
}

Node* SearchRecursive(Node* root,int key){
    if(root == NULL || root->data == key){
        return root;
    }
  if(key < root->data){
        return SearchRecursive(root->left,key);
    }
    else if (root->data < key){
        return SearchRecursive(root->right,key);
    }
    return root;
}

Node* SearchNonRecursive(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;   //agar kuch nhi root nhi milta or roor nhi return hota toh null return krdo 
}

Node* maxElement(Node* root){

    if (root == nullptr)
        return nullptr; // Empty tree, no max element

    while(root->right != nullptr){
        root = root->right;
    }
    return root;
}

Node* minElement(Node* root){
    if(root == nullptr){
        return nullptr;
    }

    while (root->left != nullptr){
        root = root->left;
    }
    return root;
}

Node* inorderSuccessor(Node* root, Node* x) {
    if (x->right != nullptr)
        return minElement(x->right);  // ✅ Case 1

    // 🔹 Case 2 starts here
    Node* successor = nullptr;
    while (root != nullptr) {
        if (x->data < root->data) {
            successor = root;  // potential successor
            root = root->left; // move left
        }
        else if (x->data > root->data) {
            root = root->right; // move right
        }
        else
            break;
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* x) {
    // Case 1: Node has left subtree
    if (x->left != nullptr)
        return maxElement(x->left);

    // Case 2: No left subtree
    Node* predecessor = nullptr;
    while (root != nullptr) {
        if (x->data > root->data) {
            predecessor = root;  // potential predecessor
            root = root->right;
        }
        else if (x->data < root->data)
            root = root->left;
        else
            break;
    }
    return predecessor;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<< root->data <<" ";
    inOrder(root->right);
}

int main(){

Node* root = NULL;

root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout<<"inOrder sequence = ";
    inOrder(root);
    cout<<endl;
    int key = 20;
    cout<<" search for recursive function = ";
  Node* result1 = SearchRecursive(root,key);
    if (result1 != NULL){
        cout<<"found "<<endl;
    }
    else{
        cout<<"not found "<<endl;
    }
    key = 100;
    
    cout<<"search for non recursive function = ";
   Node* result2 = SearchNonRecursive(root,key);
    if(result2 != NULL){
          cout<<"found "<<endl;
    }
    else{
        cout<<"not found "<<endl;
    }
    
    Node* max = maxElement(root);
    cout<< " max element of bst is = "<<max->data ;  //do not use only max here as max is a node pointer itself so to print no we had to print max->data
    cout<<endl;
    Node* min = minElement(root);
    cout<< " min element of bst is = "<<min->data ;
    cout<<endl;
    Node* x = SearchRecursive(root,20);  //first search element as store as node
    Node* successor = inorderSuccessor(root,x);   //we will not pass no but we will pass an element 
    cout<<"in order successor = "<<successor->data;
    cout<<endl;
    Node* y = SearchRecursive(root,30);
    Node*  predecessor= inorderPredecessor(root,y);
    cout<<"pre order successor = "<<predecessor->data;
    cout<<endl;

    return 0;

}