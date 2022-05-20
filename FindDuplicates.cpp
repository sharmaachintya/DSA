#include<iostream>
using namespace std;
int main()
{
    int arr[10],n;
    int ans = 0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for (int i=0;i<n;i++)
    {
        ans = ans ^ arr[i]; // XOR ing All element arrays
    }
    for(int i=1;i<n;i++)
    {
        ans = ans ^ i;     // XOR ing Elements till n-1
    }
    cout<<ans;
}