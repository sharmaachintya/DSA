#include<iostream>
using namespace std;
int uniqueElement(int arr[], int n)
{
    int ans = 0;
    for (int i=0;i<n;i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()
{
    int n, arr[10],res;
    cout<<"Enter the size of Array(ODD): ";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cout<<"Enter the Element "<<i<<" of Array: ";
        cin>>arr[i];
    }
    res = uniqueElement(arr,n);
    cout<<res;
}