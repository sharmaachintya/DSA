#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lis(vector<vector<int>> mat, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
        return 0;
    if (dp[i][j] > 0)
        return dp[i][j];
    int currMax = 1;

    // down
    if (i + 1 < mat.size() && i + 1 >= 0 && mat[i+1][j] > mat[i][j])
    {
        currMax = max(currMax, 1 + lis(mat, i+1, j, dp));
    }

    // right
    if (j + 1 < mat[0].size() && j + 1 >= 0 && mat[i][j+1] > mat[i][j])
    {
        currMax = max(currMax, 1 + lis(mat, i, j+1, dp));
    }

    // up
    if (i - 1 < mat.size() && i - 1 >= 0 && mat[i-1][j] > mat[i][j])
    {
        currMax = max(currMax, 1 + lis(mat, i-1, j, dp));
    }

    // left
    if (j - 1 < mat[0].size() && j - 1 >= 0 && mat[i][j-1] > mat[i][j])
    {
        currMax = max(currMax, 1 + lis(mat, i, j-1, dp));
    }
    
    return dp[i][j] = currMax;
}

int longestIncreasingPath (vector<vector<int>> &mat)
{
    vector<vector<int>> dp(mat.size(), vector<int> (mat[0].size(), -1));
    int maxi = 0;

    for (int i=0;i<mat.size();i++)
    {
        for (int j=0;j<mat[0].size();j++)
        {
            maxi = max(maxi, lis(mat, i, j, dp));
        }
    }
    return maxi;
}


int main()
{
    vector<vector<int>> mat = {{9, 9, 4}, 
                               {6, 6, 8},
                               {2, 1, 1}};
    
    cout<<longestIncreasingPath(mat);
}