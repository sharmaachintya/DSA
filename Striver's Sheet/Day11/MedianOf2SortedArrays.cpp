#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr1 = {1,3,4,7,10,12};
    vector<int> arr2 = {2,3,6,15}; 
    double med; 

    for (int i=0;i<arr2.size();i++)  
    {
        arr1.push_back(arr2[i]);
    }
    sort(arr1.begin(), arr1.end());

    if (arr1.size() / 2 == 1)                  // Array has odd size
    {
        int temp = arr1.size() / 2;
        med = arr1[temp];
        cout<<med;
    }
    else                                      // Array has even size
    {
        int temp = arr1.size() / 2;
        med = (arr1[temp] + arr1[temp - 1]) / 2;
        cout<<med;
    }
}