#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int> arr)
{
    if (arr.size() < 3)
        return false;
    
    int mid = INT_MAX, left = INT_MAX;
    for (int i=0;i<arr.size();i++)
    {
        if (arr[i] > mid)
            return true;
        else if (arr[i] < mid && arr[i] > left)
            mid = arr[i];
        else if (arr[i] < left)
            left = arr[i];
    }
    return false;
}

int main()
{
    vector<int> arr = {2,1,5,0,4,6};
    cout<<increasingTriplet(arr);
}