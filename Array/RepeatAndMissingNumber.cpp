#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int, int> repeatAndMissing(vector<int> arr)
{
    pair<int, int> ans;
    int n = arr.size();
    vector<int> freq(n + 1);
    for (int i=0;i<n;i++)
    {
        int element = arr[i];
        freq[element] = freq[element] + 1;
    }
    for (int i=1;i<freq.size();i++)
    {
        if (freq[i] == 0)
            ans.first = i;
        else if (freq[i] > 1)
            ans.second = i;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 5, 4, 4};
    pair<int, int> ans = repeatAndMissing(arr);    
    cout<<ans.first<<" "<<ans.second;
}