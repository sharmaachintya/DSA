#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {85, 25, 1, 32, 54, 6};
    vector<int> arr2 = {85, 2};
    vector<int> ans;
    for (int i=0;i<arr.size();i++)
    {
        ans.push_back(arr[i]);
    }
    for (int i=0;i<arr2.size();i++)
    {
        ans.push_back(arr2[i]);
    }
    sort(ans.begin(), ans.end());
    int count = 0;
    for (int i=1;i<ans.size();i++)
    {
        if (ans[i] == ans[i-1])
            continue;
        else
            count++;
    }
    cout<<count + 1;
}