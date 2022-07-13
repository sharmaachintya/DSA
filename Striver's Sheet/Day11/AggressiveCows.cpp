#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> stalls, int k, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i=0;i<stalls.size();i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}


int main()
{
    vector<int> stalls = {4,2,1,3,6};
    int k = 2;

    sort(stalls.begin(), stalls.end());
    int low = 0;
    int maxi = -1;
    for (int i=0;i<stalls.size();i++)    
    {
        maxi = max(maxi, stalls[i]);
    }
    int high = maxi;
    int ans = -1;
    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        mid = low + (high - low) / 2;
    }
    cout<<ans;
}