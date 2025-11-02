#include <iostream>
using namespace std;

struct NodeDLL {
    int data;
    NodeDLL* next;
    NodeDLL* prev;
};

struct NodeCLL {
    int data;
    NodeCLL* next;
};

int countParity(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

NodeDLL* removeEvenParityDLL(NodeDLL* head) {
    NodeDLL* curr = head;
    while (curr) {
        int p = countParity(curr->data);
        if (p % 2 == 0) {
            NodeDLL* temp = curr;
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next;
            if (curr->next)
                curr->next->prev = curr->prev;
            curr = curr->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

NodeCLL* removeEvenParityCLL(NodeCLL* head) {
    if (!head) return NULL;
    NodeCLL *curr = head, *prev = NULL;
    NodeCLL *start = head;

    do {
        int p = countParity(curr->data);
        if (p % 2 == 0) {
            if (curr == head) {
                NodeCLL* temp = head;
                while (temp->next != head)
                    temp = temp->next;
                temp->next = head->next;
                head = head->next;
                curr = head;
                if (head == start) return NULL;
                continue;
            } else {
                prev->next = curr->next;
                NodeCLL* temp = curr;
                curr = curr->next;
                delete temp;
                continue;
            }
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    return head;
}

void printDLL(NodeDLL* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <=> ";
        head = head->next;
    }
    cout << endl;
}

void printCLL(NodeCLL* head) {
    if (!head) return;
    NodeCLL* temp = head;
    do {
        cout << temp->data;
        temp = temp->next;
        if (temp != head) cout << " -> ";
    } while (temp != head);
    cout << endl;
}

int main() {
    NodeCLL* headCLL = new NodeCLL{9, NULL};
    headCLL->next = new NodeCLL{11, NULL};
    headCLL->next->next = new NodeCLL{34, NULL};
    headCLL->next->next->next = new NodeCLL{6, NULL};
    headCLL->next->next->next->next = new NodeCLL{13, NULL};
    headCLL->next->next->next->next->next = new NodeCLL{21, headCLL};

    headCLL = removeEvenParityCLL(headCLL);
    printCLL(headCLL);

    NodeDLL* headDLL = new NodeDLL{18, NULL, NULL};
    headDLL->next = new NodeDLL{15, NULL, headDLL};
    headDLL->next->next = new NodeDLL{8, NULL, headDLL->next};
    headDLL->next->next->next = new NodeDLL{9, NULL, headDLL->next->next};
    headDLL->next->next->next->next = new NodeDLL{14, NULL, headDLL->next->next->next};

    headDLL = removeEvenParityDLL(headDLL);
    printDLL(headDLL);

    return 0;
}
