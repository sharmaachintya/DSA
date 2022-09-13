#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {3, 2, 1, 56, 10000, 167};
    sort (arr.begin(), arr.end());
    cout<<arr[0]<<" "<<arr[arr.size() - 1]; 
}