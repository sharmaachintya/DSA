#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    for (int i=0;i<n;i++)
    {
        arr1[i+m] = arr2[i];
    }
    sort(arr1.begin(), arr1.end());
    return arr1;
}


int main()
{
    vector<int> arr1 = {1};
    int m = 1;
    vector<int> arr2 = {};
    int n = 0;
    vector<int> ans = solve(arr1, m, arr2, n);    
    for(auto it: ans)
        cout<<it<<" ";
}