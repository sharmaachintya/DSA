#include<iostream>
#include<queue>
#include<stack>
using namespace std;


queue<int> rev(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty())
    {
        int element = s.top();
        q.push(element);
        s.pop();
    }
    return q;
}

int main()
{
    queue<int> arr;

    arr.push(4);
    arr.push(2);
    arr.push(3);
    arr.push(1);

    queue<int> ans = rev(arr);
    
    while (!ans.empty())
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }
}