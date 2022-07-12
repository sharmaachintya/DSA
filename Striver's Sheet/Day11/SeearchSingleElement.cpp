#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    int low = 0;
    int high = nums.size() - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == nums[mid^1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout<<nums[low];
}