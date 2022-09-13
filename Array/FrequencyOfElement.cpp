#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1,1,1,1,1};
    int x = 1;
    int count = 0;
    for (int i=0;i<arr.size();i++)
    {
        if (arr[i] == x)
            count++;
    }
    cout<<count;
}