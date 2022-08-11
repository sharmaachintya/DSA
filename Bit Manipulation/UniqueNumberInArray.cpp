#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int uniqueNo(int arr[], int n)
{
    int xorS;
    for (int i=0;i<n;i++)
    {
        xorS = xorS ^ arr[i];
    }
    return xorS;
}

int main()
{
    int arr[] = {2,4,6,3,4,6,2};
    cout<<uniqueNo(arr, 7);
}