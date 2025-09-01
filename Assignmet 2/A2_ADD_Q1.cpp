#include <iostream>
using namespace std;

int countPair(int arr[], int n, int key)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (abs(arr[i] - arr[j]) == key)
            {
                count++;
                cout << arr[i] << "," << arr[j] << endl;
            }
        }
    }
    return count;
}
int main()
{

    int arr[50];
    int n;
    cout << "enter the size of arr:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "enter the diff uwant : ";
    cin >> key;

    int result = countPair(arr, n, key);
    cout << "total pairs = " << result << endl;

    return 0;
}