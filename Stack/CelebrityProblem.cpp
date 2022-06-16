#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool knows(vector<vector<int>> &arr, int a, int b, int n)
{
    if (arr[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int celebrity(vector<vector<int>> &arr, int n)
{
    stack<int> s;
    for (int i=0;i<n;i++)        // Push all elements in stack
    {
        s.push(i);
    }
    while (s.size() != 1)       // Get 2 elements and compare them
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(arr, a, b, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int cand = s.top();
    bool rowCheck = false;      // Single element in stack can be the celebrity
    int zeroCount = 0;          // Verifying
    for (int i=0;i<n;i++)
    {
        if(arr[cand][i] == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount == n)
    {
        rowCheck = true;
    }
    bool colCheck = false;
    int oneCount = 0;
    for (int i=0;i<n;i++)
    {
        if(arr[i][cand] == 1)
        {
            oneCount++;
        }
    }
    if (oneCount == n-1)
    {
        colCheck = true;
    }
    if (rowCheck == true && colCheck == true)
    {
        return cand;
    }
    return -1;
}

int main()
{
    vector<vector<int>> arr = {{ 0, 1, 0},
                                {0, 0, 0},
                                {0, 1, 0}};
    
    int n = arr.size();

    int ans = celebrity(arr, n);
    cout<<ans;
}