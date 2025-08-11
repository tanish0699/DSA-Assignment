#include <iostream>
using namespace std;

void sumRow(int arr[4][3], int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << "sum of row " << i + 1 << "= " << sum;
        cout << endl;
    }
}

void sumColumn(int arr[4][3], int n, int m)
{

    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum = sum + arr[j][i];
        }
        cout << "sum of column " << i + 1 << "= " << sum;
        cout << endl;
    }
}

int main()
{
    int arr[4][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};

    sumRow(arr, 4, 3);
    sumColumn(arr, 4, 3);
}