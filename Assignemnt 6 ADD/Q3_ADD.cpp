#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    return temp;
}

Node* reverseInGroups(Node* head, int k) {
    if (!head) return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* newHead = NULL;
    int count = 0;

    while (current && count < k) {
        next = current->next;
        current->next = current->prev;
        current->prev = next;
        newHead = current;
        current = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverseInGroups(next, k);
        if (head->next != NULL)
            head->next->prev = head;
    }

    return newHead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->prev = head;
    head->next->next = newNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    int k = 4;
    head = reverseInGroups(head, k);

    printList(head);
    return 0;
}
