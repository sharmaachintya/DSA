#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstRepeating(vector<int> arr)
{
    set<int> st;
    int min = -1;
    for (int i=arr.size()-1;i>=0;i--)
    {
        if (st.find(arr[i]) != st.end())
        {
            min = i;
        }
        else
        {
            st.insert(arr[i]);
        }
    }
    if (min != -1)
        return min + 1;
    else
        return min;
}

int main()
{
    vector<int> arr = {1, 5, 3, 4, 3, 5, 6};
    cout<<firstRepeating(arr);    
}