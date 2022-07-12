#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> arr, int target)
{
    int low = 0;    
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[low] < arr[mid])
        {
            if (arr[low] <= target && arr[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= target && arr[high] >= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}   

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;

    cout<<solve(arr, target);

}