#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {10, 1, 7, 6, 14, 9};
    int n = arr.size();

    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i;j++)
        {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
    for (auto i : arr)    
    {
        cout<<i<<" ";
    }
}