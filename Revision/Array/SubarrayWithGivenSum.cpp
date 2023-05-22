#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr, int sum)
{
    int currSum = 0;
    vector<int> ans;
    int n = arr.size();
    for (int i=0;i<n;i++)
    {
        currSum = arr[i];
        for (int j=i+1;j<=n;j++)
        {
            if (currSum == sum)
            {
                ans.push_back(i+1);
                ans.push_back(j);
            }
            if (currSum > sum || j == n)
                break;
            if (currSum == sum)
                break;
            currSum += arr[j];
        }
        if (currSum == sum)
            break;
    }
    if (ans.size() == 0)
        ans.push_back(-1);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 7, 5};
    int sum = 12;
    vector<int> ans = solve(arr, sum);  
    for (auto it : ans)  
        cout<<it<<" ";
}