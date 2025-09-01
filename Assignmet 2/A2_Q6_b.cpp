//Write a program to implement the following operations on a Sparse Matrix, assuming the matrix is represented using a triplet.
// Addition of two matrices

#include <iostream>
using namespace std;

int main() {
    int rows1, cols1, nonZero1;
    int rows2, cols2, nonZero2;

    cout << "Enter rows, columns and non-zero elements for Matrix 1: ";
    cin >> rows1 >> cols1 >> nonZero1;

    int row1[nonZero1], col1[nonZero1], val1[nonZero1];
    cout << "Enter triplets (row col val) for Matrix 1 (0-indexed):\n";
    for (int i = 0; i < nonZero1; i++) {
        cin >> row1[i] >> col1[i] >> val1[i];
    }

    cout << "Enter rows, columns and non-zero elements for Matrix 2: ";
    cin >> rows2 >> cols2 >> nonZero2;

    if (rows1 != rows2 || cols1 != cols2) {
        cout << "Matrices dimensions must be same for addition.\n";
        return 0;
    }

    int row2[nonZero2], col2[nonZero2], val2[nonZero2];
    cout << "Enter triplets (row col val) for Matrix 2 (0-indexed):\n";
    for (int i = 0; i < nonZero2; i++) {
        cin >> row2[i] >> col2[i] >> val2[i];
    }

   
    int maxNonZero = nonZero1 + nonZero2;
    int resRow[maxNonZero], resCol[maxNonZero], resVal[maxNonZero];

    int i = 0, j = 0, k = 0;

   
    while (i < nonZero1 && j < nonZero2) {
        if (row1[i] < row2[j] || (row1[i] == row2[j] && col1[i] < col2[j])) {
            // Take element from first matrix
            resRow[k] = row1[i];
            resCol[k] = col1[i];
            resVal[k] = val1[i];
            i++; k++;
        }
        else if (row2[j] < row1[i] || (row2[j] == row1[i] && col2[j] < col1[i])) {
            
            resRow[k] = row2[j];
            resCol[k] = col2[j];
            resVal[k] = val2[j];
            j++; k++;
        }
        else {
           
            int addedVal = val1[i] + val2[j];
            if (addedVal != 0) {
                resRow[k] = row1[i];
                resCol[k] = col1[i];
                resVal[k] = addedVal;
                k++;
            }
            i++; j++;
        }
    }

   
    while (i < nonZero1) {
        resRow[k] = row1[i];
        resCol[k] = col1[i];
        resVal[k] = val1[i];
        i++; k++;
    }

   
    while (j < nonZero2) {
        resRow[k] = row2[j];
        resCol[k] = col2[j];
        resVal[k] = val2[j];
        j++; k++;
    }

    cout << "\nResultant matrix after addition (row col value):\n";
    for (int idx = 0; idx < k; idx++) {
        cout << resRow[idx] << " " << resCol[idx] << " " << resVal[idx] << "\n";
    }

    return 0;
}