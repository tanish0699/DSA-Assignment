#include <iostream>
using namespace std;

void duplicateZero(int arr[], int n)
{
    int brr[n];
    int i = 0;
    int j = 0;
    while (i < n && j < n)
    {
        if (arr[i] != 0)
        {
            brr[j] = arr[i];
            i++;
            j++;
        }
        else
        {
            brr[j] = arr[i];
            brr[j + 1] = 0;

            i++;
            j = j + 2;
        }
    }

    for (int j = 0; j < n; j++)
    {
        cout << brr[j];
    }
}
int main()
{
    int n;
    cout << "enter the size of arr:";
    cin >> n;
    int arr[50];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    duplicateZero(arr, n);

    return 0;
}