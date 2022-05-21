#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 5, ele;
    vector <int> arr;
    vector<vector<int>> ans;
    for (int i=0;i<arr.size();i++)
    {
        cout<<"Enter the Element "<<i<<" in the Array: ";
        cin>>ele;
        arr.push_back(ele);
    }
    for (int i=0;i<arr.size();i++)
    {
        for (int j=i+1;j<arr.size();j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                vector <int> temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(),ans.end());
}