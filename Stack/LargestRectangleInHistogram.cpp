#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> nextSmall(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for (int i=n-1;i>=0;i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmall(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i=0;i<n;i++)
    {
        int curr =arr[i];
        while( s.top() == -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}


int largestRect(vector<int> heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmall(heights, n);

    vector<int> prev(n);
    prev = prevSmall(heights, n);

    int area = INT_MIN;
    for (int i=0;i<n;i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l*b;
        area = max(area, newArea);
    }
    return area;
}

int main()
{
    vector<int> heights = {2,4};
    int ans = largestRect(heights);
    cout<<ans;
}