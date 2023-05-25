#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> arr)
{
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;
    for (int i=0;i<n;i++)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (auto it : arr)
        cout<<it<<" ";
}

int main()
{
    vector<int> arr = {0, 1, 2, 1, 2, 1, 2};
    solve(arr);    
}