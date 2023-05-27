#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int target)
{
    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i=0;i<arr.size();i++)
    {
        int ele = target - arr[i];
        if (mp.find(ele) != mp.end())
        {
            ans.push_back(i);
            ans.push_back(mp[ele]);
        }
        mp[arr[i]] = i;
    }
    for (auto i : ans)
        cout<<i<<" ";
}

int main()
{
    vector<int> arr = {3, 2, 4};
    int target = 6;
    solve(arr, target);
}