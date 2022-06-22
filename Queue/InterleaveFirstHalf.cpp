#include<iostream>
#include<bits/stdc++.h>
using namespace std;

queue<int> interleaveFirst(queue<int> ip)
{
    queue<int> temp;
    queue<int> ans;

    int n = ip.size() / 2;

    while (n--)
    {
        temp.push(ip.front());
        ip.pop();
    }

    while (!temp.empty())
    {
        ans.push(temp.front());
        temp.pop();
        ans.push(ip.front());
        ip.pop();
    }
    return ans;
}

int main()
{
    queue<int> ip;
    queue<int> ans;

    ip.push(1);
    ip.push(2);
    ip.push(3);
    ip.push(4);
    ip.push(5);
    ip.push(6);
    ip.push(7);
    ip.push(8);
    ip.push(9);
    ip.push(10);

    ans = interleaveFirst(ip);

    while (!ans.empty())
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }
}