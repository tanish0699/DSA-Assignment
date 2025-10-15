#include <iostream>
#include <queue>
#include <climits>
using namespace std;

void sortQueue(queue<int> &q)
{
    int size = q.size();

    for (int i = 0; i < size; i++)
    {
        int min_index = -1;
        int min_value = INT_MAX;
        int n = q.size();

        for (int j = 0; j < n; j++)
        {
            int curr = q.front();
            q.pop();

            if (curr < min_value && j <= size - i - 1)
            {
                min_value = curr;
                min_index = j;
            }

            q.push(curr);
        }

        // Move elements back, placing min_value in correct position
        for (int j = 0; j < n; j++)
        {
            int curr = q.front();
            q.pop();
            if (j != min_index)
                q.push(curr);
        }

        q.push(min_value);
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
