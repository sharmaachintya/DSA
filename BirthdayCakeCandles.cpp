#include<iostream>
using namespace std;
int main()
{
    int n,count = 0;
    int highest;
    int arr[10];
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for (int i=0; i<n; i++)
    {
        highest=arr[i];
        if (arr[i]>highest)
        {
            highest=arr[i];
            count++;
        }
    }
    cout<<count;
    return 0;
}