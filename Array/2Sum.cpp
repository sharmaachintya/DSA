#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
vector<int> twoSum(vector<int> arr, int target) 
{
    unordered_map<int, int> mp;
    vector<int> res;

    for (int i=0;i<arr.size();i++)
    {
        int ele = target - arr[i];
        if (mp.find(ele) != mp.end())
        {
            res.push_back(i);
            res.push_back(mp[ele]);
        }
        mp[arr[i]] = i;
    }
    return res;
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(arr, target);
    for (auto i :ans)
        cout<<i<<" ";
}
