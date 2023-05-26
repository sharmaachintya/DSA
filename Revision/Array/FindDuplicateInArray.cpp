#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    for (int i=1;i<=arr.size();i++)
    {
        if (arr[i] == arr[i-1])
            return arr[i];
    }
    return 1;
}
int main()
{
    vector<int> arr = {1, 2, 2, 3, 4, 5, 6};
    cout<<solve(arr);    
}