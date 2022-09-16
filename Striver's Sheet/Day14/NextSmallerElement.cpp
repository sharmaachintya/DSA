#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i=n-1;i>=0;i--)
    {
        int curr = arr[i];
        while (st.top() >= curr)
            st.pop();
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 4, 3};
    int n = 4;
    vector<int> ans = nextSmaller(arr, n);
    for (auto i : ans)
        cout<<i<<" ";
}