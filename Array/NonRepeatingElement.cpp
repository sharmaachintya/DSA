#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int nonRepeating(vector<int> arr)
{
    unordered_map<int, int> mp;
    for (int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
    for (int i=0;i<arr.size();i++)
    {
        if (mp[arr[i]] == 1)
            return arr[i];
    }
    return 0;
}

int main()
{
    vector<int> arr = {-1, 2, -1, 3, 2};   
    cout<<nonRepeating(arr); 
}