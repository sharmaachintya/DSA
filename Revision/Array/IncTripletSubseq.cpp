#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr)
{
    int n = arr.size();
    int left = INT_MAX, mid = INT_MAX;
    
    for (int i=0;i<n;i++)
    {
        if (arr[i] > mid)
            return true;
        else if (arr[i] < left)
            left = arr[i];
        else if (arr[i] > left && arr[i] < mid)
            mid = arr[i];
    }
    return 0;
}

int main()
{
    vector<int> arr = {1, 2, 0, 4, 5};
    cout<<solve(arr);    
}