#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {10, 1, 7, 4, 8, 2, 11};
    int n = arr.size();

    for (int i=1;i<n;i++)    
    {
        int temp = arr[i];
        int j = i - 1;
        for (;j>=0;j--)
        {
            if (arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
    }
    for (auto i : arr)
    {
        cout<<i<<" ";
    }
}