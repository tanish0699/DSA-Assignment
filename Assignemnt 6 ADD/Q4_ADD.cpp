#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* random;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = temp->prev = temp->random = NULL;
    return temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Data = " << temp->data;
        if (temp->random)
            cout << ", Random = " << temp->random->data;
        else
            cout << ", Random = NULL";
        cout << endl;
        temp = temp->next;
    }
}

void correctRandom(Node* head) {
    if (!head) return;
    int n = 0;
    Node* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }
    Node* arr[n];
    temp = head;
    for (int i = 0; i < n; i++) {
        arr[i] = temp;
        temp = temp->next;
    }
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (arr[i]->random == arr[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            arr[i]->random = arr[i];
            break;
        }
    }
}

int main() {
    Node* head = newNode(10);
    Node* second = newNode(20);
    Node* third = newNode(30);
    Node* fourth = newNode(40);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    head->random = head;
    second->random = second;
    third->random = head;
    fourth->random = newNode(99);
    cout << "Before correction:\n";
    printList(head);
    correctRandom(head);
    cout << "\nAfter correction:\n";
    printList(head);
    return 0;
}
