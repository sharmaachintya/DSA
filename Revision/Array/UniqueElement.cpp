#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int size)
{
    unordered_map<int, int> mp;
    for (int i=0;i<size;i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            mp[arr[i]]++;
        }
        else
            mp[arr[i]] = 1;
    }
    for (auto it: mp)
    {
        if (it.second == 1)
            return it.first;
    }
    return 1;
}


int main()
{
    vector<int> arr = {1, 3, 1, 3, 6, 6, 7, 10, 7};
    int n = arr.size();
    cout<<solve(arr, n);    
}