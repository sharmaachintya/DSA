#include<iostream>
#include<stack>
#include<queue>
using namespace std;

deque<int> revK(deque<int> &arr, int k)
{
    stack<int> s;
    int count = 1;
    while (count <= k)
    {
        int element = arr.front();
        arr.pop_front();
        s.push(element);
        count++;
    }

    while(!s.empty())
    {
        int element = s.top();
        arr.push_back(element);
        s.pop();
    }

    int t = arr.size() - k;
    while (t--)
    {
        int val = arr.front();
        arr.pop_front();
        arr.push_back(val);
    }
    return arr;
}


int main()
{
    deque<int> arr;
    
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    int k = 3;

    deque<int> ans = revK(arr, k);

    while(!ans.empty())
    {
        cout<<ans.front()<<" ";
        ans.pop_front();
    }
}