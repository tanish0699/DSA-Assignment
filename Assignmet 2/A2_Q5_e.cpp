//symmetric matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of symmetric matrix (n x n): ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int arr[size];

    cout << "Enter elements of lower triangular part of symmetric matrix row-wise:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int idx = (i * (i + 1)) / 2 + j;
            cin >> arr[idx];
        }
    }

    cout << "\nFull matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int idx;
            if (i >= j) {
                idx = (i * (i + 1)) / 2 + j;
                cout << arr[idx] << " ";
            } else {
                idx = (j * (j + 1)) / 2 + i;
                cout << arr[idx] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}