#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int> (n, 1));
    int left = 0, right = n-1, top = 0, down = n-1, index = 1;

    while(left <= right && top <= down)
    {
        // first row
        for (int j=left;j<=right;j++)
        {
            ans[top][j] = index;
            index++;
        }
        top++;
        
        // last column
        for (int i = top;i<=down;i++)
        {
            ans[i][right] = index;
            index++;
        }
        right--;
        
        // last row
        for (int j=right;j>=left;j--)
        {
            ans[down][j] = index;
            index++;
        }
        down--;
        
        //first column
        for (int i=down;i>=top;i--)
        {
            ans[i][left] = index;
            index++;
        }
        left++;
    }
    return ans;
}

int main()
{
    int n = 3;
    vector<vector<int>> ans = spiralMatrix(n);    
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}