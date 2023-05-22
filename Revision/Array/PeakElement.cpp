#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size();
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;
    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
            start = mid + 1;
        else
            end = mid;
        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};    
    cout<<solve(arr);
}