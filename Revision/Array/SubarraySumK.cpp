#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int sum = 0, count = 0;

    for (int i=0;i<n;i++)
    {
        sum += arr[i];
        if (sum == k)
            count++;
        if (mp.find(sum - k) != mp.end())
        {
            count += mp[sum - k];
        }
        if (mp.find(sum) != mp.end())
            mp[sum]++;
        else
            mp[sum] = 1;
    }
    return count;
}

int main()
{
    vector<int> nums = {1,2,3};
    int k = 3;  
    cout<<solve(nums, k);  
}