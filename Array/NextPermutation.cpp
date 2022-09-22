#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextPerm(vector<int> arr)
{
    int idx = -1;
    int n = arr.size();
    for (int i=n-1;i>0;i--)
    {
        if (arr[i] > arr[i-1])
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    else
    {
        int prev = idx;
        for (int i=idx+1;i<n;i++)
        {
            if (arr[i] > arr[idx-1] && arr[i] <= arr[prev])
                prev = i;
        }
        swap(arr[idx-1], arr[prev]);
        reverse(arr.begin()+idx, arr.end());
    }
    return arr;
}

int main()
{
    vector<int> arr = {3,1,2};
    vector<int> ans = nextPerm(arr); 
    for (auto i : ans)   
        cout<<i<<" ";
}