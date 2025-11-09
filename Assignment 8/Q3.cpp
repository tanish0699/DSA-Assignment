#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return newNode(key);
    }
    if (root->data > key) {
        root->left = insert(root->left, key);
    } else if (root->data < key) {
        root->right = insert(root->right, key);
    } else {
        cout << "duplicate not allowed" << endl;
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;
    int maxLeft = maxDepth(root->left);
    int maxRight = maxDepth(root->right);
    return 1 + max(maxLeft, maxRight);
}

int minDepth(Node* root) {
    if (root == nullptr)
        return 0;
    if (root->left == nullptr)
        return 1 + minDepth(root->right);
    if (root->right == nullptr)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

Node* minElement(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minElement(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(nullptr, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 25);

    cout << "inorder sequence is = ";
    inOrder(root);
    cout << endl;

    cout << "maximum depth = " << maxDepth(root) << endl;
    cout << "minimum depth = " << minDepth(root) << endl;

    deleteNode(root, 10);
    inOrder(root);
    return 0;
}
