#include<iostream>
using namespace std;
int firstOccur(int arr[], int size, int key)
{
    int start =0, end=size-1, ans=-1;
    int mid = (start+end)/2;
    while(start<=end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid-1;
        }
        else if (arr[mid] > key)
        {
            end = mid-1;
        }
        else if (arr[mid] < key)
        {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int lastOccur(int arr[], int size, int key)
{
    int start =0, end=size-1, ans=-1;
    int mid = (start+end)/2;
    while(start<=end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid+1;
        }
        else if (key < arr[mid])
        {
            end = mid-1;
        }
        else if (key > arr[mid])
        {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int main()
{
    int even[5] = {1,3,3,3,3};
    cout<<"The first Occurence of 3 is at Index: "<<firstOccur(even , 5, 3)<<endl;
    cout<<"The Last Occurence of 3 is at Index: "<<lastOccur(even , 5, 3);
}