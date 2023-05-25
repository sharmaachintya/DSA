#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Maximum Subarray Sum

int solve(vector<int> &arr)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (int i=0;i<arr.size();i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

int main()
{
    vector<int> arr = {1, 2, 7, -4, 3, 2, -10, 9, 1};
    cout<<solve(arr);
}