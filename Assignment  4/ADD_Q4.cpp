#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int countStudentsUnableToEat(queue<int> students, stack<int> sandwiches)
{
    int rotations = 0;

    while (!students.empty() && rotations < students.size())
    {
        if (students.front() == sandwiches.top())
        {
            students.pop();
            sandwiches.pop();
            rotations = 0;
        }
        else
        {
            students.push(students.front());
            students.pop();
            rotations++;
        }
    }

    return students.size();
}

int main()
{
    queue<int> students;
    stack<int> sandwiches;

    students.push(1);
    students.push(1);
    students.push(0);
    students.push(0);

    sandwiches.push(1);
    sandwiches.push(0);
    sandwiches.push(1);
    sandwiches.push(0);

    cout << countStudentsUnableToEat(students, sandwiches) << endl;

    return 0;
}
