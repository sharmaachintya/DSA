#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> arr)
{
    int sum = 0;
    int maxi = 0;
    unordered_map<int, int> mp;
    for (int i=0;i<arr.size();i++)
    {
        sum = sum + arr[i];
        if (sum == 0)
            maxi = i + 1;
        else
        {
            if (mp.find(sum) != mp.end())
                maxi = max(maxi, i - mp[sum]);
            else
                mp[sum] = i;
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {1, 3, -1, 4, -4};    
    cout<<longestSubarray(arr);
}