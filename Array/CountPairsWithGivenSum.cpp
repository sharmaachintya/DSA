#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int> arr, int sum)
{
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i=0;i<arr.size();i++)
    {
        int b = sum - arr[i];
        if (mp[b])
        {
            ans = ans + mp[b];
        }
        mp[arr[i]]++;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,1,1,1};
    cout<<countPairs(arr, 2);    
}