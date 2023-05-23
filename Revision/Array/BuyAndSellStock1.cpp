#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size();
    int minSoFar = arr[0], maxAns = 0;
    for (int i=0;i<n;i++)
    {
        minSoFar = min(minSoFar, arr[i]);
        int temp = arr[i] - minSoFar;
        maxAns = max(maxAns, temp);
    }
    return maxAns;
}

int main()
{
    vector<int> arr = {7,1,5,3,6,4};
    cout<<solve(arr);    
}