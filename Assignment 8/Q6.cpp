#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;
    bool isMaxHeap;

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && compare(heap[i], heap[parent])) {
            swap(heap[i], heap[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int size = heap.size();
        while (true) {
            int left = 2 * i + 1, right = 2 * i + 2, extreme = i;
            if (left < size && compare(heap[left], heap[extreme])) extreme = left;
            if (right < size && compare(heap[right], heap[extreme])) extreme = right;
            if (extreme != i) {
                swap(heap[i], heap[extreme]);
                i = extreme;
            } else break;
        }
    }

    bool compare(int a, int b) {
        return isMaxHeap ? a > b : a < b;
    }

public:
    PriorityQueue(bool maxHeap = true) { isMaxHeap = maxHeap; }

    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    void print() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pqMax(true);
    pqMax.push(30);
    pqMax.push(10);
    pqMax.push(50);
    pqMax.push(20);

    cout << "Max Heap Priority Queue: ";
    pqMax.print();

    cout << "Top element: " << pqMax.top() << endl;
    pqMax.pop();
    cout << "After deleting top: ";
    pqMax.print();

    PriorityQueue pqMin(false);
    pqMin.push(30);
    pqMin.push(10);
    pqMin.push(50);
    pqMin.push(20);

    cout << "Min Heap Priority Queue: ";
    pqMin.print();

    cout << "Top element: " << pqMin.top() << endl;
    pqMin.pop();
    cout << "After deleting top: ";
    pqMin.print();

    return 0;
}
