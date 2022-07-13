#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &pages, int mid, int n, int m)
{
    int studentCnt = 1;
    int pageSum = 0;

    for (int i=0;i<n;i++)
    {
        if (pageSum + pages[i] <= mid)
        {
            pageSum = pageSum + pages[i];
        }   
        else
        {
            studentCnt++;
            if (studentCnt > m || pages[i] > mid)
            {
                return false;
            }
            pageSum = 0;
            pageSum = pageSum + pages[i];
        }
    }
    return true;
}


int main()
{
    vector<int> pages = {10,20,30,40};
    int m = 2;
    int n = pages.size();    

    int low = 0;
    int high = 0;
    int ans;

    for (int i=0;i<n;i++)
    {
        high = high + pages[i];
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(pages, mid, n, m))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    cout<<ans;
}