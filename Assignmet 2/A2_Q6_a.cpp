//program to implement the operations on a Sparse Matrix, assuming the matrix is represented using a triplet.
//Transpose of a matrix.

#include <iostream>
using namespace std;

int main() {
    int rows, cols, nonZero;
    cout << "Enter number of rows, columns and non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    int row[nonZero], col[nonZero], val[nonZero];
    int tRow[nonZero], tCol[nonZero], tVal[nonZero];

    cout << "Enter the triplets (row col value) (0-indexed):\n";
    for (int i = 0; i < nonZero; i++) {
        cin >> row[i] >> col[i] >> val[i];
    }

    
    for (int i = 0; i < nonZero; i++) {
        tRow[i] = col[i];
        tCol[i] = row[i];
        tVal[i] = val[i];
    }

    
    for (int i = 0; i < nonZero - 1; i++) {
        for (int j = 0; j < nonZero - i - 1; j++) {
            if (tRow[j] > tRow[j + 1] || (tRow[j] == tRow[j + 1] && tCol[j] > tCol[j + 1])) {
               
                int temp = tRow[j];
                tRow[j] = tRow[j + 1];
                tRow[j + 1] = temp;
               
                temp = tCol[j];
                tCol[j] = tCol[j + 1];
                tCol[j + 1] = temp;
              
                temp = tVal[j];
                tVal[j] = tVal[j + 1];
                tVal[j + 1] = temp;
            }
        }
    }

    cout << "\nTranspose of the matrix (row col value):\n";
    for (int i = 0; i < nonZero; i++) {
        cout << tRow[i] << " " << tCol[i] << " " << tVal[i] << "\n";
    }

    return 0;
}