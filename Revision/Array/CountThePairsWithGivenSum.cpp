#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int k)
{
    unordered_map<int, int> mp;
    int ans = 0;
    int n = arr.size();
    for (int i=0;i<n;i++)
    {
        int b = k - arr[i];
        if (mp[b])                        // Adding the Frequency of that particular 'b' element in answer
            ans += mp[b];
        mp[arr[i]]++;                     // Mapping the arr[i] with it's frequency
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 5, 7, 1};
    int k = 6;
    cout<<solve(arr, k);    
}