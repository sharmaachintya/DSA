#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossible(vector <int> &stalls, int c, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];
    for (int i=0;i<stalls.size();i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == c)
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
    vector <int> stalls = {4, 2, 1, 3, 6};  // Distance between stalls
    sort(stalls.begin(),stalls.end());
    int c = 2;                 // Number of Aggressive Cows
    int start = 0;
    int maxi = -1;
    for (int i=0;i<stalls.size();i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int end = maxi;
    int ans = -1;
    int mid = (start+end)/2;
    while (start<=end)
    {
        if (isPossible(stalls, c, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    cout<<ans;
}