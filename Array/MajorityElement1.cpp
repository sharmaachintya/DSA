#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> arr)
{
    unordered_map<int, int> mp;
    int ans = -1;
    for (int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
    for (auto i: mp)
    {
        if (i.second > arr.size() / 2)
            ans = i.first;
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 2, 3};
    cout<<majorityElement(arr);    
}