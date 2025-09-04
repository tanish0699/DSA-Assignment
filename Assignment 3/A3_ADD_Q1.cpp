// Given an array A, find the nearest smaller element for every element A[i] in the array such that the element has an index smaller than i


#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements = ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements = ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            cout << -1 << " ";  // No smaller element to the left
        } else {
            cout << s.top() << " ";  // Nearest smaller to left
        }
        s.push(arr[i]);
    }
    cout << endl;

    return 0;
}