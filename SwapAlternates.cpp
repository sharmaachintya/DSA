#include<iostream>
using namespace std;
int main()
{
    int n,arr[10];
    cout<<"Enter the size of array: ";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cout<<"Enter the Element "<<i<<" in array: ";
        cin>>arr[i];
    }
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<n;i+=2)
    {
        if(i+1 < n)
        {
            swap(arr[i], arr[i+1]);
        }
    }
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}