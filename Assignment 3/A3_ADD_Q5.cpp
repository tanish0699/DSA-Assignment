// <!-- You have an array A of integers of size N, an array B (initially empty) and a stack S (initially 
// empty). You are allowed to do the following operations:
// a) Take the first element of array A and push it into S and remove it from A.
// b) Take the top element from stack S, append it to the end of array B and remove it from S.
// You have to tell if it possible to move all the elements of array A to array B using the above
// operations such that finally the array B is sorted in ascending order. -->

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool canTransform(vector<int> &A)
{
    int n = A.size();
    vector<int> target = A;
    sort(target.begin(), target.end());

    stack<int> S;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        S.push(A[i]);

        while (!S.empty() && S.top() == target[j])
        {
            S.pop();
            j++;
        }
    }

    return (S.empty() && j == n);
}

int main()
{
    vector<int> A = {2, 3, 1};

    if (canTransform(A))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}