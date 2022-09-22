#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int stockBuyAndSell(vector<int> arr)
{
    int minSoFar = arr[0];
    int maxSoFar = 0;
    for (int i=0;i<arr.size();i++)
    {
        minSoFar = min(arr[i], minSoFar);
        int temp = arr[i] - minSoFar;
        maxSoFar = max(maxSoFar, temp);
    }
    return maxSoFar;
}
int main()
{
    vector<int> arr = {7,1,5,3,6,4};    
    cout<<stockBuyAndSell(arr);
}