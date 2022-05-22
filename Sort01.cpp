#include<iostream>
using namespace std;
void sort1(int arr[], int size)
{
    int left=0, right=size-1;
    while(left<right)
    {
        while(arr[left] == 0 && left < right)
        {
            left++;
        }
        while(arr[right] == 1 && left < right)
        {
            right--;
        }
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}
int main()
{
    int arr[10]={0,1,0,1,1,1,1,0,0,1};
    sort1(arr, 10);
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
}