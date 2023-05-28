#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    unordered_map<int , int> mp;
    int n = nums.size();
    int ans = 0;
    for (int i=0;i<nums.size();i++)
    {
        mp[nums[i]]++;
    }
    for (auto it: mp)
    {
        if (it.second > n/2)
            ans = it.first;
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    cout<<solve(nums);    
}