#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int subarraySum (vector<int> arr, int k)
{
    unordered_map<int, int> mp;
    int sum = 0, count = 0;
    for (int i=0;i<arr.size();i++)
    {
        sum = sum + arr[i];
        if (sum == k)
            count++;
        if (mp.find(sum - k) != mp.end())
        {
            count = count + mp[sum - k];
        }
        else if (mp.find(sum) != mp.end())
            mp[sum]++;
        else
            mp[sum] = 1;
    }
    return count;
}

int main()
{
    vector<int> arr = {1, 1, 1};
    int k = 2;    
    cout<<subarraySum(arr, k);
}