#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> ans;
    for (int i=n-1;i>=0;i--)
    {
        if (st.empty())
            ans.push_back(-1);
        else
        {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();
            
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {9, 3, 6, 5};
    int n = 4;
    vector<int> ans = nextGreater(arr, n);
    for (auto i: ans)
        cout<<i<<" ";
}