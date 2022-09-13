#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {0, 2, 1, 2, 0};    
    int low = 0, mid = 0, high = arr.size() - 1;
    for (int i=0;i<arr.size();i++)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (auto i : arr)
    {
        cout<<i<<" ";
    }
}