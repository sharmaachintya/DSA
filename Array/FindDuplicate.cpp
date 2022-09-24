#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int duplicate(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    for (int i=1;i<arr.size();i++)
    {
        if (arr[i] == arr[i-1])
            return arr[i];
    }
    return 0;
}

int main()
{
    vector<int> arr = {1,6,8,2,3,5,20,5};
    cout<<duplicate(arr);    
}