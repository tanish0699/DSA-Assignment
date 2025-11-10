#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> v1, v2, merged;
    inorder(root1, v1);
    inorder(root2, v2);
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) merged.push_back(v1[i++]);
        else merged.push_back(v2[j++]);
    }
    while (i < v1.size()) merged.push_back(v1[i++]);
    while (j < v2.size()) merged.push_back(v2[j++]);

    Node* head = NULL;
    Node* prev = NULL;
    for (int val : merged) {
        Node* node = new Node(val);
        if (!head) head = node;
        node->left = prev;
        if (prev) prev->right = node;
        prev = node;
    }
    return head;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->data << " <—> ";
        head = head->right;
    }
    cout << "null" << endl;
}

int main() {
    Node* T1 = NULL;
    Node* T2 = NULL;
    T1 = insert(T1, 20);
    insert(T1, 10);
    insert(T1, 30);
    insert(T1, 25);
    insert(T1, 100);
    insert(T1, 50);
    T2 = insert(T2, 5);
    insert(T2, 70);

    Node* head = mergeBSTs(T1, T2);
    printDLL(head);
    return 0;
}
