#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> nextSmallerElement(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i=n-1;i>=0;i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
            st.pop();
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i=0;i<n;i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
            st.pop();
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRect(vector<int> heights, int n)
{
    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i=0;i<n;i++)
    {
        int l = heights[i];
        if (next[i] == -1)
            next[i] = n;
        
        int b = next[i] - prev[i] - 1;
        int newArea = l*b;
        area = max(area, newArea);
    }
    return area;
}

int main()
{
    vector<int> heights = {2,1,5,6,2,3};    
    int n = 6;
    cout<<largestRect(heights, n);
}