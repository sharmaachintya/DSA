#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int m = 3;
    reverse(arr.begin()+m+1, arr.end());
    for (auto it: arr)    
        cout<<it<<" ";
}