#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool canBeSorted(queue<int> input)
{
    stack<int> s;
    int expected = 1;

    while (!input.empty())
    {
        if (input.front() == expected)
        {
            input.pop();
            expected++;
        }
        else
        {
            if (!s.empty() && s.top() == expected)
            {
                s.pop();
                expected++;
            }
            else
            {
                s.push(input.front());
                input.pop();
            }
        }
    }

    while (!s.empty())
    {
        if (s.top() == expected)
        {
            s.pop();
            expected++;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (canBeSorted(q))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
