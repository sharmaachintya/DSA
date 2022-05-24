#include<iostream>
#include<vector>
using namespace std;
bool possibleSol(vector <int> &arr,int k,int mid)
{
    int PainterCount = 1;
    int SumTime = 0;
    for (int i=0;i<arr.size();i++)
    {
        if (SumTime + arr[i] <= mid)
        {
            SumTime = SumTime + arr[i];
        }
        else
        {
            PainterCount++;
            if(PainterCount > k || arr[i] > mid)
            {
                return false;
            }
            SumTime = 0;
            SumTime = SumTime + arr[i];
        }
    }
    return true;
}
int main()
{
    vector <int> arr = {5, 5, 5, 5}; // Number of unit Boards
    int k = 2; // Number Of Painters
    int start = 0; 
    int end;
    int ans = -1;
    int sum = 0;
    for (int i=0;i<arr.size();i++)
    {
        sum = sum + arr[i];
    }
    end = sum;
    int mid = (start + end)/2;
    while (start<=end)
    {
        if(possibleSol(arr, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    cout<<ans;
}