#include<iostream>
#include<vector>
using  namespace std;
bool isPossible(vector<int> &arr, int n, int m, int mid)
{
    int studCount = 1;
    int pageSum = 0;
    for (int i=0;i<n;i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum = pageSum + arr[i];
        }
        else
        {
            studCount++;
            if (studCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}
int main()
{
    vector <int> arr = {10,20,30,40};
    int n = 4; // Number of books
    int m = 2; // Nmber of students
    int start = 0;
    int sum = 0;
    for (int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    int end = sum;
    int ans = -1;
    int mid = (start+end)/2;
    while (start<=end)
    {
        if(isPossible(arr, n, m ,mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    cout<<ans;
}