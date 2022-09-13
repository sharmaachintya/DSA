#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k = 2;
    vector<int> arr = {1,2,3,4};
    sort(arr.begin(), arr.end());
    cout<<arr[k-1]<<endl;
    int n = arr.size() - 1;
    cout<<arr[n - k + 1];    
}