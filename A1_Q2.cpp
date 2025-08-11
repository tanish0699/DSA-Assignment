#include <iostream>
using namespace std;

void duplicate(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {

                for (int k = j; k < n; k++)
                {
                    arr[k] = arr[k + 1];
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[6] = {1, 2, 2, 3, 4, 5};
    duplicate(arr, 6);
}