//Write a program to implement the following operations on a Sparse Matrix, assuming the matrix is represented using a triplet.
// Multiplication of two matrices.

#include <iostream>
using namespace std;

int main() {
    int rowsA, colsA, nonZeroA;
    int rowsB, colsB, nonZeroB;

    cout << "Enter rows, columns and non-zero elements for Matrix A: ";
    cin >> rowsA >> colsA >> nonZeroA;

    int rowA[nonZeroA], colA[nonZeroA], valA[nonZeroA];
    cout << "Enter triplets (row col val) for Matrix A (0-indexed):\n";
    for (int i = 0; i < nonZeroA; i++) {
        cin >> rowA[i] >> colA[i] >> valA[i];
    }

    cout << "Enter rows, columns and non-zero elements for Matrix B: ";
    cin >> rowsB >> colsB >> nonZeroB;

    if (colsA != rowsB) {
        cout << "Matrix multiplication not possible: cols of A != rows of B\n";
        return 0;
    }

    int rowB[nonZeroB], colB[nonZeroB], valB[nonZeroB];
    cout << "Enter triplets (row col val) for Matrix B (0-indexed):\n";
    for (int i = 0; i < nonZeroB; i++) {
        cin >> rowB[i] >> colB[i] >> valB[i];
    }

   
    int maxRes = nonZeroA * nonZeroB;
    int resRow[maxRes], resCol[maxRes], resVal[maxRes];
    int resCount = 0;

   
    for (int i = 0; i < nonZeroA; i++) {
        for (int j = 0; j < nonZeroB; j++) {
            if (colA[i] == rowB[j]) {
                
                int r = rowA[i];
                int c = colB[j];
                int v = valA[i] * valB[j];

                
                bool found = false;
                for (int k = 0; k < resCount; k++) {
                    if (resRow[k] == r && resCol[k] == c) {
                        resVal[k] += v;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    resRow[resCount] = r;
                    resCol[resCount] = c;
                    resVal[resCount] = v;
                    resCount++;
                }
            }
        }
    }

   
    int finalCount = 0;
    for (int i = 0; i < resCount; i++) {
        if (resVal[i] != 0) {
            resRow[finalCount] = resRow[i];
            resCol[finalCount] = resCol[i];
            resVal[finalCount] = resVal[i];
            finalCount++;
        }
    }

    cout << "\nResultant matrix after multiplication (row col value):\n";
    for (int i = 0; i < finalCount; i++) {
        cout << resRow[i] << " " << resCol[i] << " " << resVal[i] << "\n";
    }

    return 0;
}