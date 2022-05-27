#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> arr = {1,2,3,4};
    vector <int> temp(arr.size());
    int k = 2;                          // Positions to be shifted
    int n = arr.size();
    for (int i=0;i<n;i++)
    {
        temp[(i+k) % n] = arr[i];        // Cyclic way of shifting elements
    }
    for (int i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<" ";
    }
}