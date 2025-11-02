#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *right, *down, *left, *up;
    Node(int x) {
        data = x;
        right = down = left = up = NULL;
    }
};

Node* constructDLL(int mat[][3], int n, int m) {
    Node* head = NULL;
    Node* prevRow[m];
    for (int i = 0; i < m; i++) prevRow[i] = NULL;

    for (int i = 0; i < n; i++) {
        Node* prev = NULL;
        for (int j = 0; j < m; j++) {
            Node* curr = new Node(mat[i][j]);
            if (!head) head = curr;
            if (prev) {
                prev->right = curr;
                curr->left = prev;
            }
            if (prevRow[j]) {
                prevRow[j]->down = curr;
                curr->up = prevRow[j];
            }
            prevRow[j] = curr;
            prev = curr;
        }
    }
    return head;
}

void printList(Node* head, int n, int m) {
    Node* row = head;
    for (int i = 0; i < n; i++) {
        Node* col = row;
        for (int j = 0; j < m; j++) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n = 3, m = 3;
    Node* head = constructDLL(mat, n, m);
    printList(head, n, m);
    return 0;
}
