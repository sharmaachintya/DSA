#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;
    int sum = 0;
    int maxi = 0;
    for (int i=0;i<n;i++)
    {
        sum = sum + arr[i];
        if (sum == 0)
            maxi = i + 1;
        else
        {
            if (mp.find(sum) != mp.end())             // Sum already exists in the map
                maxi = max(maxi, i - mp[sum]);
            else                                      // Sum doesn't exist in map
                mp[sum] = i;
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {1, 3, -1, 4, -4};
    int n = arr.size(); 
    cout<<solve(arr, n);   
}