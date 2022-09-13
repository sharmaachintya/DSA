#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, -1, 3, 2, -7, -5, 11, 6};
    vector<int> ans;
    int n = arr.size();
    for (int i=0;i<n;i++)
    {
        if (arr[i] > 0)
            ans.push_back(arr[i]);
    }
    for (int i=0;i<n;i++)
    {
        if (arr[i] < 0)
            ans.push_back(arr[i]);
    }    
    for(auto i : ans)
        cout<<i<<" ";
}