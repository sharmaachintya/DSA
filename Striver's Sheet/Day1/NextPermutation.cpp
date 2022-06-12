#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int i,j;
    vector <int> arr = {1,3,5,4,2}; 
    for (i=arr.size()-2;i>=0;i--)  // Finding the Breakpoint
    {
        if (arr[i] < arr[i+1])
        {
            break;
        }
    }
    if (i < 0)                    // No Breakpoint Found
    {
        reverse(arr.begin(),arr.end());
    }
    else                          // Breakpoint Found
    {
        for (j=arr.size()-1;j>i;j--)
        {
            if (arr[j] > arr[i])
            {
                break;
            }
        }
        swap(arr[i],arr[j]);
        reverse(arr.begin()+i+1,arr.end());
    }
    for (int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}