#include<iostream>
using namespace std;
int main()
{
    int arr[5], minDig=1, maxDig=0;
    int sumMin=0, sumMax=0;
    for (int i=0; i<5; i++)
    {
        cin>>arr[i];
    }
    for (int i=0; i<5; i++)
    {
        if(arr[i] > maxDig)
        {
            maxDig=arr[i];
        }
        if(arr[i] < minDig)
        {
            minDig=arr[i];
        }
    }
    for (int i=0; i<5; i++)
    {
        if (arr[i]!=minDig)
        {
            sumMin+=arr[i];
        }
        if (arr[i]!=maxDig)
        {
            sumMax+=arr[i];
        }
    }
    cout<<sumMin<<endl<<sumMax;
}