#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> arr  = {0,1,1,0,1,2,1,2,0,0,0,1};
    int low=0, mid=0, high=arr.size()-1;
    for (int i=0;i<arr.size();i++)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}