#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1,2,1,3,5,6,4};
    // USING BINARY SEARCH
    int start = 0;
    int end = arr.size() - 1;
    int mid = (start + end) / 2;
    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
            end = mid;
        mid = start + (end - start) / 2;
    }
    cout<<start;
}