#include<iostream>
#include<vector>
using namespace std;
int merge(int arr[], int temp[], int high, int low, int mid)
{
    int count = 0;
    int i = low;
    int j = mid;
    int k = low;
    while ((i <= mid-1) && (j <= high))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count = count + (mid - i);
        }
    }
    while (i<=mid-1)
    {
        temp[k++] = arr[i++];
    }
    while (j<=high)
    {
        temp[k++]=arr[j++];
    }
    for (i=low;i<=high;i++)
    {
        arr[i] = temp[i];
    }
    return count;
}
int mergeSort(int arr[], int temp[], int low, int high)
{
    int mid , count = 0;
    if (high > low)
    {
        mid = (high + low)/2;
        count += mergeSort(arr, temp, low, high);
        count += mergeSort(arr, temp, mid + 1, high);

        count += merge(arr, temp, low, high, mid + 1);
    }
    return count;
}
int main()
{
    int arr[] = {5,3,2,4,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    int size = sizeof(arr);
    int ans = mergeSort(arr, temp, 0, size - 1);
    cout<<"Number of Inversions are: "<<ans;
}