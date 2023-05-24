#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int idx = -1;
    for (int i=n-1;i>0;i--)    
    {
        if (arr[i] > arr[i-1])
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
        reverse(arr.begin(), arr.end());
    else
    {
        int prev = idx;
        for (int i=idx+1;i<n;i++)
        {
            if (arr[i] > arr[idx - 1] && arr[i] <= arr[prev])
                prev = i;
        }
        swap(arr[idx - 1], arr[prev]);
        reverse(arr.begin()+idx, arr.end());
    }

    for (int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}