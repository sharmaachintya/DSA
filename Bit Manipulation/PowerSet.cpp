#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void powerSet(int arr[], int n)
{
    for (int i=0;i<(1<<n);i++)                // 1 << n -> 2^n
    {
        for (int j=0;j<n;j++)
        {
            if (i & (1 << j))
            {
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3};     
    powerSet(arr, 3);
}