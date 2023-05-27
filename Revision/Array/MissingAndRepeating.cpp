#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> arr)
{
    pair<int, int> ans;
    int n = arr.size();
    vector<int> mp(n + 1);

    for (int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for (int i=1;i<n;i++)
    {
        if (mp[i] > 1)
            ans.first = i;
        else if (mp[i] == 0)
            ans.second = i;
    }
    cout<<ans.first<<" "<<ans.second;
}

int main()
{
    vector<int> arr = {6, 4, 3, 5, 5, 1};
    solve(arr);    
}