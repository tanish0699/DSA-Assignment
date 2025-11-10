#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* current = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != -1) {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

vector<int> rightView(Node* root) {
    vector<int> view;
    if (!root) return view;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            if (i == size - 1) view.push_back(current->data);
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
    return view;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Node* root = buildTree(arr);
        vector<int> result = rightView(root);
        for (int val : result) cout << val << " ";
        cout << endl;
    }
    return 0;
}
