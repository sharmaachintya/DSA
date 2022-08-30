#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();
    for (int i=0;i<n-1;i++)
    {
        int minIndex = i;
        for (int j=i+1;j<n;j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    for (auto i : arr)
    {
        cout<<i<<" ";
    }
}