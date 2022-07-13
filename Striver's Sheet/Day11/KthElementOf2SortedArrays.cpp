#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr1 = {1,3,4,7,10,12};
    vector<int> arr2 = {2,3,6,15};
    int k = 5;

    for (int i=0;i<arr2.size();i++)    
    {
        arr1.push_back(arr2[i]);
    }
    sort(arr1.begin(), arr1.end());

    cout<<arr1[k-1];
}