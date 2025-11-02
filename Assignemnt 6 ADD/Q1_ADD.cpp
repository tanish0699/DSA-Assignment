#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    if (head == NULL)
        return;

    while (fast_ptr->next != head && fast_ptr->next->next != head) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    *head1_ref = head;

    if (head->next != head)
        *head2_ref = slow_ptr->next;

    fast_ptr->next = slow_ptr->next;
    slow_ptr->next = head;
}

void printList(Node* head) {
    Node* temp = head;
    if (head != NULL) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    cout << endl;
}

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    Node* head = newNode(10);
    head->next = newNode(4);
    head->next->next = newNode(9);
    head->next->next->next = head;

    Node* head1 = NULL;
    Node* head2 = NULL;

    splitList(head, &head1, &head2);

    printList(head1);
    printList(head2);

    return 0;
}
