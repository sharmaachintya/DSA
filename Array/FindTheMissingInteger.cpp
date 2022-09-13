#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {6,1,2,8,3,4,7,10,5};
    int n = arr.size() + 1;
    vector<int> freq(n);
    for (int i=0;i<arr.size();i++)
    {
        int ele = arr[i];
        freq[ele]++;
    }    
    for (int i=1;i<freq.size();i++)
    {
        if(freq[i] == 0)
            cout<<i;
    } 
}