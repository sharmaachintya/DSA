#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum =12;
    vector <int> arr;
    vector<vector<int>> ans;
    for (int i=0;i<arr.size();i++)
    {
        cout<<"Enter "<<i<<" Element";
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    for (int i=0;i<arr.size();i++)
    {
        for (int j=i+1;j<arr.size();j++)
        {
            for (int k =j+1;k<arr.size();k++)
            {
                if(arr[i] + arr[j] + arr[k] == sum)
                {
                    vector <int> temp;
                    temp.push_back(min(arr[i],arr[j],arr[k]));
                    temp.push_back(max(arr[i],arr[j],arr[k]));
                    ans.push_back(temp);
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
}