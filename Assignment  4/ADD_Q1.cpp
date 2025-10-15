#include <iostream>
#include <queue>
using namespace std;

void generateBinaryNumbers(int n)
{
    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++)
    {
        string s = q.front();
        cout << s << " ";
        q.pop();

        q.push(s + "0");
        q.push(s + "1");
    }
}

int main()
{
    int n = 5; // Example: generate binary numbers from 1 to 5
    generateBinaryNumbers(n);
    return 0;
}
