#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

void removeLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // Detect loop
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow != fast)
        return; // No loop

    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL; // Remove loop
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // loop

    removeLoop(head);
    cout << "Loop removed successfully.";
}
